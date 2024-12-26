#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createlist();
void display();
void del_end();

int main()
{
    createlist();
    display();
    del_end();
    display();
    
    return 0;
}

void createlist()
{
    struct node *newnode , *temp;
    int choice = 1;
    int count = 0;
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d",&newnode->data);
        newnode -> next = NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue(0,1)?= ");      // 0 to exit , 1 to continue
        scanf("%d",&choice);
    }    
}

void del_end()
{
    struct node *temp,*prev;
    temp = head;
    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
}


void display()
{
    struct node *temp;
    temp = head;
    int count=0;
    if(head == NULL)
    {
        printf("Empty list");
    }
    while(temp != NULL)
    {
        printf("%d ",temp -> data);
        temp = temp->next;
        count++;
    }
    printf("\n");
    printf("The number of nodes are: %d \n",count);
    
}





