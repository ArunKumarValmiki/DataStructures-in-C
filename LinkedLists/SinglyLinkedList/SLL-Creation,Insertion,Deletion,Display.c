#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void createlist();
void display();
void insert_beg();
void insert_end();
void insert_atpos();
void del_beg();
void del_end();
void del_atpos();


int main()
{
    createlist();
    display();
    insert_beg();
    display();
    insert_end();
    display();
    insert_atpos();
    display();
    del_beg();
    display();
    del_end();
    display();
    del_atpos();
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
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d",&newnode -> data);
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
        printf("Do you want to continue(0,1)?= ");   // 0 to exit , 1 to continue
        scanf("%d",&choice);
    }    
}

void insert_beg()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value to insert:");
    scanf("%d", &newnode -> data);
    newnode -> next = head;
    head = newnode;
    printf("Newlist after inserting at beg: ");
}


void insert_end()
{
    struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    temp = head;
    while(temp -> next != 0)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    printf("Newlist after inserting at end: ");
}


void insert_atpos()
{
    struct node *newnode, *temp;
    int i, pos;
    int count = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data value to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    
    printf("Enter the position: ");
    scanf("%d", &pos);
    
    
    temp = head;
    while(temp != NULL)
    {
        count++;                          // count number of nodes
        temp = temp -> next;
    }


    if(pos < 1 ||  pos > count+1)
    {
        printf("Invalid position");
        printf("\n");
        return;
    
    }
    
    if(pos == 1)
    {
        newnode -> next = head;
        head = newnode;
        return;
    }
    
    temp = head;
    for (i = 1 ; i < pos - 1 ; i++)
    {
        temp = temp->next;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
    printf("Newlist after inserting at specpos: ");
    
}


void del_beg()
{
    struct node *temp;
    temp = head;
    head = head -> next;
    free(temp);
    printf("\n");
    printf("Newlist after deleting at beg: ");
}


void del_end()
{
    struct node *temp,*prev;
    temp = head;
    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
    printf("\n");
    printf("Newlist after deleting at end: ");
}


void del_atpos()
{
    struct node *temp,*nextnode;
    int i = 1;
    int pos;
    temp = head;
    printf("\nEnter the position to delete a node: ");
    scanf("%d",&pos);
    while(i < pos-1)
    {
        temp = temp -> next;
        i++;
    }
    nextnode = temp -> next;
    temp -> next = nextnode -> next;
    free(nextnode);
    printf("Newlist after deleting at specpos: ");
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
        temp = temp -> next;
        count++;
    }
    printf("\n");
    printf("The number of nodes are: %d",count);
    
}






