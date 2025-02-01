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

void pop()
{
    if(topIndex==-1)
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        topIndex--;
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
        for(int index=topIndex;index>=0;index--)
        {
            printf("%d-",stackArray[index]);
        }
        printf("\n");
    }
}

void size()
{
    int count=0;
    for(int index=topIndex;index>=0;index--)
    {
        count++;
    }
    printf("%d\n",count);
}

int main()
{
    printf("Stack operations\nEnter operations\n");
    int choice;
    printf("1.Push\n2.Pop\n3.Peak\n4.Display\n5.Size\n");

    while(1)
    {
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter element:");
            int element;
            scanf("%d",&element);
            push(element);
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
