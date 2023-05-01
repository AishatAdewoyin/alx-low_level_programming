#include "main.h"

/**
 * _strcpy - Copies the string pointed to by `src` into the buffer
 *           pointed to by `dest`.
 * @dest: A buffer to copy the string into.
 * @src:  The string to copy.
 *
 * Return: A pointer to `dest`.
 */
char *_strcpy(char *dest, const char *src)
{
    char *dest_start = dest;
    
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    
    return (dest_start);
}
