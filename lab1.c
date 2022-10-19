#include <stdio.h>

int			main()
{
    double	x, y, z, max; 

    printf	("Введите x:  ");
    scanf	("%lf",	&x);
    printf	("Введите y:  ");
    scanf	("%lf",	&y);
    printf	("Введите z:  ");
    scanf	("%lf",	&z);

	if (x >= y)
		if (x >= z)
			max = x;
		else
			max = z;
	else if (y >= z)
			max = y;
		else
			max = z;

	if (2 * max > x + y + z)
		printf("max(x, y, z) > sum(x, y, z) - 2 * max(x, y, z)\n\nmax(x, y,z ) = %lf", max);
	else
		printf("max(x, y, z) <= sum(x, y, z) - 2 * max(x, y, z)\n\nsum(x, y, z) - 2 max(x, y, z) = %lf\n", x + y + z - 2 * max);

    return	0;
}