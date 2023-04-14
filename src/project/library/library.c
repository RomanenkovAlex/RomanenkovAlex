#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

#include "functions.h"
#include "menu.h"

//void del_from_file(FILE *filename, char *word)
//{
//    int len;
//
//    char buf[BUFSIZ];
//    while (!feof(filename))
//    	++len;
//
//    for (int j = 0; j < len; ++j)
//	{
//		fread(buf, 1, 1, filename);
//		if (strstr(buf, word))
//           ;//delete(buf); // deleting not done yet
//	}
//}

struct book
{
    // title
    // author
    // year
    // typo
    // isbn
    // count
};

struct user
{
    // id
    // f
    // i
    // o
    // book -> list may be?
};

struct library
{
    // books -> list may be?
    // user -> list may be?
    // 
};



int main()
{
    FILE *books = fopen("books.txt", "r+");
    FILE *people = fopen("people.txt", "r+"); 

    printf("Welcome to the virtual library!\n");
    while ((op = get_operation()))
    {
        switch (op)
        {
        case 0:
            break;
        default:
            puts("");
            break;
        }

        if (strcmp(input_word, "1") == 0)
        {
            out(books, len_of_file(books));
        }
        else if (strcmp(input_word, "2") == 0)
        {
            printf("please enter author name or book name: ");
            scanf("%s", book_stuff);
            search(books, book_stuff, len_of_file(books));
        }
        else if (strcmp(input_word, "3") == 0)
        {
            printf("please enter author name or book name: ");
            scanf("%s", book_stuff);
            printf("Please enter your full name and your date of birth:\n");
            scanf("%s", human_data);
            fprintf(people, "%s - %s\n", human_data, book_stuff);   
        }
        else if (strcmp(input_word, "4") == 0)
        {
            printf("Please enter author name and name of the book:\n");
            scanf("%s %s %s", author_name, author_surname, book_stuff);
            fseek(books, 0, SEEK_END);
            fprintf(books, "%s %s %s\n", author_name, author_surname, book_stuff);
        }
        else
        {
            printf("bye\n");
            break;
        }
    }

    fclose(books);
    fclose(people);
    getc(books);
    getc(people);
    return 0;
}