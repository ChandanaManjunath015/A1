#include<stdio.h>
#include<stdlib.h>

struct StackNode
{
    int data;
    struct StackNode*next;
};

struct StackNode*top=NULL;

int isEmpty()
{
    return top==NULL;
}

void push(int value)
{
    struct StackNode*newStackNode=(struct StackNode*)malloc(sizeof(struct StackNode));
    newStackNode->data=value;
    newStackNode->next=top;
    top=newStackNode;
}

void pop()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct StackNode*temporaryStackNode=top;
        printf("Popped element:%d\n",top->data);
        top=top->next;
        free(temporaryStackNode);
    }
}

void peek()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element:%d\n",top->data);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct StackNode*temporaryStackNode=top;
        while(temporaryStackNode!=NULL)
        {
            printf("%d ",temporaryStackNode->data);
            temporaryStackNode=temporaryStackNode->next;
        }
        printf("\n");
    }
}

void size()
{
    int count=0;
    struct StackNode*temporaryStack=NULL;

    while(!isEmpty())
    {
        struct StackNode*temporaryStackNode=top;
        top=top->next;
        temporaryStackNode->next=temporaryStack;
        temporaryStack=temporaryStackNode;
        count++;
    }

    while(temporaryStack!=NULL)
    {
        struct StackNode*temporaryStackNode=temporaryStack;
        temporaryStack=temporaryStack->next;
        temporaryStackNode->next=top;
        top=temporaryStackNode;
    }

    printf("Size:%d\n",count);
}

int main()
{
    int choice;
    int value;

    while(1)
    {
        printf("Enter operation:1 for push,2 for pop,3 for peek,4 for display,5 for size,0 to exit:");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter value to push:");
            scanf("%d",&value);
            push(value);
        }
        else if(choice==2)
        {
            pop();
        }
        else if(choice==3)
        {
            peek();
        }
        else if(choice==4)
        {
            display();
        }
        else if(choice==5)
        {
            size();
        }
        else if(choice==0)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
