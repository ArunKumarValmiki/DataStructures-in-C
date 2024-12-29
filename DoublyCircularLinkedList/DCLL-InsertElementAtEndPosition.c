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
void insert_at_end();

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

int main()
{
    createlist();
    display();
    insert_at_end();
    display();
}