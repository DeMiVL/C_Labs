#include <stdio.h>
#include <math.h>

void Cycle(unsigned int n)
{
	if (n == 0)
	{
		printf("0");
		return;
	}
	unsigned digits = (int)log10(n);
	for (int i = digits; i >= 0; i--)
	{
		printf("%u", n / (unsigned)pow(10, i));
		n %= (unsigned)pow(10, i);
	}
}

void Recurse(unsigned int N)
{
    unsigned int r;
	static int g = 0;
    r = N % 10;
    if (N == 0) 
	{
		if (g == 0)
		{
			printf("%u", N);
		}
        return;
    }
	g++;
    Recurse(N / 10);
	g = 0;
    printf("%u", r);
}

int main()
{
	unsigned int a;
	printf("Input unsigned integer n\nn -> ");
    scanf("%u", &a);
	printf("Rec: ");
	Recurse(a);
	printf("\nCyc: ");
	Cycle(a);
	return 0;
}