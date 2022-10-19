#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    printf("Enter x { -0.491022 < x < -0.286216}\n");
    printf("Enter x {  3.42781  < x <  3.63262 }\n");
    printf("Enter x {  0.156729 < x <  0.523599} -> ");
    scanf("%lf", &x);
    if ((0.156729 < x && x < 0.523599) || (3.42781  < x && x <  3.63262) || (-0.491022< x && x <  -0.286216))
    {
        double y = acos(2 *sin(x));
        double z = sqrt(cos(pow(y, 2)));
        printf("y(x) = %lf\nz(y) = %lf\n", y, z);
    }//fsadfgdsgsgs
    else
        printf("x value is incorrect!\n");
    return 0;
}