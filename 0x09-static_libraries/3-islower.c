#include "main.h"
/**
 * _islower - a function that checks for lowercase
 * @c: the character
 * Return: 1 if lowercase, else 0.
 */
int _islower(int c)
{
	return (c >= 'a' && c <= 'z') ? 1 : 0;
}
