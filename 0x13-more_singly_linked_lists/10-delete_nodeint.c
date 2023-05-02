#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index
 * of a listint_t linked list
 * @head: double pointer to the head of the linked list
 * @index: index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *present, *prev;
    unsigned int i = 0;

    if (*head == NULL)
        return (-1);

    present = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        free(present);
        return (1);
    }

    while (i < index && present != NULL)
    {
        prev = present;
        present = present->next;
        i++;
    }

    if (i == index && present != NULL)
    {
        prev->next = present->next;
        free(present);
        return (1);
    }

    return (-1);
}

