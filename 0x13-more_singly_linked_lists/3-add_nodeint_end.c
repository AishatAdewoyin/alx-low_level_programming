#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to the head of the list
 * @n: integer to be added to the new node
 *
 * Return: address of the new element or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *addedNode = malloc(sizeof(listint_t));
    listint_t *newlyAdded = *head;

    if (!addedNode)
        return (NULL);

    addedNode->n = n;
    addedNode->next = NULL;

    if (!newlyAdded)
    {
        *head = addedNode;
        return (addedNode);
    }

    while (newlyAdded->next)
        newlyAdded = newlyAdded->next;

    newlyAdded->next = addedNode;

    return (addedNode);
}
