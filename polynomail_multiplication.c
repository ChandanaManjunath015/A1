#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coefficient,exponent;
    struct Node *next;
} Node;

Node *createNode(int coefficient,int exponent)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->coefficient=coefficient;
    newNode->exponent=exponent;
    newNode->next=NULL;
    return newNode;
}

void insertNode(Node **head,int coefficient,int exponent)
{
    Node *newNode=createNode(coefficient,exponent);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
    Node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

Node *addTerm(Node *head,int coefficient,int exponent)
{
    if(head==NULL)
    {
        return createNode(coefficient,exponent);
    }
    Node *temp=head,*prev=NULL;
    while(temp!=NULL&&temp->exponent>exponent)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp!=NULL&&temp->exponent==exponent)
    {
        temp->coefficient+=coefficient;
    }
    else
    {
        Node *newNode=createNode(coefficient,exponent);
        if(prev==NULL)
        {
            newNode->next=head;
            head=newNode;
        }
        else
        {
            newNode->next=temp;
            prev->next=newNode;
        }
    }
    return head;
}

Node *multiplyPolynomials(Node *poly1,Node *poly2)
{
    Node *result=NULL;
    for(Node *temp1=poly1;temp1!=NULL;temp1=temp1->next)
    {
        for(Node *temp2=poly2;temp2!=NULL;temp2=temp2->next)
        {
            result=addTerm(result,temp1->coefficient*temp2->coefficient,temp1->exponent+temp2->exponent);
        }
    }
    return result;
}

void printPolynomial(Node *head)
{
    while(head!=NULL)
    {
        printf("%dx^%d",head->coefficient,head->exponent);
        head=head->next;
        if(head!=NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void inputPolynomial(Node **poly)
{
    int terms,coefficient,exponent;
    printf("Enter number of terms: ");
    scanf("%d",&terms);
    for(int i=0;i<terms;i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d",&coefficient,&exponent);
        insertNode(poly,coefficient,exponent);
    }
}

int main()
{
    Node *poly1=NULL,*poly2=NULL;
    inputPolynomial(&poly1);
    inputPolynomial(&poly2);
    Node *result=multiplyPolynomials(poly1,poly2);
    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    printf("Resultant Polynomial: ");
    printPolynomial(result);
    return 0;
}
