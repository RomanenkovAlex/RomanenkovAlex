#include <stdio.h>

void sub_menu_book()
{

}

void sub_menu_user()
{
    
}

void menu()
{
    puts("Menu:");
    puts("\t0) exit");
    puts("\t1) books list");
    puts("\t2) book search");
    puts("\t3) give book");
    puts("\t4) add book");
    puts("\t5) remove book");
    puts("\t6) add user");
    puts("\t7) remove user");
}

int get_operation()
{
    int operation = -1;

    puts("Input operation: ");
    while (scanf("%d", &operation) != 1 && getchar() != EOF)
    {
        while (getchar() != EOF)
            ;
        puts("Input operation: ");
    }
}