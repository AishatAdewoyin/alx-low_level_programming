#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a latest node at a given position
 * @head: Pointer to the head node of the list
 * @idx: Index where latest node should be inserted (starting from 0)
 * @n: Value to be stored in the new node
 *
 * Return: Address of the new node or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)

{
unsigned int i;
listint_t *latestNode, *tmp;
if (head == NULL)
return (NULL);

/* Create new node */
latestNode = malloc(sizeof(listint_t));
if (latestNode == NULL)
return (NULL);
latestNode->n = n;

if (idx == 0) /* Insert at beginning of list */
{
latestNode->next = *head;
*head = latestNode;
}
else /* Insert at any other position */
{
tmp = *head;
for (i = 0; i < idx - 1 && tmp != NULL; i++)
tmp = tmp->next;

/* Check if the given index is valid */
if (tmp == NULL)
{
free(latestNode);
return (NULL);
}

latestNode->next = tmp->next;
tmp->next = latestNode;
}
return (latestNode);
}
