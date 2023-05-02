#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the head node of the list
 * @index: index of the node to be returned
 *
 * Return: pointer to the node at index, or NULL if it does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)

{
listint_t *current = head;
unsigned int i = 0;

while (current != NULL)
{
if (i == index)
return (current);
i++;
current = current->next;
}
return (NULL);
}
