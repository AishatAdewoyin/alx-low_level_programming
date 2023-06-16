#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a doubly linked list.
 * @head: Pointer to the head of the linked list.
 * @index: Index of the node to retrieve (starting from 0).
 * Return: Pointer to the nth node, otherwise NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head;
	unsigned int count = 0;

	while (temp != NULL)
	{
		if (count == index)
			return (temp);

		temp = temp->next;
		count++;
	}

	return (NULL);
}
