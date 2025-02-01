#include <stdio.h>
#define MAX 5  
int queue[MAX];
int frontIndex = -1, rearIndex = -1;

int isFull() 
{
    if (rearIndex == MAX - 1) 
    {
        return 1;
    }
    return 0;
}

int isEmpty() 
{
    if (frontIndex == -1 || frontIndex > rearIndex) 
    {
        return 1;
    }
    return 0;
}

void peek() 
{
    printf("%d\n", queue[frontIndex]);
}

void enqueue(int element) 
{
    if (isFull()) 
    {
        printf("Queue is full. Cannot enqueue %d\n", element);
        return;
    }
    if (frontIndex == -1) 
    {
        frontIndex = 0;
    }
    rearIndex++;
    queue[rearIndex] = element;
    printf("Enqueued: %d\n", element);
}

int dequeue() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = queue[frontIndex];
    frontIndex++;
    printf("%d", dequeuedValue);
}

void display() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int index = frontIndex; index <= rearIndex; index++) 
    {
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main() 
{
    printf("Queue operations\nEnter operations\n");
    int operationChoice;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n");

    while (1) 
    {
        scanf("%d", &operationChoice);

        if (operationChoice == 1) 
        {
            printf("Enter element: ");
            int element;
            scanf("%d", &element);
            enqueue(element);
        } 
        else if (operationChoice == 2) 
        {
            dequeue();
        } 
        else if (operationChoice == 3) 
        {
            peek();
        } 
        else if (operationChoice == 4) 
        {
            display();
        } 
        else 
        {
            printf("Enter valid operation\n");
            break;
        }
    }
}
