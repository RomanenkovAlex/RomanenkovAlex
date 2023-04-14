#include <stdio.h>

int main()
{
    int n = 0;
    int d = 0;
    int c = 1;
    float a = 0;
    float b = 0;

    scanf("%d", &n);
    scanf("%f", &a);

    for (int i = 2; i <= n; ++i)
    {
        scanf("%f", &b);
        if ((b < a) && (c = 1))
            d += 1;

        if (b < a)
            c = 0;
        if (b > a)
            c = 1;

        a = b;
    }
    printf("%d", d); 

    return 0;
}