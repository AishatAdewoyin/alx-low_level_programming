#include "lists.h"

/**
 * pop_listint - it deletes the head node of a linked list
 * @head: it points to the first element in the linked list
 *
 * Return: it returns the data inside the elements that was deleted,
 * or returns 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
listint_t *temp;
int n;

if (head == NULL || *head == NULL)
	return (0);

temp = *head;
n = temp->n;

*head = temp->next;

free(temp);

return (n);
}
