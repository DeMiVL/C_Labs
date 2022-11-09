#include <termios.h>
#include <stdio.h>

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

int main()
{
    int  i = 0;
    int  n = 0;
    while(1)
    {
      char c = getch();;
      if(c == 27)
      {
        c = getch();
        if (c == 79)
        {
          c = getch();
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
          c = getch();
          if (c == 65 || c == 66 || c == 67 || c == 68 || c == 70 || c == 72)
          {
            continue;
          }
          c = getch();
          if (c == 126) continue;
          c = getch();
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
