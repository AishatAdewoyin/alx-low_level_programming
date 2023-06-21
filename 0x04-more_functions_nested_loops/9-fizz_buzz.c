#include "main.h"
#include <stdio.h>

/**
 * main - Prints the numbers from 1 to 100, with some conditions.
 *
 * Description: Prints numbers from 1 to 100, but for multiples of three
 *              prints "Fizz", for multiples of five prints "Buzz",
 *              and for multiples of both three and five prints "FizzBuzz".
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 != 0)
		{
			printf("Fizz ");
		}
		else if (i % 5 == 0 && i % 3 != 0)
		{
			printf("Buzz ");
		}
		else if (i % 3 == 0 && i % 5 == 0)
		{
			printf("FizzBuzz ");
		}
		else
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return (0);
}
