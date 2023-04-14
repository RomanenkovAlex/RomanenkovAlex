#include <stdio.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int file_len(FILE *file);
void print_file(FILE *filename, int len);
void book_search(FILE *filename, char *word, int len);

#endif