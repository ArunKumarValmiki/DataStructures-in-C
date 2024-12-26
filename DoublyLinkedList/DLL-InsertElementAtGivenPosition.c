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


void insert_at_given_pos()
{
    struct node *newnode, *temp;
    int i = 1, pos;
    printf("\nEnter the position to insert the element: ");
    scanf("%d",&pos);
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data value: ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    
    if (head == NULL)
    {
        printf("Empty list");
    }
    else if (pos == 1)
    {
        newnode -> next = head;
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
        newnode -> prev = temp;
        temp -> next = newnode;
        newnode -> next -> prev = newnode;
    }
    
    
}



int main()
{
    createlist();
    display();
    insert_at_given_pos();
    display();
}