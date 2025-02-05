#include<stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* getNode(int value)
{
    struct node* newNode=malloc(sizeof(node*));
    if(!newNode)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void createNode(node** head,int value)
{
    node* newNode=getNode(value);
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        } 
        temp->next=newNode;
    }
}

node* reversenode(node** head,int k)
{
    node* prev=NULL;
    node* next=NULL;
    node* current=*head;
    int count=0;
    while(current!=NULL && count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if (next!=NULL)
    {
        (*head)->next=reversenode(&next,k);
    }
    *head=prev;
}

void displayList(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        printf(" ");
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    node* head=NULL;
    int value;
    while(scanf("%d",&value)==1)
    {
        createNode(&head,value);
        if(getchar()=='\n')
        {
            break;
        }
    }
    displayList(head);
    int k;
    scanf("%d",&k);
    reversenode(&head,k);
    displayList(head);
    return 0;
}
