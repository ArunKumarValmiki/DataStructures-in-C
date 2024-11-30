# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createlist();
void display();
void insert_at_given_pos();

void createlist()
{
    struct node *newnode, *temp;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
        
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
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


void display()
{
    struct node *temp;
    int count = 0;
    
    if(head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        temp = head;
        do {
            printf("%d ",temp -> data);
            temp = temp -> next;
            count++;
        }
        while (temp != head);
        {
            printf("\nThe number of nodes are %d", count);
        }
    }
}


void insert_at_given_pos()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    int i = 1, pos;
    printf("Enter the position to insert the element: ");
    scanf("%d",&pos);
    
    if (head == NULL)
    {
        printf("Empty list");
    }
    
    else if (pos == 1)
    {
        temp = head;
        while (temp -> next != head)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> next = head;
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
        temp -> next = newnode;
    }
}



int main()
{
    createlist();
    display();
    insert_at_given_pos();
    display();
}