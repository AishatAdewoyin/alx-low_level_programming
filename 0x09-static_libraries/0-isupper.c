#include "main.h"

/**
* _isupper - This function shows if the program is in uppercase
* @c: The parameter for the function
* Return: If uppercase, 1, else 0.
*/
int _isupper(int c)
{
	switch (c)
	{
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		return (1);
	default:
		return (0);
	}
}
