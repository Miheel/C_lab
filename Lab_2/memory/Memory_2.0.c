#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)
#define YTILE 4
#define XTILE 5
void shuffle(int arr[], int arrSize);
void printCards(int arr[], int taken[], int arrSize);
int main()
{
	int cards[] = { 0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9 };
	int flipped[20];
	int play = 1, sum = 0, tries = 0, xAxis1 = 0, xAxis2 = 0, yAxis1 = 0, yAxis2 = 0, choice1, choice2;
	shuffle(cards, 20);
	//Fills the Array with 20 Zeros
	for (int i = 0; i < 20; i++)
	{
		flipped[i] = 0;
	}
#pragma region controll
	////See how the flipped Array looks
	//for (int i = 0; i < 20; i++)
	//{
	//	printf("%d: ", flipped[i]);
	//}
	//printf("\n");
	////See how the cards array looks
	//for (int i = 0; i < 20; i++)
	//{
	//	printf("%d: ", cards[i]);
	//}
	//printf("\n");
#pragma endregion
	printf("Welcome to memory\n");
	printCards(cards, flipped, 20);
	while (play >= 1)
	{
#pragma region Choice of card
		//	The loops determines if the chosen cards are in the bounds of the game.
		//	The same goes for the if statements.
		//	If any of them are triggered the card are out of bounds.
		//	The loop will start over with the chioce of card.
		printf("Choose two coordinates on the board separated by space or <return>s\n");
		do
		{
			printf("Choose a card1 (x y): ");
			scanf("%d%d", &xAxis1, &yAxis1);
			choice1 = yAxis1 * 5 + xAxis1;
			if (xAxis1 > 4 || yAxis1 > 3 || xAxis1 < 0 || yAxis1 < 0)
			{
				printf("Invalid input. The chosen card is out of bounds.\n\n");
			}
			else if (flipped[choice1] > 0)
			{
				printf("Invalid input. You can't pick a card that is already taken.\n\n");
			}
		} while (xAxis1 > 4 || yAxis1 > 3 || xAxis1 < 0 || yAxis1 < 0 || flipped[choice1] > 0);
		do
		{
			printf("Choose a card2 (x y): ");
			scanf("%d%d", &xAxis2, &yAxis2);
			choice2 = yAxis2 * 5 + xAxis2;
			if (xAxis2 > 4 || yAxis2 > 3 || xAxis2 < 0 || yAxis2 < 0)
			{
				printf("Invalid input. The chosen card is out of bounds.\n\n");
			}
			else if (flipped[choice2] > 0)
			{
				printf("Invalid input. You can't pick a card that is already taken.\n\n");
			}
			else if (yAxis1 == yAxis2 && xAxis1 == xAxis2)
			{
				printf("Invalid input. You can't pick the same card.\n\n");
			}
		} while (xAxis2 > 4 || yAxis2 > 3 || xAxis2 < 0 || yAxis2 < 0 || flipped[choice2] > 0 || yAxis1 == yAxis2 && xAxis1 == xAxis2);
#pragma endregion

#pragma region chosen cards
		//	spells out the chosen cards
		printf("Card1: %d\n", cards[choice1]);
		printf("Card2: %d\n\n", cards[choice2]);
#pragma endregion

#pragma region Equal card or not
		//	determines if two cards are equal or not.
		//	if they are continue with the game
		//	if not choose a new set of cards.
		if (cards[choice1] == cards[choice2])
		{
			flipped[choice1] = 1;
			flipped[choice2] = 1;
			printCards(cards, flipped, 20);
			tries++;
		}
		else if (cards[choice1] != cards[choice2])
		{
			printf("The cards were not equal. Try again.\n");
			tries++;
		}
#pragma endregion

#pragma region controll
		//See how the flipped Array looks after input
		/*for (int i = 0; i < 20; i++)
		{
			printf("%d: ", flipped[i]);
		}*/
		printf("\n");
#pragma endregion		

#pragma region Full board or not
		//	checks if all the cards have been uncovered 
		//	calculates the sum of array flipped
		//	if the total sum of all elements in flipped is 20
		//	all cards have a pair, end the game
		for (int i = 0; i < 20; i++)
		{
			sum += flipped[i];
		}
#pragma region controll 
		//flipp sum
		//printf("sum is %d:\n", sum);
#pragma endregion
		if (sum == 20)
		{
			printf("Conglaturation!! You completed the board\n");
			play = 0;
		}
		sum = 0;
#pragma endregion
	}
	printf("It took you %d tries to complete the board.\n", tries);
	printf("End Game.\n");
	system("PAUSE");
	return 0;
}
void shuffle(int arr[], int arrSize)
{
	srand((int)time(NULL));
	int temp;
	for (int i = 0; i < arrSize - 1; i++)
	{
		size_t j = rand() % 20;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
void printCards(int arr[], int taken[], int arrSize)
{
	int k = 0, a = 0;
	printf("%c%c", ' ', '|');
	for (int i = 0; i < XTILE; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	printf("-|----------------\n");
	for (int i = 0; i < YTILE; i++)
	{
		printf("%d%c", i, '|');
		for (int i = 0; i < XTILE; i++)
		{
			if (taken[k] == 1)//ska vara 1
			{
				printf("%3d", arr[k]);
			}
			else
			{
				printf("%3c", '*');
			}
			k++;
		}
		printf("\n");
	}
}
//rita ut spelplanen
//låt spelaren välja två brickor
//vänd på brickorna 
//ta reda på om brikorna är lika eller inte 
//är brickorna lika rita ut spelplanen med de funna paret 
//är brikorna inte lika fråga igen
//rita ut spelplanen men tagna par efter som de blir funna