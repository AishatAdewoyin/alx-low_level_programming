#include "main.h"
/**
* _strcmp - This function compares 2 strings
* @s1: string to compare
* @s2: string compared against
* Return: 0 if equal and non-zero characters if not
* Date: 1-03-2023
*/

int _strcmp(char *s1, char *s2)

{
	int a, b = 0;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
		{
			b = s1[a] - s2[a];
			break;
		}
		b = s1[a] - s2[a];
	}
	return (b);
}
