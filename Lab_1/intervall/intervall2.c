#include <stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int i, b = 0;
	while (b == 0)
	{
		scanf("%d", &i);
		getchar();
		//intervall mindre eller lika med 15 eller st�rre �n 25
		if (i <= 15 || i > 25)
		{
			printf("valid %d\n", i);
		}
		else
		{
			printf("invalid%d\n", i);
		}
	}
	getchar();
	return 0;
}