#include "main.h"

/**
 * _strncat - Concatenates two strings up to a maximum of n bytes
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string
 * @n: Maximum number of bytes to concatenate from src
 *
 * Return: Pointer to the resulting string (i.e. dest)
 */
char *_strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = strlen(dest);
    size_t b;

    for (b = 0; b < n && src[b] != '\0'; b++)
        dest[dest_len + b] = src[b];

    dest[dest_len + b] = '\0';

    return (dest);
}
