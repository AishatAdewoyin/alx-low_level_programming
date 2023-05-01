#include "main.h"

/*
* _strlen - This function returns the length of the string.
* @s:parameter assigned.
* Return: len the length of String.
*/

int _strlen(char *s)
{
int len;

for (len = 0; s[len] != '\0'; len++);

return (len);
}
