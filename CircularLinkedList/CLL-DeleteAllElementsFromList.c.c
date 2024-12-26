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
void delete_entire_list();

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
            head -> next = head;
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
    
    if (head == NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        temp = head;
        do 
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
            count++;
        }
        while (temp != head);
        {
            printf("\nThe number of nodes are %d",count);
        }
    }
}

void delete_entire_list()
{
    struct node *temp, *temp1;
    temp1 = head;
    while (temp1 -> next != head)
    {
        temp1 = temp1 -> next;
    }
    
    while(head -> next != head)
    {
        temp = head;
        head = head -> next;
        free(temp);
        temp1 -> next = head;
    }
    free(head);
    head = NULL;
}



int main()
{
    createlist();
    display();
    delete_entire_list();
    display();
}