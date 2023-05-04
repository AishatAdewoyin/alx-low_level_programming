#include "main.h"


/**
* clear_bit - Sets the value of a bit t
*	at a given index.
* @n: Pointer to the unsigned long int to modify.
* @index: The index, starting from 0
*	of the bit to clear.
* Return: 1 if it worked, or -1 if an error occurred.
*/

int clear_bit(unsigned long int *n, unsigned int index)

{
if (index >= (sizeof(unsigned long int) * 8))
return (-1);

*n &= ~(1 << index);
return (1);
}
