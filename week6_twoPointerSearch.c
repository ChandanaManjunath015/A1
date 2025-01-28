#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int searchLinkedList(struct Node* headNode, int searchKey) 
{
    struct Node* slowPointer = headNode;
    struct Node* fastPointer = headNode;
    while (fastPointer != NULL)
    {
        if (slowPointer->data == searchKey) 
        {
            return 1;
        }
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;  
        if (fastPointer != NULL && slowPointer->data == searchKey)
        {
            return 1; 
        }
    }

    return 0; 
}

struct Node* createLinkedListFromInput(int numNodes)
{
    struct Node* headNode = NULL;
    struct Node* currentNode = NULL;
    int data;
    for (int i = 0; i < numNodes; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (headNode == NULL)
        {
            headNode = newNode;  
        } 
        else
        {
            currentNode->next = newNode; 
        }
        currentNode = newNode; 
    }
    return headNode;
}

void printLinkedList(struct Node* headNode) 
{
    struct Node* currentNode = headNode;
    while (currentNode != NULL) 
    {
        printf("%d ->", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main() 
{
    int numNodes, searchKey;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &numNodes);
    struct Node* headNode = createLinkedListFromInput(numNodes);
    printf("Linked List: ");
    printLinkedList(headNode);
    printf("Enter the key to search for: ");
    scanf("%d", &searchKey);
    if (searchLinkedList(headNode, searchKey)) {
        printf("Key %d found in the list.\n", searchKey);
    }
    else 
    {
        printf("Key %d not found in the list.\n", searchKey);
    }
    return 0;
}
