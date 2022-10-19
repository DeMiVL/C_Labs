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
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    int *P = calloc(0, sizeof(int));
	int *N = calloc(0, sizeof(int));
    fill(n, A);
    int i;
	int	j, k;	/*	количество неотрицательных
					и отрицательных чисел соотвественно*/
    j = 0;
    k = 0;
    for (i = 0; i < n; i++)
    {
        //printf("%4d", A[i]);
        if (A[i] >= 0) 
        {
            j++;
            N = realloc(N, sizeof(int));
			N[j - 1] = A[i];
        }
        else
        {
            k++;
            P = realloc(P, sizeof(int));
			P[k - 1] = A[i];
        }
    }
   	
   // printf("\n%d - %d\n", j, k);
	/*
	for (i = 0; i < k; i++)
	{
        printf("%4d", P[i]);
	}
	
	printf("\n");
	
	for (i = 0; i < j; i++)
	{
        printf("%4d", N[i]);
	}
*/
    return 0;
}
