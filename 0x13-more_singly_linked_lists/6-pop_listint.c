#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list,
 *               and returns the head node’s data (n).
 * @head: Pointer to a pointer to the head node of the linked list.
 *
 * Return: The head node's data (n), or 0 if the linked list is empty.
 */
int pop_listint(listint_t **head)
{
    int n;
    listint_t *temp;

    if (*head == NULL)
        return (0);

    temp = *head;
    n = temp->n;
    *head = temp->next;
    free(temp);

    return (n);
}

