#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int osgor = 0, osvert = 0, i, j, ch = 0, k, ch2 = 0;
    char simb;
    string str, contr = "0123456789ABCDEF";
    cin >> k;
    j = 0;
    for (i = k; i > 0; i--) {
        cin >> str;

        while (str != "") 
        {
            simb = str[str.length() - 1];
            ch += contr.find(simb);
            j += 1;
            str.erase(str.length() - 1, 1);
        }

        ch2 = ch % 5;

        switch (ch2)
        {
        case 0:
            break;
        case 1: 
            osvert += 1; 
            break;
        case 2: 
            osgor += 1; 
            break;
        case 3: 
            osvert -= 1; 
            break;
        case 4: 
            osgor -= 1; 
            break;
        }
        
        printf("%d %d\n", osgor, osvert);
        ch2 = 0;
        ch = 0;
        j = 0;
        str = "";
    }
    return 0;
}