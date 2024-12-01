#include<stdio.h>

#define N 5
int deque[N];
int front = -1;
int rear = -1;

void insertfront();
void insertrear();
void deletefront();
void deleterear();
void display();

int main()
{
    int choice;
    
    do
    {
        printf("Enter Choice: 1: insertfront, 2: insertrear, 3: deletefront, 4: deleterear, 5: display, 0: exit: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertfront();
            break;
            case 2: insertrear();
            break;
            case 3: deletefront();
            break;
            case 4: deleterear();
            break;
            case 5: display();
            break;
            case 0:
            break;
            default : printf("Invalid Choice\n");
        }
    }
    while(choice != 0);
    

    return 0;
}


void insertfront()
{
    int x;
    printf("Enter the data: ");
    scanf("%d",&x);
    if((front == 0 && rear == N-1)  || (front == rear+1))
    {
        printf("Deque is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if(front == 0)
    {
        front = N-1;
        deque[front] = x;
    }
    else
    {
        front--;
        deque[front] = x;
    }
}


void insertrear()
{
    int x;
    printf("Enter the data: ");
    scanf("%d",&x);
    if((front == 0 && rear == N-1) || (front == rear+1))
    {
        printf("Deque is full\n");
    }
    else if(front ==-1 && rear ==-1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else if(rear == N-1)
    {
        rear = 0;
        deque[rear] = x;
    }
    else
    {
        rear++;
        deque[rear] = x;
    }
}


void deletefront()
{
    if(front == -1 && rear == -1)
    {
        printf("Deque is empty\n");
    }
    else if(front == rear)
    {
        printf("Dequeued element is %d\n",deque[front]);
        front = rear = -1;
    }
    else if(front == N-1)
    {
        printf("Dequeued element is %d\n",deque[front]);
        front = 0;
    }
    else
    {
        printf("Dequeued element is %d\n",deque[front]);
        front++;
    }
}

void deleterear()
{
    if(front == -1 && rear == -1)
    {
        printf("Deque is empty\n");
    }
    else if(front == rear)
    {
        printf("Dequeued element is %d\n",deque[rear]);
        front = rear = -1;
    }
    else if(rear == 0)
    {
        printf("Dequeued element is %d\n",deque[rear]);
        rear = N-1;
    }
    else
    {
        printf("Dequeued element is %d\n",deque[rear]);
        rear--;
    }
}

void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deque elements are: \n");
        while(i != rear)
        {
            printf("%d ",deque[i]);
            i = (i+1) % N;
        }
        printf("%d ",deque[rear]);
        printf("\n");
    }
}










