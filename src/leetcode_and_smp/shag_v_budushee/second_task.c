#include <stdio.h>
#include <math.h>

int perevod(int a)
{
    long long int n = 0;
    int k, m = 0;
    while(a) 
    {
        k = a % 2;
        a = a / 2;
        n += k * pow(10, m);
        m++;
    }
    return n;
}

int main()
{
    int a = 0;
    int b = 0;
    printf("%d\n", perevod(123));
    scanf("%d %d", &a, &b);
 //   for (int i = a; i < b; ++i)
 //   {
 //       perevod(i)
 //   }


    return 0;
}