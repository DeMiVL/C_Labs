#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0;
    float x;

    printf("Enter x step for argument -> ");
    scanf("%f", &x);
    printf("DO WHILE CYCLE\n   x\t\tf(x)\n");
    do
    {
        printf("%f\t%f\n", a, exp(sin(a)));
        a += x;
    } 
    while (a <= 0.250001f);

    do
    {
        printf("%f\t%f\n", a, exp(a) - (1 / sqrt(a)));
        a += x;
    } 
    while (a <= 0.500001f);

    printf("Enter x step for argument -> ");
    scanf("%f", &x);
    printf("FOR CYCLE\n   x\t\tf(x)\n");
    for(int j = 0; j*x <= 0.500001f; j++)
    {
        if(j * x <= 0.250001f)
        {
            printf("%f\t%f\n", j*x, exp(sin(j*x)));
        }
        else
        {
            printf("%f\t%f\n", j*x, exp(j*x) - (1 / sqrt(j*x)));
        }
    }

    return 1;
}