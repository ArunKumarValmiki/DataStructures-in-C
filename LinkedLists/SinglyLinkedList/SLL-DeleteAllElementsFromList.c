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
    for (int i = 0; i< n ;i ++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d",&newnode -> data);
        newnode -> next = NULL;
        
        if (head == NULL)
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
    int count = 0;
    
    if (head == NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
            count++;
        }
    }
    printf("\nThe number of nodes are %d",count);
}

void delete_entire_list()
{
    struct node *temp;
    
    while (head != NULL)
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
    head = NULL;
}

int main()
{
    createlist();
    display();
    delete_entire_list();
    display();
}