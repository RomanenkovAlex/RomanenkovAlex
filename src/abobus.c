#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *get_file_ext_pos(char *filename)
{
    char *ext = 0;

// "\0" - const char * - 0x560ce602100d
// '\0' - char - 0

    if (!filename)
        return NULL;
    ext = strrchr(filename, '.');
    if (ext)
        ++ext;
    return ext;
}

size_t number_length(long long num)
{
    size_t length = (num <= 0);

    while (num != 0)
    {
        num /= 10;
        length++;
    }
    return length;
}

char *file_add_num(char *filename, int num)
{
    size_t filename_len = strlen(filename);
    size_t num_len = number_length(num);
    int len = filename_len + num_len + 2;
    char *result = malloc(len * sizeof(char));
    char *ext = get_file_ext_pos(filename);

    if (!result)
        return NULL;
    
    if (ext)
    {
        strncpy(result, filename, filename_len - );
        snprintf(result, len, "%s_%d.%s", result, num, ext);
    }    
    else
        snprintf(result, len, "%s_%d", filename, num);    
    return 
}

int main()
{
    const char *filename_noformat = "09fizika";
    const char *format = "file.avi";
    char *filename = file_add_num(format, 10);
 
    printf("%s\n", filename);
    free(filename);
    return 0;
}
