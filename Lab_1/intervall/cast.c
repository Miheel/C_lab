#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)

int main()
{
	int x, y;
	double z;
	printf("matain tv� heltal (1 2):");
	scanf("%d", &x);
	scanf("%d", &y);
	getchar();
	printf("%f", z = (double)x / y);
	getchar();
	return 0;
}