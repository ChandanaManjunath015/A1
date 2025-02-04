#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct queue{
    int arr[MAX];
    int front;
    int rear;

}queue;

void initQueue(queue* q)
{
    q->front=-1;
    q->rear=-1;
}

void enqueue(queue* q,int value)
{
    if(q->rear==MAX-1)
    {
        printf("Queue full\n");
    }
    if(q->front==-1)
    {
        q->front=0;
    }
    q->rear++;
    q->arr[q->rear]=value;
}

void deQueue(queue* q)
{
    if(q->front==-1)
    {
        printf("Queue empty\n");
        return;
    }
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
}

int main()
{
    queue q;
    initQueue(&q);
    enQueue(&q,10);
    enQueue(&q,20);
    deQueue(&q);

}
