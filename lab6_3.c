#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () % 101 - 50;
}

int main()
{
    srand(time(NULL));
    int n;
    int otr = 0, neotr = 0;
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%4d", A[i]);
        if (A[i] < 0)
            otr++;
        else
            neotr++;
    }
    int P[otr];
    int N[n - otr];
    otr = 0; neotr = 0;
    for(i = 0; i < n; i++)
    {
        if(A[i] < 0)
        {
            P[otr] = A[i];
            otr++;
        }
        else if(A[i] >= 0)
        {
            N[neotr] = A[i];
            neotr++;
        }
    }
    printf("\nP: ");
    for(i = 0; i < otr; i++)
    {
        printf("%4d\t", P[i]);
    }
    printf("\nN: ");
        for(i = 0; i < neotr; i++)
    {
        printf("%4d\t", N[i]);
    }

    printf("\n");
    return 0;
}
