#include "main.h"

/**
* _memcpy - copies memory area
* @dest: the destination of the memory area
* @src: the source of the memory area
* @n: the amount of bytes to copy
*
* Return: pointer to dest
*/

char *_memcpy(char *dest, const char *src, size_t n)

{
	char *pdest = dest;
	const char *psrc = src;

	while (n--)
	*pdest++ = *psrc++;

	return (dest);
}
