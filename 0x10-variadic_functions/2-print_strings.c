#include "variadic_functions.h"
#include <stdio.h>
/**
 * print_strings - a function that prints a string
 * @separator: String to be printed
 * @n: unsigned int parameter
 * Return: string
 * Date: 23-03-2023
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
const char *str;
unsigned int i;
va_list print;
va_start(print, n);
for (i = 0; i < n; i++)
{
str = va_arg(print, const char *);
if (str != NULL)
printf("%s", str);
else
printf("(nil)");
if (separator != NULL && i != n - 1)
printf("%s", separator);
}
va_end(print);
printf("\n");
}
