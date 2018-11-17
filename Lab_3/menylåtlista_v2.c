#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <crtdbg.h>  
#include "Declaration_v2.h"
#pragma warning(disable:4996)
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((int)time(NULL));
	int nrOfSongs = 0, menuSelect = 0, menuLoop = 0, year = 0;
	char title[20], artist[20];
	Song * song = (Song*)calloc(nrOfSongs, sizeof(Song));
	while (menuLoop < 5 && menuLoop != -1)
	{
		printf("View songlist (1),shuffle (2), Sort list (3), Add a song (4), Save to new list (5), Read from file(6)");
		scanf("%d", &menuSelect);
		getchar();
		switch (menuSelect)
		{

#pragma region View songlist(1)Done
		case 1:
			viewSongList(song, nrOfSongs);
			break;
#pragma endregion

#pragma region shuffle(2)
		case 2:
			shuffle(song, nrOfSongs);
			break;
#pragma endregion

#pragma region Sort list(3)
		case 3://sort list
			sort(song, nrOfSongs);
			break;
#pragma endregion

#pragma region Add a song(4)
		case 4:
			printf("Add A song\n");
			printf("Title Artist Year");
			scanf("%s%s%d", title, artist, &year);
			song = addSongFunk(song, title, artist, year, &nrOfSongs);
			break;
#pragma endregion

#pragma region Save to new list(5)Done
		case 5:
			saveToFile(song, nrOfSongs);
			break;
#pragma endregion

#pragma region Read from file(6)Done
		case 6:
			song = readFromFile(song, &nrOfSongs);
			break;
#pragma endregion

#pragma region exit
		case -1:
			menuLoop = -1;
			break;
#pragma endregion
		}
	}
	free(song);
	getchar();
	return 0;
}