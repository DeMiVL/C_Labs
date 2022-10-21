#include <stdio.h>
#include <math.h>

int main()
{
    double a = 0.0;
    double precision = 1e-9;
    double x;

    printf("Enter x step for argument -> ");
    scanf("%lf", &x);
    printf("DO WHILE CYCLE\n   x\t\tf(x)\n");
    do
    {
        printf("%lf\t%lf\n", a, exp(sin(a)));
        a += x;
    }
    while ((a - 0.25 < precision));

    do
    {
        printf("%lf\t%lf\n", a, exp(a) - (1 / sqrt(a)));
        a += x;
    } 
    while (a - 0.5 < precision);

    printf("Enter x step for argument -> ");
    scanf("%lf", &x);
    printf("FOR CYCLE\n   x\t\tf(x)\n");
    for(int j = 0; j*x - 0.5 < precision; j++)
    {
        if(j * x - 0.25 < precision)
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