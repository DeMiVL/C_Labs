#include <stdio.h>
#include <math.h>

int main()
{
    double a = 0;
    double x;

    printf("Enter x step for argument -> ");
    scanf("%lf", &x);
    printf("DO WHILE CYCLE\n   x\t\tf(x)\n");
    do
    {
        printf("%lf\t%lf\n", a, exp(sin(a)));
        a += x;
    } 
    while (a <= 0.250001f);

    do
    {
        printf("%lf\t%lf\n", a, exp(a) - (1 / sqrt(a)));
        a += x;
    } 
    while (a <= 0.500001);

    printf("Enter x step for argument -> ");
    scanf("%lf", &x);
    printf("FOR CYCLE\n   x\t\tf(x)\n");
    for(int j = 0; j*x <= 0.500001; j++)
    {
        if(j * x <= 0.250001)
        {
            printf("%lf\t%lf\n", j*x, exp(sin(j*x)));
        }
        else
        {
            printf("%lf\t%lf\n", j*x, exp(j*x) - (1 / sqrt(j*x)));
        }
    }

    return 1;
}