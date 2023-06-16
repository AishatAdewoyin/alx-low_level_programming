#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the list.
 * Return: void.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (head != NULL)
	{
		/* Move to the first node of the list */
		while (head->prev != NULL)
			head = head->prev;

		/* Free each node until the end of the list */
		while ((temp = head) != NULL)
		{
			head = head->next;
			free(temp);
		}
	}
}
