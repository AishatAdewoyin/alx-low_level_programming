#include "hash_tables.h"
/**
 * hash_table_get- Retrieves value associated with key
 * @ht: hash table to search.
 * @key: Key
 * Return: Value associated with key otherwise NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i;
	hash_node_t *tmp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	i = key_index((unsigned	char *)key, ht->size);
	tmp = ht->array[i];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

