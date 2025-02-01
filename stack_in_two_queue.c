#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue1[MAX];
int queue2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

int isEmpty(int queueNumber)
{
    if (queueNumber == 1)
    {
        return front1 == -1;
    }
    else if (queueNumber == 2)
    {
        return front2 == -1;
    }
    return 1;
}

void enqueue(int queueNumber,int value)
{
    if (queueNumber == 1)
    {
        if ((rear1 + 1) % MAX == front1)
        {
            printf("Queue 1 is full.\n");
        }
        else
        {
            if (front1 == -1)
            {
                front1 = 0;
            }
            rear1 = (rear1 + 1) % MAX;
            queue1[rear1] = value;
        }
    }
    else if (queueNumber == 2)
    {
        if ((rear2 + 1) % MAX == front2)
        {
            printf("Queue 2 is full.\n");
        }
        else
        {
            if (front2 == -1)
            {
                front2 = 0;
            }
            rear2 = (rear2 + 1) % MAX;
            queue2[rear2] = value;
        }
    }
}

int dequeue(int queueNumber)
{
    int dequeuedValue;
    if (queueNumber == 1)
    {
        if (isEmpty(1))
        {
            printf("Queue 1 is empty.\n");
            return -1;
        }
        else
        {
            dequeuedValue = queue1[front1];
            if (front1 == rear1)
            {
                front1 = rear1 = -1;
            }
            else
            {
                front1 = (front1 + 1) % MAX;
            }
            return dequeuedValue;
        }
    }
    else if (queueNumber == 2)
    {
        if (isEmpty(2))
        {
            printf("Queue 2 is empty.\n");
            return -1;
        }
        else
        {
            dequeuedValue = queue2[front2];
            if (front2 == rear2)
            {
                front2 = rear2 = -1;
            }
            else
            {
                front2 = (front2 + 1) % MAX;
            }
            return dequeuedValue;
        }
    }
    return -1;
}

void push(int value)
{
    enqueue(1,value);
    while (!isEmpty(1))
    {
        int tempValue = dequeue(1);
        enqueue(2,tempValue);
    }
    while (!isEmpty(2))
    {
        int tempValue = dequeue(2);
        enqueue(1,tempValue);
    }
}

int pop()
{
    return dequeue(1);
}

void display()
{
    if (isEmpty(1))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    int index = front1;
    while (index != rear1)
    {
        printf("%d ", queue1[index]);
        index = (index + 1) % MAX;
    }
    printf("%d\n", queue1[rear1]);
}

int main()
{
    printf("Stack operations using two queues\n");
    int choice, value;

    while (1)
    {
        printf("\nEnter operation:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
            {
                printf("Popped: %d\n",value);
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
