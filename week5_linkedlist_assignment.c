#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
}Node;
Node* head = NULL; 

Node* createNode(int value) 
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(!newNode) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertAtBeginning(int value) 
{
    Node* newNode = createNode(value);
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(int value) 
{
    Node* newNode = createNode(value);
    Node* temp = head;
    if(head) 
    {
        while(temp->next) 
        {
            temp=temp->next;
        }
        temp->next=newNode;
    } 
    else 
    {
        head=newNode;
    }
}

void insertAtPosition(int position,int value) 
{
    Node* newNode = createNode(value);
    Node* temp = head;
    if(position < 1) 
    {
        printf("Invalid position\n");
    } 
    else if(position == 1) 
    {
        newNode->next=head;
        head=newNode;
    } 
    else 
    {
        for(int i=1;i<position-1 && temp; i++) 
        {
            temp = temp->next;
        }

        if(temp) 
        {
            newNode->next=temp->next;
            temp->next=newNode;
        } 
        else 
        {
            printf("Invalid position\n");
        }
    }
}

void display()
{
    Node* temp=head;
    if(temp) 
    {
        while(temp) 
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}

void updateAtPosition(int position,int newValue) 
{
    Node* temp = head;
    if(position<1) 
    {
        printf("Invalid position\n");
    }
    else 
    {
        for(int i=1;i<position && temp; i++) 
        {
            temp=temp->next;
        }

        if(temp) 
        {
            temp->data=newValue;
        } 
        else 
        {
            printf("Invalid position\n");
        }
    }
}

void deleteAtBeginning() 
{
    if(head) 
    {
        Node* temp = head;
        head=head->next;
        free(temp);
    }
    else
    {
        printf("Invalid position\n");
    }
}

void deleteAtEnd() 
{
    Node* temp = head;
    if(head) 
    {
        if(!head->next) 
        {
            free(head);
            head=NULL;
        }
        else 
        {
            while(temp->next->next) 
            {
                temp=temp->next;
            }
            free(temp->next);
            temp->next=NULL;
        }
    } 
    else 
    {
        printf("Invalid position\n");
    }
}

void deleteAtPosition(int position)
{
    Node* temp = head;
    if(position < 1 || !head)
    {
        printf("Invalid position\n");
    } 
    else if(position==1) 
    {
        Node* toDelete = head;
        head=head->next;
        free(toDelete);
    } 
    else 
    {
        for(int i=1;i<position-1 && temp; i++) 
        {
            temp=temp->next;
        }
        if(temp && temp->next) 
        {
            Node* toDelete = temp->next;
            temp->next=toDelete->next;
            free(toDelete);
        }
        else 
        {
            printf("Invalid position\n");
        }
    }
}

int main() 
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        int operation, value, position, newValue;
        scanf("%d",&operation);
        switch(operation) 
        {
            case 1:
                scanf("%d",&value);
                insertAtEnd(value);
                break;
            case 2:
                scanf("%d",&value);
                insertAtBeginning(value);
                break;
            case 3:
                scanf("%d %d",&position,&value);
                insertAtPosition(position,value);
                break;
            case 4:
                display();
                break;
            case 5:
                scanf("%d %d",&position,&newValue);
                updateAtPosition(position,newValue);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                scanf("%d",&position);
                deleteAtPosition(position);
                break;
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}
