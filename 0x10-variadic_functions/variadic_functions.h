#ifndef VARIADIC_FUNC
#define VARIADIC_FUNC
#include <stdarg.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
int _putchar(char);

/**
 * struct print - A struct containing a character and its corresponding function
 * for printing a va_list argument.
 *
 * @spec: A character representing the type of the va_list argument.
 * @fn: A function pointer to a function that takes a va_list and prints a
 * single argument of type @spec.
 */
typedef struct print
{
	char spec;
	void (*fn)(va_list);
} print_t;

int _putchar(char c);
void print_char(va_list arg);
void print_integer(va_list arg);
void print_float(va_list arg);
void print_string(va_list arg);
void print_all(const char * const format, ...);


#endif
