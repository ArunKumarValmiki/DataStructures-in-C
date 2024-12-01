#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;


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
            case 2: dequeue ();
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
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    
    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
        rear -> next = newnode;
    }
    else
    {
        rear -> next = newnode;
        rear = newnode;
        rear -> next = front;
    }
} 


void dequeue()
{
    struct node *temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else if(front == rear)
    {
        front = rear = 0;
        free(temp);
    }
    else
    {
        printf("Dequeued element is %d\n",front -> data);
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
}


void peek()
{
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Peek element is %d\n",front -> data);
    }
}


void display()
{
    struct node *temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: \n");
        while(temp -> next != front)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("%d ",temp -> data);
        printf("\n");
    }
}    





