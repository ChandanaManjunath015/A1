#include<stdio.h>
#include<stdlib.h>

struct QueueNode
{
    int data;
    struct QueueNode*next;
};

struct QueueNode*front=NULL;
struct QueueNode*rear=NULL;

int isEmpty()
{
    return front==NULL;
}

void enqueue(int element)
{
    struct QueueNode*temporaryQueueNode=(struct QueueNode*)malloc(sizeof(struct QueueNode));
    temporaryQueueNode->next=NULL;
    temporaryQueueNode->data=element;
    if(isEmpty())
    {
        front=temporaryQueueNode;
        rear=temporaryQueueNode;
    }
    else
    {
        rear->next=temporaryQueueNode;
        rear=temporaryQueueNode;
    }
}

void dequeue()
{
    if(isEmpty())
    {
        printf("No element to remove");
        return;
    }
    printf("Dequeue element:%d\n",front->data);
    struct QueueNode*temporaryQueueNode=front;
    front=front->next;
    free(temporaryQueueNode);
}

void peek()
{
    if(isEmpty())
    {
        printf("No element to peek");
        return;
    }
    else
    {
        printf("%d",front->data);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("No element to display");
        return;
    }
    else
    {
        struct QueueNode*temporaryQueueNode=front;
        while(temporaryQueueNode!=rear->next)
        {
            printf("%d--",temporaryQueueNode->data);
            temporaryQueueNode=temporaryQueueNode->next;
        }
        printf("\n");
    }
}

void size()
{
    struct QueueNode*temporaryQueueNode=front;
    int count=0;
    while(temporaryQueueNode!=rear->next)
    {
        count++;
        temporaryQueueNode=temporaryQueueNode->next;
    }
    printf("%d",count);
}

int main()
{
    printf("Queue operations\nEnter operations\n");
    int choice;
    printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Size\n");

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
            dequeue();
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
        else
        {
            printf("Enter valid operation");
            break;
        }
    }
}
