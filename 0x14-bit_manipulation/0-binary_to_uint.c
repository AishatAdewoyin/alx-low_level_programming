#include "main.h"

/**
* binary_to_uint - function that converts
* binary to unsigned int
* @b: binary number to convert
* Return: Unsigned int
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int uint = 0;
	int i = 0, binary;

	if (!b)
		return (0);

	while (b[i] != '\0')
		i++;

	for (i--, binary = 1; i >= 0; i--, binary *= 2)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		if (b[i] & 1)
			uint += binary;
	}

	return (uint);
}
