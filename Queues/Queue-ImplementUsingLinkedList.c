#include <stdio.h>
#include <stdlib.h>

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
    int x;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data value: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL; 
    
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear -> next = newnode;
        rear = newnode;
    }
}


void dequeue()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        printf("Dequeued element : %d\n",front -> data);
        front = front -> next;
        free(temp);
        if (front == NULL)
        {
            rear = NULL;
        }
    }
}


void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element in a queue: %d\n",front -> data);
    }
}


void display()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("Queue ie empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        temp = front;
        while (temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}







