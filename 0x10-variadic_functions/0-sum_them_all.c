#include "variadic_functions.h"
/**
 * sum_them_all - function that returns sum of parameters
 * @n: integers constant
 * Return: sum
 * Date: 23-03-2023
 */
int sum_them_all(const unsigned int n, ...)
{
va_list num;
unsigned int i, sum;
if (n == 0)
return (0);
va_start(num, n);
sum = 0;
for (i = 0; i < n; i++)
sum += va_arg(num, int);
va_end(num);				
return (sum);
}
