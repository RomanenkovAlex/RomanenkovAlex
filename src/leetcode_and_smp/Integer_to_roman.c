#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * intToRoman(int num)
{
    char* Roman_string = (char*)malloc(30 * sizeof(char));

    for (int i = 0; i < 30; i++)
    {
        Roman_string[i] = '\0';
    }    
    
    char I = 'I'; // 1
    char V = 'V'; // 5
    char X = 'X'; // 10
    char L = 'L'; // 50
    char C = 'C'; // 100
    char D = 'D'; // 500
    char M = 'M'; // 1000

    int degit = num;

    while(degit != 0)
    {
        if(degit >= 1000)
        {
            strncat(Roman_string, &M, 1);
            degit -= 1000;
        }
        else if(degit >= 900)
        {
            strncat(Roman_string, &C, 1);
            strncat(Roman_string, &M, 1);
            degit -= 900;
        }
        else if(degit >= 500)
        {
            strncat(Roman_string, &D, 1);
            degit -= 500;
        }
        else if(degit >= 400)
        {
            strncat(Roman_string, &C, 1);
            strncat(Roman_string, &D, 1);
            degit -= 400;
        }
        else if(degit >= 100)
        {
            strncat(Roman_string, &C, 1);
            degit -= 100;
        }
        else if(degit >= 90)
        {
            strncat(Roman_string, &X, 1);
            strncat(Roman_string, &C, 1);
            degit -= 90;
        }
        else if(degit >= 50)
        {
            strncat(Roman_string, &L, 1);
            degit -= 50;
        }
        else if(degit >= 40)
        {
            strncat(Roman_string, &X, 1);
            strncat(Roman_string, &L, 1);
            degit -= 40;
        }
        else if(degit >= 10)
        {
            strncat(Roman_string, &X, 1);
            degit -= 10;
        }
        else if(degit >= 9)
        {
            strncat(Roman_string, &I, 1);
            strncat(Roman_string, &X, 1);
            degit -= 9;
        }
        else if(degit >= 5)
        {
            strncat(Roman_string, &V, 1);
            degit -= 5;
        }
        else if(degit >= 4)
        {
            strncat(Roman_string, &I, 1);
            strncat(Roman_string, &V, 1);
            degit -= 4;
        }
        else if(degit >= 1)
        {
            strncat(Roman_string, &I, 1);
            degit -= 1;
        }
    }
// гений игры в чате   
    return Roman_string;
}