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
void insert_beginning();
void insert_at_end();
void insertAtGivenPos();
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtGivenPos();

int main()
{
    createlist();
    display();
    insert_beginning();
    display();
    insert_at_end();
    display();
    insertAtGivenPos();
    display();
    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteAtGivenPos();
    display();
}

void createlist()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        struct node *newnode, *temp;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data value for node %d: ",i+1);
        scanf("%d",&newnode -> data);
        newnode -> prev = NULL;
        newnode -> next = NULL; 
        
        if (head == NULL)
        {
            head = newnode;
            newnode -> next = newnode;
            newnode -> prev = newnode;
            temp = head;
        }
        else
        {
            temp -> next = newnode;
            newnode -> prev = temp;
            newnode -> next = head;
            head -> prev = newnode;
            temp = newnode;
        }
    }
}


void insert_beginning()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value: ");
    scanf("%d",&newnode -> data);
    newnode -> prev = NULL;
    newnode -> next = NULL;
    
    if(head == NULL)
    {
        head = newnode;
        newnode -> next = newnode;
        newnode -> prev = newnode;
    }
    else
    {
        temp = head;
        while(temp -> next != head)
        {
            temp = temp -> next;
        }
        newnode -> next = head;
        head -> prev = newnode;
        head = newnode;
        temp -> next = head;
        head -> prev = temp;
    }
}


void insert_at_end()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value: ");
    scanf("%d",&newnode -> data);
    newnode -> prev = NULL;
    newnode -> next = NULL;
    
    if(head == NULL)
    {
        head = newnode;
        newnode -> next = newnode;
        newnode -> prev = newnode;
    }
    else
    {
        temp = head;
        while(temp -> next != head)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
        newnode -> next = head;
        head -> prev = newnode;
    }
}


void insertAtGivenPos()
{
    struct node *newnode, *temp;
    int i = 1, pos;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value: ");
    scanf("%d",&newnode -> data);
    newnode -> prev = NULL;
    newnode -> next = NULL;
    
    printf("Enter the position to insert the element: ");
    scanf("%d",&pos);
    
    if(head == NULL)
    {
        head = newnode;
        newnode -> next = newnode;
        newnode -> prev = newnode;
    }
    else if (pos == 1)
    {
        temp = head -> prev;
        newnode -> next = head;
        newnode -> prev = temp;
        temp -> next = newnode;
        head -> prev = newnode;
        head = newnode; 
    }
    else
    {
        temp = head;
        while (i < pos - 1)
        {
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        newnode -> next -> prev = newnode;
        temp -> next = newnode;
        newnode -> prev = temp;
    }
}


void deleteAtBeginning()
{
    struct node *temp, *temp1;
    temp1 = temp = head;
    
    while (temp -> next != head)
    {
        temp = temp -> next;
    }
    temp1 -> next -> prev = temp;
    head = temp1 -> next;
    temp -> next = head;
    free(temp1);
    printf("\nLinked List after deleting the node at beginning: ");
}


void deleteAtEnd()
{
    struct node *temp;
    temp = head;
    
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    temp -> prev -> next = head;
    head -> prev = temp -> prev;
    free(temp); 
    printf("\nLinked List after deleting the node at end: ");
}


void deleteAtGivenPos()
{
    struct node *temp,*temp1;
    int i = 1, pos;
    printf("\nEnter the position to delete the node: ");
    scanf("%d",&pos);
    
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp -> next;
            i++;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);
        printf("Linked List after deleting the node at position %d: ",pos);
    }    
}


void display()
{
    struct node *temp;
    int count = 0;
    
    if (head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        temp = head;
        do {
            printf("%d ",temp->data);
            temp = temp -> next;
            count++;
        } while (temp != head);
        printf("\nThe number of nodes are %d",count);
    }
}