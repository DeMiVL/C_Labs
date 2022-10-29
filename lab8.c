#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int main()
{
    int  i = 0;
    int  n = 0;
    char c = ' ';
    while(1)
    {
        c  = _getch();
        if(c == 0)
        {
            c = _getch();
            if (c == 84) break;
        }
        n++;
        i += c;
        printf("\'%c\'", c);
    }
    printf("\n\'%c\'\n", (i / n));
    return 0;
}
