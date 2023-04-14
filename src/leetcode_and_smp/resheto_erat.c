#include <stdio.h>
#include <string.h>


char *resheto_erat(int n)
{
    char *mas = (char *)malloc(n * sizeof(char));
    int i = 2;
    int j = 0;

    memset(mas, 0x01, n);
    while (i < n)
    {
        if (mas[j])
            mas[j] = 0;
    } 
    return mas;
}


int main()
{
    resheto_erat(100);

    return 0;
}