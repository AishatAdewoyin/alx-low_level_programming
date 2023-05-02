#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_strings - prints strings, followed by a new line.
* @separator: string to be printed between the strings
* @n: number of strings passed to the function
* @...: variable number of arguments
*
* Return: void
*/

void print_strings(const char *separator, const unsigned int n, ...)

{
va_list args;
unsigned int i;
char *str;
va_start(args, n);
for (i = 0; i < n; i++)

{
str = va_arg(args, char *);
printf("%s", str != NULL ? str : "(nil)");
if (separator != NULL && i < n - 1)
printf("%s", separator);
}
printf("\n");
va_end(args);
}
