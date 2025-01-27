#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void swapData(struct Node *node1, struct Node *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void selectionSort(struct Node *head)
{
    struct Node *currentNode = head;
    struct Node *minNode = NULL;
    struct Node *tempNode = NULL;
    while (currentNode != NULL)
    {
        minNode = currentNode;
        tempNode = currentNode->next;
        while (tempNode != NULL)
        {
            if (minNode->data > tempNode->data)
            {
                minNode = tempNode;
            }
            tempNode = tempNode->next;
        }
        if (minNode != currentNode)
        {
            swapData(currentNode, minNode);
        }
        currentNode = currentNode->next;
    }
}

int main()
{
    struct Node *head = createNode(9);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    printf("Original Linked List:");
    printList(head);
    selectionSort(head);
    printf("Sorted Linked List:");
    printList(head);

    return 0;
}
