# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void createlist();
void display();
void insert_at_beg();

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
        newnode -> prev = NULL;
        
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
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
        while (temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
            count++;
        }
    }
    printf("\nThe number of nodes are %d",count);
}


void insert_at_beg()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    
    if (head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        newnode -> next = head;
        newnode -> next -> prev = newnode;
        head = newnode;
    }
}

int main()
{
    createlist();
    display();
    insert_at_beg();
    display();
}