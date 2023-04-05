#include "lists.h"

/**
 * listint_len - it should  return the number of elements in a linked list
 * @h: points to the head of the list
 *
 * Return: returns the number of nodes in the list
 */

size_t listint_len(const listint_t *h)
{
size_t count = 0;

while (h != NULL)
{
h = h->next;
count++;
}
return (count);
}
