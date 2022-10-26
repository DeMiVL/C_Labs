#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Fill(int n, int m, int (*a)[m])
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

int MaxInColumnMinInAll(int n, int m, int (*a)[m])
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
    printf("m -> ");
    scanf("%d", &m);
    int A[n][m];

    Fill(n, m, A);

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%4d\t", A[i][j]);
        }
        printf("\n");
    }


    printf("\n%4d\n", MaxInColumnMinInAll(n, m, A));
    return 0;

}
