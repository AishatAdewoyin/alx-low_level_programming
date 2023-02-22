#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 */

void times_table(void)
{
int row, column, result;

for (row = 0; row < 10; row++)
{
for (column = 0; column < 10; column++)
{
result = row * column;

/* Print the result */
if (column == 0)
_putchar('0' + result);
else if (result < 10)
{
_putchar(',');
_putchar(' ');
_putchar(' ');
_putchar('0' + result);
}
else
{
_putchar(',');
_putchar(' ');
_putchar('0' + (result / 10));
_putchar('0' + (result % 10));
}
}
/* Move to the next line */
_putchar('\n');
}
}
