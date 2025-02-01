#include<stdio.h>
#include<stdlib.h>

int stackArray[25];
int topIndex=-1;

void push(int element)
{
    if(topIndex==24)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        topIndex++;
        stackArray[topIndex]=element;
    }
}

int pop()
{
    if(topIndex==-1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        int current=stackArray[topIndex];
        topIndex--;
        return current;
    }
}

void peak()
{
    if(topIndex==-1)
    {
        printf("No elements\n");
    }
    else
    {
        printf("%d\n",stackArray[topIndex]);
    }
}

void display()
{
    if(topIndex==-1)
    {
        printf("No elements\n");
    }
    else
    {
        for(int index=topIndex; index>=0; index--)
        {
            printf("%d-",stackArray[index]);
        }
        printf("\n");
    }
}

void insert(int element)
{
    if(topIndex==-1)
    {
        push(element);
        return;
    }

    int current=pop();
    insert(element);
    push(current);
}

void enqueue(int element)
{
    if(topIndex==24)
    {
        printf("Queue full overflow\n");
        exit(1);
    }
    else if(topIndex==-1)
    {
        topIndex++;
        stackArray[topIndex]=element;
        return;
    }
    else
    {
        insert(element);
    }
}

void size()
{
    int count=0;
    for(int index=topIndex; index>=0; index--)
    {
        count++;
    }
    printf("%d\n",count);
}

int main()
{
    printf("Queue using 1 stack operations\nEnter operations\n");
    int choice;
    printf("1.Enqueue\n2.Dequeue\n3.Peak\n4.Display\n5.Size\n");

    while(1)
    {
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter element:");
            int element;
            scanf("%d",&element);
            enqueue(element);
        }
        else if(choice==2)
        {
            pop();
        }
        else if(choice==3)
        {
            peak();
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
            printf("Enter valid operation\n");
            break;
        }
    }
}
