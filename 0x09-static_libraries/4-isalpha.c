#include "main.h"

/**
* _isalpha - checks for alphabetic character
* @c: the character to be checked
* Return: 1 if c is an alphabetic character, 0 otherwise
*/

int _isalpha(int c)

{
	switch (c)
	{
	case 'a'...'z':
	case 'A'...'Z':
	return (1);
	default:
	return (0);
	}
}
