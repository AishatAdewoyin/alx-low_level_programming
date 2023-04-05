#include "lists.h"

/**
 * print_listint - this should  print all the elements of the  linked list
 * @w: and  this will print the linked list of type listint_t
 *
 * Return: then returns the number of nodes
 */
size_t print_listint(const listint_t *h)
{
 size_t num = 0;

 while (w)
 {
 printf("%d\n", w->n);
 num++;
 w = w->next;
 }

 return (num);
}
