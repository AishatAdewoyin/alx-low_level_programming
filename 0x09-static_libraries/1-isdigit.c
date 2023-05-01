#include "main.h"

/**
* _isdigit - checks if a character is a digit (0-9)
* @c: the character to check
* Return: 1 if c is a digit, otherwise 0
*/

int _isdigit(int c)

{
	switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	return (1);
	default:
	return (0);
	}
}
