#include "lists.h"

/**
 * listint_len - it should  return the number of elements in a linked list
 * @s: links lists of types accross  listint_t
 *
 * Return: returning the number of nodes
 */
size_t listint_len(const listint_t *s)
{
 size_t num = 0;

 while (s)
 {
 num++;
 s = s->next;
 }

 return (num);
}
