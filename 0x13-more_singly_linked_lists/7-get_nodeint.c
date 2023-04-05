#include "lists.h"

/**
 * get_nodeint_at_index - it returns the node at a  index in the linked list
 * @head: the first node in the linked list
 * @index: the index of the node to be returned
 *
 * Return: points to the node we are  looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int count = 0;

listint_t *current = head;
while(current != NULL)
{

	if (count == index)
		return current;
	count++;
	current = current->next;
}

return NULL;

}
