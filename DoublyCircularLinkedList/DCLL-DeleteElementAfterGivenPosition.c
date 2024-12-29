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
void deleteAfterGivenPos();

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

void deleteAfterGivenPos()
{
    struct node *temp,*temp1;
    int i = 1, pos;
    printf("Enter the position to delete the node: ");
    scanf("%d",&pos);
    
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        temp = head;
        while (i <= pos)
        {
            temp = temp -> next;
            i++;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);
        printf("Linked List after deleting the node at position %d: ",pos);
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
        printf("\nThe number of nodes are %d\n",count);
    }
}

int main()
{
    createlist();
    display();
    deleteAfterGivenPos();
    display();
}