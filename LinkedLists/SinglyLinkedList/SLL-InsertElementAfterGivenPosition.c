#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createlist();
void display();
void insert_afterpos();

int main()
{
    createlist();
    display();
    insert_afterpos();
    display();

    return 0;
}

void createlist()
{
    struct node *newnode, *temp;
    int choice = 1;
    int count = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d", &newnode->data);
        newnode -> next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue(0,1)?=");
        scanf("%d", &choice);
    }
}


void insert_afterpos()
{
    struct node *newnode, *temp;
    int pos,i;
    int count = 0;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data value to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;

    printf("Enter the position: ");
    scanf("%d", &pos);

    temp = head;
    while (temp != NULL)
    {
        count++;                   // count number of nodes
        temp = temp -> next;
    }

    if (pos < 1 || pos > count+1)
    {
        printf("Invalid position");
        printf("\n");
        return;
    }

    temp = head;
    for (i = 1; i < pos; i++)
    {
        temp = temp -> next;
    }
    
    newnode -> next = temp -> next;
    temp -> next = newnode;
}



void display()
{
    struct node *temp;
    temp = head;
    int count=0;
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
        count++;
    }
    printf("\n");
}











