#include "stdio.h"

int sum_of_nums(int n)
{
    int sum = 0;

    if (!n)
        return 0;
    return sum_of_nums(n /= 10) + n % 10;
}

int right_to_left_num(int n)
{
    if (n == 0)
        return 1;

    printf("%d ", n % 10);
    right_to_left_num(n /= 10);
}

int left_to_right_num(int n)
{
    if (n == 0)
        return 1;
    
    left_to_right_num(n /= 10);
    printf("%d ", n % 10);
}

int main()
{
    printf("%d", sum_of_nums(123));
    return 0;
}