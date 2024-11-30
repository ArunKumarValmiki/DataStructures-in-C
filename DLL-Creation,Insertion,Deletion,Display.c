#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

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
    struct node *newnode, *temp;
    int choice = 1;
    int count = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
        }
        printf("Do you want to continue (0,1)? = ");
        scanf("%d", &choice);
    }
}

void insert_beg()
{
    struct node *newnode , *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;
    printf("Newlist after inserting at beg: ");
}

void insert_end()
{
    struct node *newnode , *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    
    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> prev = temp;
    printf("Newlist after inserting at end: ");
}

void insert_atpos()
{
    struct node *newnode , *temp;
    int i,pos;
    int count = 0;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    
    printf("\nEnter position: ");
    scanf("%d",&pos);
    
    temp = head;
    while (temp != NULL)
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
        head -> prev = newnode;
        head = newnode;
        return;
    }

    temp=head;
    for(i=1; i < pos-1 ;i++)
    {
        temp = temp -> next;
    }
    newnode -> prev = temp;
    newnode -> next = temp -> next;
    temp -> next -> prev = newnode;
    temp -> next = newnode;
    printf("Newlist after inserting at spec pos:  ");
    
}    
   
   
void del_beg()
{
    struct node *temp;
    temp = head;
    head = head -> next;
    head -> prev = NULL;
    free(temp);
    printf("\n");
    printf("Newlist after deleting at beg: ");
}    
  
  
void del_end()
{
    struct node *temp,*nextnode;
    temp = head;
    
    while(temp -> next != NULL)
    {
        nextnode = temp;
        temp = temp -> next;
    }
    nextnode -> next = NULL;
    free(temp);
    printf("\n");
    printf("Newlist after deleting at end: ");
}    
    
    
void del_atpos()
{
    struct node *temp;
    
    int i = 1,pos;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    
    temp = head;
    while(i < pos)
    {
        temp = temp -> next;
        i++;
    }
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(temp);
    printf("Newlist after deleting at specpos: ");
}
    
           
void display()
{
    struct node *temp;
    temp = head;
    int count = 0;
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp -> data);
            temp = temp -> next;
            count++;
        }
        printf("\n");
        printf("The number of nodes are %d",count);
    }
}





