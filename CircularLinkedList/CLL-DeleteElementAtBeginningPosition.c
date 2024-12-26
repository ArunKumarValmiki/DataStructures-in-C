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
void del_at_beg();

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
    printf("\n");
}


void del_at_beg()
{
    struct node *temp, *temp1;
    
    temp = head;
    temp1 = head;
    
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    head = head -> next;
    temp -> next = head;
    free(temp1);
}

int main()
{
    createlist();
    display();
    del_at_beg();
    display();
}