#include <stdio.h>

int main()
{
    int a = 0;
    int c = 0;
    int m = 0;
    int x_prev = 0;
    int n = 0;
    int x = 0;
    float sum = 0;
    float sredn = 0;

    scanf("%d %d %d %d %d", &a, &c, &m, &x, &n);

    for (int i = 1; i <= n; ++i)
    {
        x = (a * x + c) % m;
        sum += x;
    }
    sredn = sum / n;
    printf("%.4f", sredn); 

    return 0;
}