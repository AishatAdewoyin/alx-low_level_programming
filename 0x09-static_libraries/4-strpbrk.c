#include "main.h"
/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string parameter searched.
 * @accept: The set of bytes searched for.
 * Return: pointer to the first occurrence of a character in `accept`
 *         that matches any character in `s`, or NULL if no match is found.
 */
char *_strpbrk(char *s, char *accept)
{
	char *p;

	while (*s != '\0')
	{
		for (p = accept; *p != '\0'; p++)
		{
			if (*p == *s)
				return (s);
		}
		s++;
	}

	return (NULL);
}
