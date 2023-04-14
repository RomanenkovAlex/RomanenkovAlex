#include <stdio.h>
#include <errno.h>

int main()
{
    char buf[BUFSIZ];
    int k = 0;
    int err = 0;

    FILE *file = fopen("a.out", "rb");
    
    //printf("EACCES - %d\n", EACCES);
    if (!file)
    {
        err = errno; // EACCES
        perror("fopen");
        return err;
    }

    while (feof(file) == 0)
    {
        fread(buf, 1, 1, file);
        printf("%02hhx ", buf[0]);
        if (k == 16)
        {
            printf("\n");
            k = 0;
        }
        ++k;
    }
    return 0;
}