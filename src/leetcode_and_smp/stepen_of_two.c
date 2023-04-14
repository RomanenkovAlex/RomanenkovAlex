#include "stdio.h"
#include <limits.h>

int power(int n)
{
    if (n == 1)
        return 1;
    if (n % 2)
        return 0;
    return power(n / 2);
}


int main()
{
    printf("%d\n", power(2));
    printf("%d %d\n", INT_MIN, INT_MAX);
    printf("%d\n", abs(INT_MIN));
    return 0;
}