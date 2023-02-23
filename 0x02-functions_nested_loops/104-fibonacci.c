#include <stdio.h>

/**
 * main - Entry point
 * Return: 0
*/ 

int main(void) 
{
int n = 98; /* number of Fibonacci numbers to print */
int a = 1, b = 2; /* initial Fibonacci numbers */
printf("%d, %d", a, b); /* print the first two Fibonacci numbers */
for (int i = 2; i < n; i++) 
{
int c = a + b; /* calculate the next Fibonacci number */
printf(", %d", c); /* print it */
a = b; /* update the rolling sum */
b = c;
}
printf("\n");
return (0);
}
