#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    printf("Enter x { -0.491022 < x < -0.286216}\n");
    printf("Enter x {  3.42781  < x <  3.63262 }\n");
    printf("Enter x {  0.156729 < x <  0.523599} -> ");
    scanf("%f", &x);
    if ((0.156729 < x && x < 0.523599) || (3.42781  < x && x <  3.63262) || (-0.491022< x && x <  -0.286216))
    {
        float y = acos(2 *sin(x));
        float z = sqrt(cos(pow(y, 2)));
        printf("y(x) = %f\nz(y) = %f\n", y, z);
    }
    else
        printf("x value is incorrect!\n");
    return 0;
}