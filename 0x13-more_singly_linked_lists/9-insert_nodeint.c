#include "lists.h"

/**
 * insert_nodeint_at_index - insertng a new node in a linked list,
 * at certain position
 * @head: it points to the first node in the list
 * @idx: this is the index where the new node is added
 * @n: this is the  data to be  inserted in the new node
 *
 * Return: points to the new node, or  returns NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
 unsigned int i;
 listint_t *new;
 listint_t *temp = *head;

 new = malloc(sizeof(listint_t));
 if (!new || !head)
 return (NULL);

 new->n = n;
 new->next = NULL;

 if (idx == 0)
 {
 new->next = *head;
 *head = new;
 return (new);
 }

 for (i = 0; temp && i < idx; i++)
 {
 if (i == idx - 1)
 {
 new->next = temp->next;
 temp->next = new;
 return (new);
 }
 else
 temp = temp->next;
 }

 return (NULL);
}

