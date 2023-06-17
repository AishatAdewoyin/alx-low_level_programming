#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"lists.h"

/**
 * main - Entry point of the program.
 * Return: EXIT_SUCCESS if successful,
 * EXIT_FAILURE otherwise.
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *new;
	dlistint_t hello = {8, NULL, NULL};
	size_t n;

	head = &hello;

	/* Allocate memory for a new node */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (EXIT_FAILURE);
	}

	new->n = 9;
	head->prev = new;
	new->next = head;
	new->prev = NULL;
	head = new;

	/* Print the elements in the doubly linked list */
	n = print_dlistint(head);
	printf("->%lu elements\n", n);

	free(new);

	return (EXIT_SUCCESS);
}
