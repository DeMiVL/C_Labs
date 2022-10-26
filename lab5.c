#include <stdio.h>
#include <math.h>

void Cycle(unsigned int n)
{
	if (n == 0)
	{
		printf("0");
		return;
	}
	unsigned short digits = (unsigned)log10(n);
	for (int i = digits; i >= 0; i--)
	{
		printf("%u", n / (unsigned )pow(10, i));
		n %= (unsigned )pow(10, i);
	}
}

void Recurse(unsigned int N)
{
    unsigned int r;   
    if (N == 0) 
	{
		printf("0");
        return;
    }
 	r = N % 10;
    Recurse(N / 10);
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
	printf("\n");
	return 0;
}