#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: Pointer to the head of the list
 *
 * Return: The size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *slow = *h, *fast = *h, *tmp;
    size_t size = 0;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        size++;

        /* Detect loop */
        if (slow == fast)
        {
            *h = NULL;
            return (size);
        }

        /* Free node */
        tmp = slow->next;
        free(slow);
        slow = tmp;
    }

    /* Free remaining nodes */
    while (*h)
    {
        tmp = (*h)->next;
        free(*h);
        *h = tmp;
        size++;
    }

    return (size);
}

