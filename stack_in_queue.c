#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return (rear + 1) % MAX == front;
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    return dequeuedValue;
}

void push(int value)
{
    int size = (rear - front + MAX) % MAX + 1;
    enqueue(value);
    for (int i = 0; i < size - 1; i++)
    {
        int temp = dequeue();
        enqueue(temp);
    }
}

int pop()
{
    return dequeue();
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    printf("Stack operations using one queue\n");
    int choice, value;

    while (1)
    {
        printf("\nEnter operation:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
            {
                printf("Popped: %d\n", value);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
