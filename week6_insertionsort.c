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

void swap(struct node *node1,struct node* node2)
{
    struct node* temp=node1;
    *node1=*node2;
    *node2=*temp;
}

void insertionSort(struct node** head) 
{
    struct node* sorted= NULL;
    struct node* current=*head;
    while (current!=NULL) 
    {
        struct node* next_node=current->next;
        if (sorted==NULL|| sorted->data>= current->data)
        {
            current->next=sorted;
            sorted=current;
        } 
        else 
        {
            struct node* temp = sorted;
        while (temp->next != NULL && temp->next->data < current->data) 
           {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next_node;
    }
    *head=sorted;
}

void printList(struct node* head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NUll\n");
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
    insertionSort(&head);
    printList(head);
    return 0;
}
