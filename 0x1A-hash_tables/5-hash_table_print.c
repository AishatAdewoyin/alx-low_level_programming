#include "hash_tables.h"
/**
 * hash_table_print - prints hash table
 * @ht: The hash table
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;
	char *separator;

	if (ht == NULL)
		return;

	printf("{");
	separator = "";

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			printf("%s'%s': '%s'", separator, tmp->key, tmp->value);
			separator = ", ";
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
