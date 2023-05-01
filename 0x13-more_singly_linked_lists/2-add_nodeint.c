#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @n: The integer to be stored in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nodeAtTheBeginning;

	if (head == NULL)
		return (NULL);

	nodeAtTheBeginning = malloc(sizeof(listint_t));
	if (nodeAtTheBeginning == NULL)
		return (NULL);

	nodeAtTheBeginning->n = n;
	nodeAtTheBeginning->next = *head;
	*head = nodeAtTheBeginning;

	return (nodeAtTheBeginning);
}

