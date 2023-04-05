#include "lists.h"

/**
 * print_listint - this should  print all the elements of the linked list
 * @h: and this will print the linked list of type listint_t
 *
 * Return: then returns the number of nodes
 */
size_t print_listint(const listint_t *h)
{
 size_t num = 0;

 while (h)
 {
 printf("%d\n", h->n);
 num++;
 h = h->next;
 }

 return (num);
}
