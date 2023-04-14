#include <stdio.h>

int perevod(int n)
{
    int a = 1;
    int b = 0;
    int dv1 = 0;
    while (a != 0)
    {
        scanf("%d", a);
        b = a;
        while (b != 0)
        {
            dv1 = dv1 * 10 + b % 2;
            b = b / 2;
        }
        return dv1;
    }
}

int getReversedNum(num) 
{
  int result = 0;
  while (num)
{
    result = result * 10 + num % 10;
    num = num / 10;
  }
  return result;
}

int main()
{
    a = 1;
    while (a != 0)
    {
        scanf("%d", &a);
    }
    return 0;
}