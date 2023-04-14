#include <stdio.h>

void reverse(const char *s)
{
    int len = 0;
    
    while (*s)
    {
        len++;
        ++s;
    }
    while (len)
    {
        --s;
        putc(*s);
        --len;
    }
    
    s -= len;
    while (len >= 0)
    {
        printf("%c", s[len - 1]);
        --len;
    }
}

void reverse_rec(const char *s)
{
    static int count = 0;
    printf("%d - %p\n", count, s);
    ++count;

    if (*s == 0)
        return;
    reverse_rec(s + 1);
    putc(*s);
}

int main(int argc, char **argv)
{
    const char *s = ((argc > 1) ? argv[1] : "default");

    printf("string = %s\n", s);
    reverse(s);
    printf("\n");

    return 0;
}