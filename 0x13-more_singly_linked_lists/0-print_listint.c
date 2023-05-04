#include "lists.h"

/**
* print_listint - this prints all the elements
* of a listint_t list.
* @h: Head of the list.
* Return: This is the number of nodes in the list.
*/

size_t print_listint(const listint_t *h)
{
size_t numberOfNodes = 0;

while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
numberOfNodes++;
}

return (numberOfNodes);
}
