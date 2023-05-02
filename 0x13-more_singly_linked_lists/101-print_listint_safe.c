#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: A pointer to the head node of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)

{
const listint_t *tortoise, *hare;
size_t count = 0;

if (head == NULL)
exit(98);

tortoise = hare = head;

while (tortoise && hare && hare->next)
{
tortoise = tortoise->next;
hare = hare->next->next;

/* If there is a loop */
if (tortoise == hare)
{
/* Print nodes before the loop */
do {
printf("[%p] %d\n", (void *)tortoise, tortoise->n);
tortoise = tortoise->next;
count++;
}

while (tortoise != hare)
{
/* Print the loop */
printf("[%p] %d\n", (void *)tortoise, tortoise->n);
printf("-> [%p] %d\n", (void *)hare, hare->n);
count++;
return (count);
}

/* If there is no loop, print the current node */
printf("[%p] %d\n", (void *)tortoise, tortoise->n);
count++;
}

return (count);
}
