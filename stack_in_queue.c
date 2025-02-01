#include <stdio.h>
#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];
int front_of_queue = -1, rear_of_queue = -1;

int isFull()
{
    if((rear_of_queue + 1) % MAX_QUEUE_SIZE == front_of_queue)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if(front_of_queue == rear_of_queue)
    {
        return 1;
    }
    return 0;
}

void peek()
{
    if(isEmpty())
    {
        printf("Queue is empty. Cannot peek.\n");
    }
    else
    {
        printf("Peek: %d\n",queue[front_of_queue]);
    }
}

void enqueue(int element_to_enqueue)
{
    if(isFull())
    {
        printf("Stack is full. Cannot enqueue %d\n",element_to_enqueue);
        return;
    }
    if(front_of_queue == -1)
    {
        front_of_queue = 0;
    }
    rear_of_queue = (rear_of_queue + 1) % MAX_QUEUE_SIZE;
    queue[rear_of_queue] = element_to_enqueue;
    printf("Enqueued: %d\n",element_to_enqueue);
}

int dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeued_element = queue[front_of_queue];
    if(front_of_queue == rear_of_queue)
    {
        front_of_queue = rear_of_queue = -1;
    }
    else
    {
        front_of_queue = (front_of_queue + 1) % MAX_QUEUE_SIZE;
    }
    return dequeued_element;
}

void push(int element_to_push)
{
    enqueue(element_to_push);
    int temporary_rear_of_queue = rear_of_queue;
    while(front_of_queue != temporary_rear_of_queue)
    {
        int dequeued_element = dequeue();
        enqueue(dequeued_element);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int index = front_of_queue;
    while(index != rear_of_queue)
    {
        printf("%d ",queue[index]);
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n",queue[rear_of_queue]);
}

int main()
{
    printf("Queue operations\nEnter operations\n");
    int operation_choice;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n");

    while(1)
    {
        printf("\nEnter operation (1-4): ");
        scanf("%d",&operation_choice);

        if(operation_choice == 1)
        {
            printf("Enter element to enqueue: ");
            int element_to_enqueue;
            scanf("%d",&element_to_enqueue);
            push(element_to_enqueue);
        }
        else if(operation_choice == 2)
        {
            dequeue();
        }
        else if(operation_choice == 3)
        {
            peek();
        }
        else if(operation_choice == 4)
        {
            display();
        }
        else
        {
            printf("Invalid operation. Exiting...\n");
            break;
        }
    }

    return 0;
}
