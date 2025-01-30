#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;


Node* createNode(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) 
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int value) 
{
    Node* newNode = createNode(value);
    if (newNode) 
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int value) 
{
    Node* newNode = createNode(value);
    if (!newNode) return;

    Node* currentNode = *head;
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        while (currentNode->next) 
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void insertAtPosition(Node** head, int position, int value) 
{
    Node* newNode = createNode(value);
    if (!newNode) return;

    if (position < 1) 
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) 
    {
        newNode->next = *head;
        *head = newNode;
    } 
    else 
    {
        Node* currentNode = *head;
        for (int index = 1; index < position - 1 && currentNode; index++) 
        {
            currentNode = currentNode->next;
        }

        if (currentNode) 
        {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        } 
        else 
        {
            printf("Invalid position\n");
        }
    }
}

void display(Node* head)
{
    Node* currentNode = head;
    if (currentNode) 
    {
        while (currentNode) 
        {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
    }
    printf("\n");
}

void updateAtPosition(Node* head, int position, int newValue) 
{
    Node* currentNode = head;
    if (position < 1) 
    {
        printf("Invalid position\n");
        return;
    }

    for (int index = 1; index < position && currentNode; index++) 
    {
        currentNode = currentNode->next;
    }

    if (currentNode) 
    {
        currentNode->data = newValue;
    } 
    else 
    {
        printf("Invalid position\n");
    }
}

void deleteAtBeginning(Node** head) 
{
    if (*head) 
    {
        Node* nodeToDelete = *head;
        *head = (*head)->next;
        free(nodeToDelete);
    }
    else
    {
        printf("Invalid position\n");
    }
}

void deleteAtEnd(Node** head) 
{
    if (*head) 
    {
        Node* currentNode = *head;
        if (!currentNode->next) 
        {
            free(currentNode);
            *head = NULL;
        } 
        else 
        {
            while (currentNode->next->next) 
            {
                currentNode = currentNode->next;
            }
            free(currentNode->next);
            currentNode->next = NULL;
        }
    } 
    else 
    {
        printf("Invalid position\n");
    }
}

void deleteAtPosition(Node** head, int position)
{
    if (position < 1 || !*head)
    {
        printf("Invalid position\n");
        return;
    } 

    if (position == 1) 
    {
        Node* nodeToDelete = *head;
        *head = (*head)->next;
        free(nodeToDelete);
    } 
    else 
    {
        Node* currentNode = *head;
        for (int i = 1; i < position - 1 && currentNode; i++) 
        {
            currentNode = currentNode->next;
        }

        if (currentNode && currentNode->next) 
        {
            Node* nodeToDelete = currentNode->next;
            currentNode->next = nodeToDelete->next;
            free(nodeToDelete);
        }
        else 
        {
            printf("Invalid position\n");
        }
    }
}

int main() 
{
    int numberOfOperations;
     printf("Enter the number of operation(positive integer value):");
    scanf("%d", &numberOfOperations);
    Node* head = NULL;
    for (int index = 0;index< numberOfOperations;index++) 
    {
        int operation, value, position, newValue;
        printf("Enter the operation(positive integer value)");
        scanf("%d", &operation);
        switch (operation) 
        {
            case 1:
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 3:
                scanf("%d %d", &position, &value);
                insertAtPosition(&head, position, value);
                break;
            case 4:
                display(head);
                break;
            case 5:
                scanf("%d %d", &position, &newValue);
                updateAtPosition(head, position, newValue);
                break;
            case 6:
                deleteAtBeginning(&head);
                break;
            case 7:
                deleteAtEnd(&head);
                break;
            case 8:
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}
