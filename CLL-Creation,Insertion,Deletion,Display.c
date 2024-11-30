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
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        struct node *newnode , *temp;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
    
        if(head == NULL)
        {
            head = temp = newnode;
            temp -> next = head; 
        }  
        else
        {
            temp -> next = newnode;
            temp = newnode;
            temp -> next = head;
        }
    }
    
}

void insert_beg()
{
    struct node *newnode , *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value to insert: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    
    temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = head;
    head = newnode;
    printf("\nNewlist after inserting at beg: ");
}    


void insert_end()
{
    struct node *newnode , *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value to insert: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    
    temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = head;
    printf("\nNewlist after inserting at end: ");
}    


void insert_atpos()
{
    struct node *newnode, *temp;
    int i = 1;
    int pos;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data to insert: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    printf("\nEnter position to insert: ");
    scanf("%d",&pos);
    
    temp = head;
    while(i < pos-1)
    {
        temp = temp -> next;
        i++;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
    printf("\nNewlist after inserting at spec pos: ");
    
}


void del_beg()
{
    struct node *temp,*prev;
    temp = head;
    prev = head;
    
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> next = prev -> next;
    head = prev -> next;
    free(prev);
    printf("\nNewlist after deleting at beg: ");
}

void del_end()
{
    struct node *temp,*prev;
    temp = head;
    prev = head;
    
    while(temp -> next != head)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = head;
    free(temp);
    printf("\nNewlist after deleting at end: ");
}

void del_atpos()
{
    struct node *temp, *prev;
    int i = 1;
    int pos;
    printf("\nEnter the position:");
    scanf("%d",&pos);
    
    temp = head;
    prev = head;
    while(i < pos)
    {
        prev = temp;
        temp = temp -> next;
        i++;
    }
    prev -> next = temp -> next;
    free(temp);
    printf("Newlist after deleting at spec pos: ");
    
}

void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        temp = head;
        while(temp -> next != head)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("%d ",temp -> data);
    }
}

