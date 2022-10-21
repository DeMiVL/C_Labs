#include <stdio.h>
#include <math.h>

double	Func(double);

double	Integration_Rect(double(*)(double), int, double, double);

int main()
{
	double precision = 1e-9;
	double a = 0, b = 0.5;
	double integral, integral2;
	int n = 2;
	do
	{
		integral = Integration_Rect(Func, n, a, b);
		integral2 = Integration_Rect(Func, 2 * n, a, b);
		printf("%f %f %f\n", integral, integral2, fabs(integral2 - integral) / 3);
		n += 2;
	}
	while(fabs(integral2 - integral) / 3 >= precision);
	printf("Counted integral = %f\n", integral2);
	return 0;
}

double	Func(double x)
{
    if (x <= 0.250001)
	    return exp(sin(x));
    else
	    return exp(x) - 1 / sqrt(x);
}

double	Integration_Rect(double(*f)(double), int amount, double left, double right)
{
	double step = (right - left) / amount;
	double sum = 0.0;
	double x = left;
	for(int i = 1; i <= amount; i++)
	{
		sum += step * f((x + x + step) / 2);
		x += step;
	}
	return sum;
}
