#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Fill(int n, int a[])
{
    int i;
    int otr = 0;
    for (i = 0; i < n; i++)
    {
        a[i] = rand () % 101 - 50;
        if (a[i] < 0)
            otr++;
    }
    return otr;
}

void UltraFill(int n, int A[], int P[], int N[])
{
    int i = 0;
    int otr = 0;
    for(i = 0; i < n; i++)
    {
        if(A[i] < 0)
        {
            P[otr] = A[i];
            otr++;
        }
        else if(A[i] >= 0)
        {
            N[i - otr] = A[i];
        }
    }
}

int main()
{
    srand(time(NULL));
    int n;
    int otr = 0;
    printf("n -> ");
    scanf("%d", &n);
    
    int A[n];

    otr = Fill(n, A);

    int i;
    printf("\nA: ");
    for (i = 0; i < n; i++)
    {
        printf("%4d", A[i]);
    }

    if(otr == n)
    {
        printf("\nNo non-negative elements\nP: ");
        for(i = 0; i < n; i++)
        {
            printf("%4d\t", A[i]);
        }
        return 1;
    }

    if(otr == 0)
    {
        printf("\nNo negative elements\nN: ");
        for(i = 0; i < n; i++)
        {
            printf("%4d\t", A[i]);
        }
        return 2;
    }

    int P[otr];
    int N[n - otr];

    UltraFill(n, A, P, N);

    printf("\n\nN: ");
    for(i = 0; i < otr; i++)
    {
        printf("%4d\t", P[i]);
     }

    printf("\n\nP: ");
    for(i = 0; i < n - otr; i++)
    {
        printf("%4d\t", N[i]);
    }

    printf("\n");
    return 0;
}
