#include "search_algos.h"
/**
 * linear_search - searches for value in array of
 * ints with the Linear search algorithm
 * @array: pointer to the first element of array to search in.
 * @size: number of elements in array
 * @value:  the value to search for
 * Return: -1 if the value is not in the array or NULL, 
 * otherwise first index of location.
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%u] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
