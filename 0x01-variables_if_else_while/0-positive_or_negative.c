#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - This program will assign a random number to the variable n each time it is executed
 * Return: Always 0
 */

int main()
{

srand(time(NULL));
int n = rand() - RAND_MAX/2;
printf("%d ", n);

if (n > 0){
	printf("is positive \n");
}

else if (n == 0){
printf("is zero \n);
}

else{
printf("is negative \n");
}

return (0);

}
