#include <stdio.h>

int one_to_n(int n)
{
    if (n < 1)
        return 1;
    printf("%d\n", n);   
    one_to_n(n - 1);
}

int main()
{
    one_to_n(5);
    return 0;
}