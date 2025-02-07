#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct Node 
{
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashMap 
{
    Node* table[TABLE_SIZE];
} HashMap;

int hash(int key) 
{
    return key % TABLE_SIZE;
}

HashMap* createHashMap() 
{
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int index = 0; index < TABLE_SIZE; index++) 
    {
        map->table[index] = NULL;
    }
    return map;
}

void put(HashMap* map, int key, int value) 
{
    int index = hash(key);
    Node* current = map->table[index];
    while (current != NULL)
    {
        if (current->key == key) 
        {
            current->value = value;
            printf("Key %d updated with value %d.\n", key, value);
            return;
        }
        current = current->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->table[index];
    map->table[index] = newNode;
    printf("Key %d inserted with value %d.\n", key, value);
}

void get(HashMap* map, int key) 
{
    int index = hash(key);
    Node* current = map->table[index];
    while (current != NULL) 
    {
        if (current->key == key) 
        {
            printf("Value: %d\n", current->value);
            return;
        }
        current = current->next;
    }
    printf("Key %d not found.\n", key);
}

void removeKey(HashMap* map, int key)
{
    int index = hash(key);
    Node* current = map->table[index];
    Node* prev = NULL;
    while (current != NULL) 
    {
        if (current->key == key) 
        {
            if (prev == NULL) 
            {
                map->table[index] = current->next; 
            }
            else 
            {
                prev->next = current->next; 
            }
            free(current);
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key %d not found.\n", key);
}

void display(HashMap* map) 
{
    printf("Hash Table:\n");
    for (int index = 0; index < TABLE_SIZE; index++) 
    {
        if (map->table[index] != NULL) 
        {
            printf("Index %d: ",index);
            Node* current = map->table[index];
            while (current != NULL) 
            {
                printf("(%d, %d) ", current->key, current->value);
                current = current->next;
                if (current != NULL) 
                {
                    printf("->");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    HashMap* map = createHashMap();
    int choice, key, value;
    while (1) 
    {
        printf("\nEnter your choice:\n");
        printf("1. Insert (Put)\n");
        printf("2. Search (Get)\n");
        printf("3. Delete (Remove)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                put(map, key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                get(map, key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                removeKey(map, key);
                break;
            case 4:
                display(map);
                break;
            case 5:
                printf("Exiting program\n");
                for (int index = 0; index < TABLE_SIZE; index++) 
                {
                    Node* current = map->table[index];
                    while (current != NULL) 
                    {
                        Node* temp = current;
                        current = current->next;
                        free(temp);
                    }
                }
                free(map);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
