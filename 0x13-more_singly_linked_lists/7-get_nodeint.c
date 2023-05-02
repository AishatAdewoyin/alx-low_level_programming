/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to the head node of the list
 * @index: index of the node to return
 *
 * Return: pointer to the nth node, or NULL if it does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;
	listint_t *nthNodePointer;

	if (head == NULL)
		return (NULL);

	nthNodePointer = head;
	for (j = 0; j < index; j++)
	{
		if (nthNodePointer->next == NULL)
			return (NULL);
		nthNodePointer = nthNodePointer->next;
	}

	return (nthNodePointer);
}
