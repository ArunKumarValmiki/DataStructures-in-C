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
    printf("The number of nodes are : %d",count);
    
}


int main()
{
    createlist();
    display();
    
    return 0;
}





