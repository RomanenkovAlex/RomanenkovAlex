#include <stdio.h>
#include <string.h>

char *strrev(char *str)
{
    
}

void rev_rec(char *p_b, char *p_e)
{
    if (p_b >= p_e)
        return ;
    char s = *p_b;
    *p_b = *p_e;
    *p_e = s;
    strrev_rec(p_b + 1, p_e - 1);
}

char *strrev_rec(char *str)
{
    rev_rec(str, str + strlen(str) - 1);
    return str;
}


int main()
{ 
    char buf[BUFSIZ];
    const char *s = "abcdefg";
    strcpy(buf, s);

    printf("%s", strrev_rec(buf, buf + strlen(buf) - 1)); // char *ptr;
    return 0;
}