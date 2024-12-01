# include <stdio.h> 
# include <stdlib.h> 
# define N 5 

int top = -1;
int stack[N];   

void push();
void pop();
void peek();
void display();


int main()
{
    int choice;
    
    do {
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
            default: printf("Invalid choice");
            break;
        }
    }
    while(choice != 0);
    
    return 0;
}


void push()
{
    int x;
    printf("Enter the data value: ");
    scanf("%d",&x);
    if(top == N - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
    
}


void pop()
{
    int removedItem;
    
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        removedItem = stack[top];
        top--;
        printf("Removed Item : %d\n",removedItem);
    }
}


void peek()
{
    int topElement; 
    
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        topElement = stack[top];
        printf("Top most element in stack : %d\n",topElement);
    }
}


void display()
{
    if (top == N-1)
    {
        printf("Stack is empty\n");
    }
    
    printf("Stack elements are:\n");
    for(int i = top; i >= 0; i--)
    {
        printf("%d\n",stack[i]);
    }
    printf("\n");
}