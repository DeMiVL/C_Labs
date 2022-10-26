#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct PN  {int* P; int* N};

struct PN fill(int n, int* a, int* b, int *otr, int *neotr)
{
    struct PN am;
    for (int i = 0; i < n; i++)
    {
        int elem = rand () % 101 - 50;
        if (elem < 0)
        {
            a = (int*)realloc(a, (*otr + 1) * sizeof(int));
            a[*otr] = elem;
            *otr = *otr + 1;
        }
        else
        {
            b = (int*)realloc(b, (*neotr + 1) * sizeof(int));
            b[*neotr] = elem;
            *neotr = *neotr + 1;
        }
    }
    am.P = a;
    am.N = b;
    return am;
}

int main()
{
    srand(time(NULL));
    int n;
    printf("n -> ");
    scanf("%d", &n);
    int *P      = NULL;
    int *N      = NULL;
    int otr     = 0;
    int neotr   = 0;
    struct PN am;
    am = fill(n, P, N, &otr, &neotr);
    P = am.P;
    N = am.N;
    /*
    for (int i = 0; i < n; i++)
    {
        int elem = rand () % 101 - 50;
        if (elem < 0)
        {
            P = (int*)realloc(P, (otr + 1) * sizeof(int));
            P[otr] = elem;
            otr++;
        }
        else
        {
            N = (int*)realloc(N, (neotr + 1) * sizeof(int));
            N[neotr] = elem;
            neotr++;
        }
    }
    */
    if (otr > 0)
    {
        printf("P: ");
        for(int i = 0; i < otr; i++)
        {
            printf("%4d ", P[i]);
        }
    }
    free(P);

    if (neotr > 0)
    {
        printf("\nN: ");
        for(int i = 0; i < neotr; i++)
        {
            printf("%4d", N[i]);
        }
    }
    free(N);
    
    printf("\n");

    return 0;
}
