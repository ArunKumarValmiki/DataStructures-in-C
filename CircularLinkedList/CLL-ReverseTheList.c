#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createlist();
void display();
void reverse();

void createlist() 
{
    struct node *newnode, *temp;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d", &newnode -> data);
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
        printf("Empty list\n");
    } 
    else 
    {
        temp = head;
        do 
        {
            printf("%d ", temp -> data);
            temp = temp -> next;
            count++;
        } while (temp != head);
        printf("\nThe number of nodes are %d\n", count);
    }
}

void reverse() {
    if (head == NULL || head->next == head) 
    {
        return;
    }

    struct node *prev = NULL, *current = head, *next = NULL, *last = head;

    do 
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    } while (current != head);
    

    last -> next = prev;
    head = prev;
}

int main() {
    createlist();
    printf("Original List:\n");
    display();

    reverse();
    printf("\nReversed List:\n");
    display();

    return 0;
}
