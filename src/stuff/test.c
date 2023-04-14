#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <memory.h>

void gen_name(char *buf, const char *fmt, char *preffix)
{
    static char *old_pref = NULL;
    static int part_num = 0;
    ++part_num;
    
    if (preffix != old_pref)
    {
        old_pref = preffix;
        part_num = 0;
    }
    sprintf(buf, fmt, preffix, part_num);
}

int main()
{
    char *prefs[] = {"foo", "bar", "zig"};
    const char *fmt = "%s_%02d";
    char buf[BUFSIZ];

    bzero(buf, BUFSIZ);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 10; j++)
        {
            gen_name(buf, fmt, prefs[i]);
            printf("%s\n", buf);
        }
    }

    // char *p;
    // const char *s = "23";
    // long int res = strtol(s, &p, 2);
    // int err = errno;
    // int len = strlen(s);

    // printf("begin - %p\nreal end - %p\n"
    //         "fact end - %p\nnumber - %ld\nerror - %d\n",
    //         s, s + len, p, res, err);

    return 0;
}