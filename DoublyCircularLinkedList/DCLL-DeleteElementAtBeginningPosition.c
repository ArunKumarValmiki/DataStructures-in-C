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
void deleteAtBeginning();

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


void deleteAtBeginning()
{
    struct node *temp, *temp1;
    temp1 = temp = head;
    
    while (temp -> next != head)
    {
        temp = temp -> next;
    }
    temp1 -> next -> prev = temp;
    head = temp1 -> next;
    temp -> next = head;
    free(temp1);
    printf("Linked List after deleting the node at beginning: ");
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
    deleteAtBeginning();
    display();
}