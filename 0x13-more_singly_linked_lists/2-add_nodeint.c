#include "lists.h"

/**
 * add_nodeint - will add a new node at the beginning of the linked list
 * @head: is the pointer that points to the first node in the list
 * @n: the data to insert in the new node
 *
 * Return: points to the new node, or returns NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
 listint_t *new;

 new = malloc(sizeof(listint_t));
 if (!new)
 return (NULL);

 new->n = n;
 new->next = *head;
 *head = new;

 return (new);
}
