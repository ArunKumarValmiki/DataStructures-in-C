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
void reverse_SLL();


void createlist()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    struct node *newnode , *temp;
    for (int i = 0 ; i < n ; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
    }    
}

void display()
{
    struct node *temp;
    int count=0;
    temp = head;
    if (head == NULL)
    {
        printf("Empty list");
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        count = count + 1;
    }
    printf("\n");
    printf("The number of nodes are : %d\n",count);
    
}

void reverse_SLL()
{
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    
    while(nextnode != 0)
    {
        nextnode = nextnode -> next;
        currentnode -> next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    
    head = prevnode;
    printf("Linked list after reversing: ");
}


int main()
{
    createlist();
    display();
    reverse_SLL();
    display();
    
    return 0;
}





