#include "main.h"

/**
* _strstr - This function finds the occurrence of needle in the string haystack.
* @haystack: string searched.
* @needle: substring to locate.
* Return: the beginning of the substring located
*/

char *_strstr(char *haystack, char *needle)

{
	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*n && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return haystack;

		haystack++;
	}

	return (NULL);
}
