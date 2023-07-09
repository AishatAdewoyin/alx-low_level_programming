#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the array
 *
 * Return: On success, returns a pointer to the newly created hash table.
 * On failure, returns NULL.
 */
hash_table_t *hash_table_create(unsigned long int size)

{
	hash_table_t *new_hash_table;

	/* Allocate memory for the hash table structure */
	new_hash_table = malloc(sizeof(hash_table_t));
	if (new_hash_table == NULL)
		return (NULL);

	/* Allocate memory for the array of hash nodes */
	new_hash_table->array = calloc(size, sizeof(hash_node_t *));
	if (new_hash_table->array == NULL)
	{
		free(new_hash_table);
		return (NULL);
	}

	/* Set the size of the hash table */
	new_hash_table->size = size;

	return (new_hash_table);
}
