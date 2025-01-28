#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data)
{
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertNode(struct node** head,int data)
{
    struct node* newNode=createNode(data);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
    struct node* temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

int searchKey(struct node *head,int key)
{
    struct node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
       if(temp->data==key)
       {
           count++;
       }
       temp=temp->next;
    }
    if(count>0)
       {
           printf("Element found \n");
           printf("The count is:%d",count);
           return 1;
       }
    printf("Element not found\n");
    return 0;
}

int main() 
{
    int key,num,data;
    printf("Enter the number of elements:");
    scanf("%d",&num);
    struct node* head=NULL;
    for( int i=0;i<num;i++)
    {
        scanf("%d",&data);
        insertNode(&head,data);
    }
    printf("Enter key\n");
    scanf("%d",&key);
    searchKey(head,key);
    return 0;
}
