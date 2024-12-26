# include <stdio.h> 
# include <stdlib.h> 
# define N 5 

int front = -1;
int rear = -1;
int queue[N];

void enqueue();
void dequeue();
void peek();
void display();


int main()
{
    int choice; 
    
    do {
        printf("Enter Choice : 1.Enqueue, 2.Dequeue, 3.Peek, 4.Display, 0.exit: ");
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
            default: printf("Invalid Choice\n");
        }
    } while(choice != 0);
    
    return 0;
}
   
void enqueue()
{
    int x;
    printf("Enter the data value: ");
    scanf("%d",&x);
    
    if (rear == N - 1)
    {
        printf("Queue is full.\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}


void dequeue()
{
    
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else if (front == rear)
    {
        printf("Removed Element : %d\n",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Removed Element : %d\n",queue[front]);
        front++;
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element in a queue: %d\n",queue[front]);
    }
}


void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        for(int i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
