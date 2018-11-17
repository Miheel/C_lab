#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int i, a = 0;
	while (a == 0)
	{
		scanf("%d", &i);
		getchar();
		//interval mellan 15 till och med 24
		if (i >= 15 && i < 25)
		{
			printf("valid %d\n", i);
		}
		else
		{
			printf("invalid %d\n", i);
		}
	}
	getchar();
	return 0;
}