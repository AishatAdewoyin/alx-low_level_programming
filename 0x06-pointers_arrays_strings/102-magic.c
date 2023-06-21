#include <stdio.h>

int main(void)
{
    int n;
    int a[5];
    int *p;

    a[2] = 1024;
    p = &n;

    /*
     * Write your line of code here...
     * Remember:
     * - You are not allowed to use 'a'
     * - You are not allowed to modify 'p'
     * - Only one statement is allowed
     * - You are not allowed to code anything else than this line of code
     */
    *(p + 7) = 98;
    
    /* Accessing the memory location pointed by 'p'
     * with an offset of 7 and assigning the value 98
     * ...so that this prints 98\n
     *
     */
    printf("a[2] = %d\n", a[2]);
    return (0);
}
