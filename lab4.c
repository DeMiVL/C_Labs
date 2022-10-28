#include <stdio.h>
#include <math.h>

double	Func(double, double);

int main()
{
	double precision  = 1e-6;
	printf("\nEnter precision -> ");
    scanf("%lf", &precision);
	double a = 0.0, b = 0.5;
	double integral, integral2;
	int n = 2;
	do
	{
		integral2 	= integral;
		integral = 0.0;
		double step = (b - a) / n;
		double x    = a;
		for(int i   = 1; i <= n; i++)
		{
			integral  += step * Func((x + x + step) / 2, precision);
			x += step;
		}
		printf("%f %f %f\n", integral, integral2, fabs(integral2 - integral) / 3.0);
		n *= 2;
	}
	while(fabs(integral - integral2) / 3.0 >= precision);
	printf("Counted integral = %f\n", integral);
	return 0;
}

double	Func(double x, double precision)
{
    if (x - 0.25 < precision)
	    return exp(sin(x));
    else
	    return exp(x) - 1.0 / sqrt(x);
}