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

Node *addPolynomials(Node *poly1,Node *poly2)
{
    Node *result=NULL;
    while(poly1!=NULL||poly2!=NULL)
    {
        int coefficient=0,exponent=0;
        if(poly1!=NULL&&poly2!=NULL&&poly1->exponent==poly2->exponent)
        {
            coefficient=poly1->coefficient+poly2->coefficient;
            exponent=poly1->exponent;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly2==NULL||(poly1!=NULL&&poly1->exponent>poly2->exponent))
        {
            coefficient=poly1->coefficient;
            exponent=poly1->exponent;
            poly1=poly1->next;
        }
        else
        {
            coefficient=poly2->coefficient;
            exponent=poly2->exponent;
            poly2=poly2->next;
        }
        insertNode(&result,coefficient,exponent);
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
    printf("Enter first polynomial:\n");
    inputPolynomial(&poly1);
    printf("Enter second polynomial:\n");
    inputPolynomial(&poly2);
    Node *result=addPolynomials(poly1,poly2);
    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    printf("Resultant Polynomial: ");
    printPolynomial(result);
    return 0;
}
