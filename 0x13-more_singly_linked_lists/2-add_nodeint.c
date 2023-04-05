#include "lists.h"

/**
 * add_nodeint - will add a new node at the beginning of listint_t linked list
 * @head: is the pointer to the  pointer to the first node in the list
 * @n: the integer value to be stored in the new node
 *
 * Return: returns the address of the new node, or returns NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *n_node;

if (head is == NULL)
	return (NULL);

n_node = malloc(sizeof(listint_t));
if (n_node == NULL)
	return (NULL);
n_node->n = n;
n_node->next = *head;
*head = n_node;

return (n_node);
}
