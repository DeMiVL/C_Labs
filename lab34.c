#include <stdio.h>
#include <math.h>

double	Func(double, double);

int main()
{
	double precision = 1e-6;
	double a = 0, b = 0.5;
	double integral, integral2;
	int n = 2;
	do
	{
		integral = 0.0;
		integral2 = 0.0;
		double step = (b - a) / n;
		double x = a;
		for(int i = 1; i <= n; i++)
		{
			integral += step * Func((x + x + step) / 2, precision);
			integral2 += (step / 2) * Func((x + x + step / 2) / 2, precision);
			integral2 += (step / 2) * Func((x + x + step / 2 + step) / 2, precision);
			x += step;
		}
		printf("%f %f %f\n", integral, integral2, fabs(integral2 - integral) / 3);
		n += 2;
	}
	while(fabs(integral - integral2) / 3. >= precision);
	printf("Counted integral = %f\n", integral2);
	return 0;
}

double	Func(double x, double precision)
{
    if (x - 0.25 < precision)
	    return exp(sin(x));
    else
	    return exp(x) - 1 / sqrt(x);
}