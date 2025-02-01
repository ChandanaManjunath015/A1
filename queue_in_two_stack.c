#include<stdio.h>
#include<stdlib.h>

#define MAX 25

int stack1[MAX];
int stack2[MAX];
int top1=-1, top2=-1;

void push(int stackNumber, int element)
{
    if(stackNumber==1)
    {
        if(top1==MAX-1)
        {
            printf("Stack 1 overflow\n");
        }
        else
        {
            stack1[++top1]=element;
            printf("Pushed %d to Stack 1\n",element);
        }
    }
    else if(stackNumber==2)
    {
        if(top2==MAX-1)
        {
            printf("Stack 2 overflow\n");
        }
        else
        {
            stack2[++top2]=element;
            printf("Pushed %d to Stack 2\n",element);
        }
    }
    else
    {
        printf("Invalid stack number\n");
    }
}

int pop(int stackNumber)
{
    if(stackNumber==1)
    {
        if(top1==-1)
        {
            printf("Stack 1 underflow\n");
            return -1;
        }
        else
        {
            return stack1[top1--];
        }
    }
    else if(stackNumber==2)
    {
        if(top2==-1)
        {
            printf("Stack 2 underflow\n");
            return -1;
        }
        else
        {
            return stack2[top2--];
        }
    }
    else
    {
        printf("Invalid stack number\n");
    }
}

void peek(int stackNumber)
{
    if(stackNumber==1)
    {
        if(top1==-1)
        {
            printf("Stack 1 is empty\n");
        }
        else
        {
            printf("Top of Stack 1: %d\n",stack1[top1]);
        }
    }
    else if(stackNumber==2)
    {
        if(top2==-1)
        {
            printf("Stack 2 is empty\n");
        }
        else
        {
            printf("Top of Stack 2: %d\n",stack2[top2]);
        }
    }
    else
    {
        printf("Invalid stack number\n");
    }
}

void display()
{
    if(top1==-1)
    {
        printf("Stack 1 is empty\n");
    }
    else
    {
        printf("Stack 1: ");
        for(int index=top1; index>=0; index--)
        {
            printf("%d ",stack1[index]);
        }
        printf("\n");
    }
}

void enqueue(int element)
{
    if(top1==MAX-1)
    {
        printf("Stack 1 overflow\n");
    }
    else if(top1==-1)
    {
        stack1[++top1]=element;
        printf("Pushed %d to Stack 1\n",element);
    }
    else
    {
        while(top1!=-1)
        {
            int value=pop(1);
            push(2,value);
        }
        push(1,element);
        while(top2!=-1)
        {
            int value=pop(2);
            push(1,value);
        }
    }
}

void size()
{
    int count=0;
    for(int index=top1; index>=0; index--)
    {
        count++;
    }
    printf("%d\n",count);
}

int main()
{
    printf("Queue working on stack operations\nEnter operations:\n");
    int choice, element;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Size\n");

    while(1)
    {
        printf("\nEnter operation (1-5): ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter element to push: ");
            scanf("%d",&element);
            enqueue(element);
        }
        else if(choice==2)
        {
            pop(1);
        }
        else if(choice==3)
        {
            peek(1);
        }
        else if(choice==4)
        {
            display();
        }
        else if(choice==5)
        {
            size();
        }
        else
        {
            printf("Invalid operation. Exiting...\n");
            break;
        }
    }

    return 0;
}
