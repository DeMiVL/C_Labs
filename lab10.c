#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fail()
{
    printf("Memory allocation failure!\n");
    exit(EXIT_FAILURE);
}

void Fill(int n, int m, int **a)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            {
                a[i][j] = rand () % 101 - 50;
            }
    }
}

int MaxInColumnMinInAll(int n, int m, int **a)
{
    int max = a[0][0], max2 = abs(a[0][0]) * 1000;
    for(int j = 0; j < m; j++)
    {
        max = a[0][j];
        for(int i = 0; i < n; i++)
        {
            if(a[i][j] > max)
                {
                    max = a[i][j];
                }
        }
        if(max < max2)
            max2 = max;
    }
    return max2;
}

int main()
{
    srand(time(NULL));
    int n, m;
    printf("n -> ");
    scanf("%d", &n);

    int **a = (int **)malloc(n * sizeof(int *));

    if (!a)
        fail();

    printf("m -> ");
    scanf("%d", &m);

    int i, j;
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
        if (!a[i])
            free(a);
            fail();
    }
    
    Fill(n, m, a);

    for(i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%4d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\n%4d\n", MaxInColumnMinInAll(n, m, a));

    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}
