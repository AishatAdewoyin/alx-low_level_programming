#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list, and returns
 *               the head node's data (nodeData).
 * @head: Pointer to the pointer of the first node of the list.
 *
 * Return: The head node's data (nodeData).
 *         If the linked list is empty, returns 0.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int nodeData;

	if (*head == NULL)
		return (0);

	temp = *head;
	*head = temp->next;
	nodeData = temp->nodeData;
	free(temp);

	return (nodeData);
}
