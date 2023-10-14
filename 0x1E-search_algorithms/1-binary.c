#include "search_algos.h"
/**
 * recursive_search - searches for value in array of
 * integers using the Binary search algorithm
 * @array: input array
 * @size:  array size
 * @value: value to search in
 * Return: index of the number
 */
int recursive_search(int *array, size_t size, int value)
{
	size_t half = size / 2, i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
		return ((int)half);

	if (value < array[half])
		return (recursive_search(array, half, value));

	half++;

	return (recursive_search(array + half, size - half, value) + half);
}

/**
 * binary_search - searches for value in sorted array of integers
 * using the Binary search algorithm
 * @array: array to search
 * @size: size of the array
 * @value: value to search in
 * Return: index of number searched for.
 */
int binary_search(int *array, size_t size, int value)
{
	int index;

	index = recursive_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
