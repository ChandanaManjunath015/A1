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

void reverseList(node** head)
{
    node* prev=NULL;
    node* next=NULL;
    node* cur=*head;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head=prev;
}

int convertToNum(node* head)
{
    int *arr=malloc(sizeof(int*));
    node* temp=head;
    int index=0;
    while(temp!=NULL)
    {
        arr[index++]=temp->data;
        temp=temp->next;
    }
    
    int result=0;
    for(int i=0;i<index;i++)
    {
        result=result*10+arr[i];
    }
    return result;

}

void convertToList(int sum)
{
    int *a=malloc(sizeof(int*));
    for(int i=0;i<3;i++)
    {
        a[i]=sum%10;
        sum=sum/10;
    }
    node* head2=NULL;
    for(int i=0;i<3;i++)
    {
        createNode(&head2,a[i]);
    }
    displayList(head2);
}

int main()
{
    
    node* head1=NULL;
    int value;
    
    while(scanf("%d",&value)==1)
    {
        createNode(&head1,value);
        if(getchar()=='\n')
        {
            break;
        }
    }
    //displayList(head);
    reverseList(&head1);
    //displayList(head1);
    int num1=convertToNum(head1);
    //printf("%d\n",num1);
    //displayList(head1);

    node* head2=NULL;
    int value2;
    while(scanf("%d",&value2)==1)
    {
        createNode(&head2,value2);
        if(getchar()=='\n')
        {
            break;
        }
    }
    //displayList(head);
    reverseList(&head2);
    //displayList(head2);
    int num2=convertToNum(head2);
    //printf("%d\n",num2);
    //displayList(head2);
    int sum=num1+num2;
    convertToList(sum);
}
