#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the head node of the list.
 * @idx: The index of the position to insert the new node.
 * @n: The value to store in the new node.
 *
 * Return: If the function succeeds, the address of the new node.
 *         Otherwise, NULL.
 */
	
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL, *next;

    if (*head == NULL || (*head)->next == NULL)
        return (*head);

    while ((*head) != NULL)
    {
        next = (*head)->next;
        (*head)->next = prev;
        prev = (*head);
        (*head) = next;
    }
    *head = prev;
    return (*head);
}


	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
