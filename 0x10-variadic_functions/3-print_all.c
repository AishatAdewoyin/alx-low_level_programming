#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_char - prints a character
 * @valist: the va_list containing the character to print
 */
void print_char(va_list valist)
{
printf("%c", va_arg(valist, int));
}

/**
 * print_int - prints an integer
 * @valist: the va_list containing the integer to print
 */
void print_int(va_list valist)
{
printf("%d", va_arg(valist, int));
}

/**
 * print_float - prints a float
 * @valist: the va_list containing the float to print
 */
void print_float(va_list valist)
{
printf("%f", va_arg(valist, double));
}

/**
 * print_string - prints a string
 * @valist: the va_list containing the string to print
 */
void print_string(va_list valist)
{
char *str = va_arg(valist, char *);
if (str == NULL)
str = "(nil)";
printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: a list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
va_list valist;
int i = 0, j = 0;
char *sep = "";
print_t prints[] = {
{"c", print_char},
{"i", print_int},
{"f", print_float},
{"s", print_string},
{NULL, NULL}
};
va_start(valist, format);
while (format && format[i])
{
j = 0;
while (prints[j].type)
{
if (format[i] == *(prints[j].type))
{
printf("%s", sep);
prints[j].func(valist);
sep = ", ";
break;
}
j++;
}
i++;
}
printf("\n");
va_end(valist);
}
