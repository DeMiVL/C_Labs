#include <stdio.h>
#include <math.h>

float Func(float x)
{
	if (x <= 0.250001)
		return exp(sin(x));
	else
		return (exp(x) - (1 / sqrt(x)));
}

short Runge(float N, float N_2, float eps)
{
	return (fabs(N_2 - N) / 3 < eps) ? 1 : 0;
}
//Контрольное значение интеграла: 0.23431
int main()
{
	float	eps;					// точность
	int		n			= 2;		// разбиение
	float	integral0	= 0.;		// интеграл с n разбиений
	float	integral	= 0.;		// интеграл с 2n разбиениями 
	float	step		= 0.;
	float	x			= 0.;
	printf("Input precision eps -> ");
    scanf("%0.6f", &eps);
	printf("Precision input <- %0.6f\n", eps);
   	
	while(1)
	{
		step = 0.5 / n;
		while(x <= 0.500001)
		{
			integral0	+= step * Func((x + x + step) / 2);
			x			+= step;
		}
		x = 0;
		step = 0.5 / (2 * n);
		while(x <= 0.500001)
		{
			integral	+= step * Func((x + x + step) / 2);
			x			+= step;
		}
		printf("Working %0.6f %0.6f %d\n", integral, integral0, n);
		if (Runge(integral0, integral, eps))
		{
		    //printf("Давай, давай, ура!!!!1");
		    break;
		}
		integral = 0;
		integral0 = 0;
		x = 0;
		n += 2;
	}
	printf("Counted integral value is: %0.6f\n", integral);
	return 0;
}