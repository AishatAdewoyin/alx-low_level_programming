#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_numbers - This function prints numbers
 * @separator: string parameter
 * @n: int constant
 * Return: void
 * Date: 23-02-2023
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list print;
unsigned int i;
va_start(print, n);
for (i = 0; i < n; i++)
{
printf("%d", va_arg(print, int));
if (separator != NULL && i != n - 1)
printf("%s", separator);
}
va_end(print);
printf("\n");
}
