#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static struct termios old, current;

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main()
{
    int  i = 0;
    int  n = 0;
    while(1)
    {
      char c = mygetch();;
      if(c == 27)
      {
        c = mygetch();
        if (c == 79)
        {
          c = mygetch();
          if (c == 80) 
          { 
            return 0;
          }
          else
          {
            continue;
          }
        }
        else if(c == 91)
        {
          c = mygetch();
          if (c == 65 || c == 66 || c == 67 || c == 68 || c == 70 || c == 72)
          {
            continue;
          }
          c = mygetch();
          if (c == 126) continue;
          c = mygetch();
          if (c == 126) continue;
          continue;
        }
      }
      if(c != 27)
      {
        n++;
        i += c;
        printf("\33[2K\r");
        printf("\'%c - %d\'\n", i / n, i / n);
        continue;
      }        
    } 
    printf("\n");
    return 0;
}
