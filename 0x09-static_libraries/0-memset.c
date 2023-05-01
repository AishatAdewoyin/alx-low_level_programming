#include "main.h"

/**
 * _memset - This function fills the memory with a constant byte.
 * @s: the memory area
 * @b: the constant byte
 * @n: bytes
 * Return: s memory area pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
    char *ptr = s;

    while (n--)
        *ptr++ = b;

    return (s);
}
