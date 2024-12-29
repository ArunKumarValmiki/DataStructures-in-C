#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data value: ");
        scanf("%d", &newnode->data);
        newnode -> next = NULL;
        newnode -> prev = NULL;

        if (head == NULL)
        {
            head = newnode;
            head -> next = head;
            head -> prev = head;
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

void display()
{
    struct node *temp;
    int count = 0;

    if (head == NULL)
    {
        printf("Empty list\n");
        return;
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
    }
    printf("\nThe number of nodes are %d\n", count);
}

void reverse()
{
    if (head == NULL)
    {
        printf("Empty list, nothing to reverse.\n");
        return;
    }

    struct node *current = head, *temp = NULL;

    do
    {
        // Swap next and prev for the current node
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        // Move to the next node (which is the original prev node)
        current = temp;
    } while (current != head);

    // Adjust head to the new first node
    head = head->prev;

    printf("List reversed successfully.\n");
}

int main()
{
    createlist();
    printf("Original List: ");
    display();

    reverse();
    printf("Reversed List: ");
    display();

    return 0;
}
