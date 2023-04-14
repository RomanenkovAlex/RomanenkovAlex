#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>

int file_len(FILE *file)
{
    int len = 0;

    while (!feof(file))
    {
        getc(file);
    	++len;
    }
    return len; 
}

void print_file(FILE *filename, int len)
{
    char buf[BUFSIZ];
    fseek(filename, 0, SEEK_SET);
    for (int j = 0; j < len; ++j)
	{
		fread(buf, 1, 1, filename);
		printf("%c", buf[0]);
	}
}

void book_search(FILE *filename, char *word, int len) 
{
    int line = 1;
    int line_len = 0;
    char *line_string = (char*)malloc(sizeof(char) * 15);
    char buf[BUFSIZ];
    fseek(filename, 0, SEEK_SET);
    
    for (int j = 0; j < len; ++j)
	{   
        fread(buf, 1, 1, filename);
        if (buf[0] == '\n')
        {
            line++;
            
        }
        else if (buf[0] != '\n')
        {
            line_len++;
        }
        fgets(line_string, line_len, filename);
        if (strcmp(line_string, word) == 0)
        {
            printf("%s", line_string);
        }
        else
        {
            printf("line not found\n");
        }

//		if (word[cur_position_in_word] == buf[0])
//        {
//            cur_position_in_word++;
//        }
//        if (cur_position_in_word == word_len - 1)
//        {
//            printf("%d\n", line);
//        }        
	}
}