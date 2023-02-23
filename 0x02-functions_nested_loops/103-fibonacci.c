#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms, followed by a new line.
 * Return: 0
*/

int main(void)
{
int sum = 0;
int prev = 1;
int curr = 2;

while (curr <= 4000000)
{
if (curr % 2 == 0)
{
sum += curr;
}
int next = prev + curr;
prev = curr;
curr = next;
}
printf("%d\n", sum);
return 0;
}
