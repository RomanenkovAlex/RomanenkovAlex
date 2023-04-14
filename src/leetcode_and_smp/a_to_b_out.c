#include "stdio.h"

int a_b(int a, int b)
{
    if (a > b)
    {
        a_b(a - 1, b);
        printf("%d\n", a);
    }
    else if (a < b)
    {
        printf("%d\n", b);
        a_b(a, b - 1);
    }
    return 0;   
}

int main()
{
    a_b(103,79);
    return 0;
}