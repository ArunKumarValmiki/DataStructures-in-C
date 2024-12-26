#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void peek();
void display();

int main()
{
    int choice;
    do
    {
        printf("Enter Choice: 1: enqueue, 2: dequeue, 3: peek, 4: display, 0: exit: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            case 0:
            break;
            default : printf("Invalid Choice\n");
        }
    }
    while(choice != 0);
    
    return 0;
}

void enqueue()
{
    int x;
    printf("Enter the data value: ");
    scanf("%d",&x);
    
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if (((rear + 1) % N) == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Dequeued element : %d\n",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued element : %d\n",queue[front]);
        front = (front + 1) % N;
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Peek element : %d\n",queue[front]);
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (i != rear)
        {
            printf("%d ",queue[i]);
            i = (i+1) % N;
        }
        printf("%d",queue[rear]);
        printf("\n");
    }
}
