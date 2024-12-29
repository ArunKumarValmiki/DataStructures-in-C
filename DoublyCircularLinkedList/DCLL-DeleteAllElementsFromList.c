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
void delete_all();

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
        scanf("%d", &newnode -> data);
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

void delete_all()
{
    if (head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }

    struct node *current = head, *next_node;

    do
    {
        next_node = current->next;
        free(current);
        current = next_node;
    } while (current != head);

    head = NULL;                 // Reset head to indicate the list is empty

    printf("All nodes have been deleted successfully.\n");
}

int main()
{
    createlist();
    printf("Original List: ");
    display();

    delete_all();
    printf("List after deletion: ");
    display();

    return 0;
}
