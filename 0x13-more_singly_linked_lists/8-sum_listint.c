#include "lisits.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: pointer to the head node of the list
 *
 * Return: the sum of all the data, or 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *latest = head;

	while (latest)
	{
		sum += latest->n;
		latest = latest->next;
	}

	return (sum);
}
