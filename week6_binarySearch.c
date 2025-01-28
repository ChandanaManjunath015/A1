#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;
    char name[100];
    struct node* next;
};

void insertSorted(struct node** head_ref, int id, const char* name)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* current;
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    if (*head_ref == NULL || (*head_ref)->id >= id)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL && current->next->id < id) 
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

const char* binarySearch(struct node* head, int target_id)
{
    struct node* start = head;
    struct node* end = NULL;
    struct node* mid;
    const char* result = "ID not found";

    while (start != end) 
    {
        mid = start;
        struct node* temp = start;
        int count = 0;

        while (temp != end) 
        {
            temp = temp->next;
            count++;
        }
        count /= 2;
        for (int i = 0; i < count; i++) 
        {
            mid = mid->next;
        }

        if (mid->id == target_id) 
        {
            result = mid->name;
            break;
        } 
        else if (mid->id < target_id) 
        {
            start = mid->next;
        } 
        else 
        {
            end = mid;
        }
    }
    return result;
}

void printList(struct node* node) 
{
    while (node != NULL)
    {
        printf("ID: %d, Name: %s\n", node->id, node->name);
        node = node->next;
    }
}

int main() 
{
    struct node* head = NULL;
    insertSorted(&head, 5, "Alice");
    insertSorted(&head, 3, "Bob");
    insertSorted(&head, 8, "Charlie");
    insertSorted(&head, 1, "David");
    insertSorted(&head, 6, "Eve");
    printf("Sorted List:\n");
    printList(head);
    printf("Enter id to search\n");
    int search_id;
    scanf("%d",&search_id);
    const char* name = binarySearch(head, search_id);
    if (strcmp(name,"ID not found")!=0)
    {
        printf("Found: ID = %d, Name = %s\n", search_id, name);
    }
    else
    {
        printf("\n%s\n", name);
    }

    return 0;
}
