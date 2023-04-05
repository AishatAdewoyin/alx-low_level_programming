#include "lists.h"

/**
 * listint_len - it should  return the number of elements in a linked list
 * @h: links lists of types accross  listint_t
 *
 * Return: returning the number of nodes
 */
size_t listint_len(const listint_t *h)
{
 size_t num = 0;

 while (h)
 {
 num++;
 h = h->next;
 }

 return (num);
}
