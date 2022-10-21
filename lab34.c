#include <stdio.h>
#include <math.h>

float	Func(float);

float	Integration_Rect(float(*)(float), int, float, float);

char RungeTest(float, float, float);

int main()
{
	float precision = .0000001;
	float a = 0, b = 0.5;
	float integral, Runge;
	int n = 2;
	do
	{
		integral = Integration_Rect(Func, n, a, b);
		Runge = Integration_Rect(Func, 2 * n, a, b);
		printf("%f %f %f\n", integral, Runge, fabs(Runge - integral) / 3);
		n += 2;
	}
	while(! RungeTest(integral, Runge, precision));
	printf("Counted integral = %f\n", Runge);
	return 0;
}

float	Func(float x)
{
    if (x <= 0.250001)
	    return exp(sin(x));
    else
	    return exp(x) - 1 / sqrt(x);
}

char RungeTest(float a, float b, float precision)
{
	if(fabs(a - b) / 3. < precision)
	{
		return 1;
	}
	return 0;
}

float	Integration_Rect(float(*f)(float), int amount, float left, float right)
{
	float step = (right - left) / amount;
	float sum = 0.0;
	float x = left;
	for(int i = 1; i <= amount; i++)
	{
		sum += step * f((x + x + step) / 2);
		x += step;
	}
	return sum;
}
