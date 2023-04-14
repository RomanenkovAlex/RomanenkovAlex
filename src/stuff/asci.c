#include <stdio.h>

int main()
{
    int value = 33493009;

    for (int byte = 0; byte < sizeof(int); ++byte)
    {
        printf("%02hhx ", *(((char *) &value) + byte));
    }
    return 0;
}// 01 ff 10 11