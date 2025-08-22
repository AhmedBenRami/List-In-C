#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *prev;
    int number;
    struct NODE *next;
} node;

node *create_linked_list(int numb_list[], int length);
void print_list(node *head);
void free_list(node *head);
void insert_node(node *head, int number, int position);

int main(void)
{
    int numb_list[] = {10, 20, 9, 0};
    node *head = create_linked_list(numb_list, 4);

    insert_node(head, -8, 0);
    print_list(head);

    free_list(head);

    return 0;
}

node *create_linked_list(int numb_list[], int length)
{
    node *head = malloc(sizeof(node));
    head->prev = NULL;

    node *n = head;
    for (int i = 0; i < length; i++)
    {
        node *temp = n;
        n = (i == 0) ? n : temp->next;

        n->prev = (i == 0) ? NULL : temp;
        n->number = numb_list[i];
        n->next = (i != length - 1) ? malloc(sizeof(node)) : NULL;
    }

    return head;
}

void print_list(node *head)
{
    node *n = head;
    while (n != NULL)
    {
        printf(" <%i> ", n->number);
        n = n->next;
    }
}

void free_list(node *head)
{
    node *next = head;

    while (next != NULL)
    {
        node *temp = next->next;
        free(next);
        next = temp;
    }
}

void insert_node(node *head, int number, int position)
{
    node *n = head;
    for (int i = 0; i < position; i++)
    {
        n = n->next;
    }

    node *new = malloc(sizeof(node));

    new->prev = n;
    new->number = number;
    new->next = n->next;

    n->next = new;
    (new->next)->prev = new;
}