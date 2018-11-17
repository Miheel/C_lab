#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#pragma warning(disable: 4996)

int main()
{
	srand((int)time(NULL));
	setlocale(LC_ALL, "swedish");
	int start = 0, ssp, pcWin = 0, humanWin = 0;
	char name[20];

	printf("Welcome to the game ”ROCK-PAPER-SCISSORS”!\n");

	printf("what is youre name (sven svensson):");
	fgets(name, 20, stdin);
	size_t ln = strlen(name) - 1;
	if (name[ln] == '\n')
	{
		name[ln] = '\0';
	}
	while (start == 0)
	{
		int rng = rand() % 3 + 1;
		printf("\n");
		printf("Sten(1), Sax(2), Påse(3) eller Exit(0): ");
		scanf("%d", &ssp);
		getchar();

		if (ssp == 1 || ssp == 2 || ssp == 3)
		{
			if (ssp == rng)
			{
				printf("It´s a draw\n");
				printf("You chose %d\n", ssp);
				//sten sten lika
				//sax sax lika
				//påse påse lika
			}
			else if (ssp == 1 && rng == 2 || ssp == 2 && rng == 3 || ssp == 3 && rng == 1)
			{
				printf("You win\n");
				printf("You chose %d\n", ssp);
				humanWin++;
				//sten0 vinner över sax1
				//sax1 vinner över påse2
				//påse2 vinner över sten0
			}
			else
			{
				printf("YOU LOSE!\n");
				printf("You chose %d\n", ssp);
				pcWin++;
			}
			if (rng == 1)
			{
				printf("The pc chose sten(%d)\n", rng);
			}
			else if (rng == 2)
			{
				printf("The pc chose sax(%d)\n", rng);
			}
			else
			{
				printf("The pc chose Påse(%d)\n", rng);
			}
		}
		else if (ssp == 0)
		{
			printf("PC: %d poäng\n%s: %d poäng\n", pcWin, name, humanWin);
			printf("Exit");
			start++;
		}
		else
		{
			printf("invalid input\n");
		}
	}
	getchar();
	return 0;
}