#include "lists.h"

/**
 * sum_dlistint - Sums the data of a doubly linked list.
 * @head: Pointer to the head of the linked list.
 * Return: The sum of the data, otherwise 0.
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *temp = head;
	int sum = 0;

	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
