#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createlist();
void display();
void insert_end();

int main()
{
    createlist();
    display();
    insert_end();
    display();
    
    return 0;
}

void createlist()
{
    struct node *newnode , *temp;
    int choice = 1;
    int count = 0;
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d",&newnode->data);
        newnode -> next = NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue(0,1)?=");
        scanf("%d",&choice);
    }    
}


void insert_end()
{
    struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value to insert: ");
    scanf("%d", &newnode->data);
    newnode -> next = NULL;
    temp = head;
    while(temp -> next != 0)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    printf("Newnode is: ");
}


void display()
{
    struct node *temp;
    temp = head;
    int count = 0;
    if(head == NULL)
    {
        printf("Empty list");
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    printf("\n");
    printf("The number of nodes are : %d",count);
}



