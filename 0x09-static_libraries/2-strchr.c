#include "main.h"

/**
* _strchr - This function locates a character in a string.
* @s: The string searched.
* @c: The character to be identified.
* Return: Pointer to the first occurrence of the character in the string,
* or NULL if the character is not found.
*/

char *_strchr(char *s, char c)

{
	while (*s != '\0')
	{
	if (*s == c)
		return (s);
	s++;
	}

	if (c == '\0')
	return (s);
	return (NULL);
}
