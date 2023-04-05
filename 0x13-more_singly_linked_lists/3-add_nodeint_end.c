#include "lists.h"

/**
 * add_nodeint_end - should  add a node at the end of the linked list
 * @head: pointing to the first element in the list
 * @n: the data to be inserted in the new element
 *
 * Return: the address of the new element, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *n_node *temp;

n_node = malloc(sizeof(listint_t));
if (n_node == NULL)
	return (NULL);
n_node->n = n;
n_node->next = NULL;

if (*head == NULL)
{
*head = n_node;
return (n_node);
}
temp = *head;
while (temp->next != NULL)
	temp = temp->next;

temp->next = n_node;
return (n_node);
}
