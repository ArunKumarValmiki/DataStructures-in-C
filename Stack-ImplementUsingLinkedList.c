# include <stdio.h> 
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = 0; 

void push();
void pop();
void peek();
void display();

int main()
{
    int choice;
    
    do
    {
        printf("Enter Choice: 1.Push, 2.Pop, 3.Peek, 4.display, 0.exit: ");
        scanf("%d",&choice);  
        switch(choice)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            case 0:
            break;
            printf("Invalid Choice\n");
        }
    }
    while(choice != 0);
    
    return 0;
}


void push()
{
    int x;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data value: ");
    scanf("%d",&newnode -> data);
    // newnode -> next = NULL;         

    newnode -> next = top;
    top = newnode;
}


void pop()
{
    struct node *temp; 
    temp = top;
    
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Removed data : %d\n",top -> data);
        top = top -> next;
        free(temp);
    }
}


void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top most element in a stack: %d\n",top -> data);
    }
}

void display()
{
    struct node *temp;
    temp = top;
    
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        while(temp != NULL)
        {
            printf("%d\n",temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}



















