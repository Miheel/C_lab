#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Declaration_v2.h"
#pragma warning(disable:4996)

#pragma region View songlist(1)done
void viewSongList(Song * arr, int nrOfSongs)
{
	if(nrOfSongs<=0)
	{
		printf("it`s empty\n");
	}
	for (int i = 0; i < nrOfSongs; i++, arr++)
	{
		printf("Title: %s\n", arr->title);
		printf("Artist: %s\n", arr->artist);
		printf("Year: %d\n", arr->year);
		printf("\n");
	}
}
#pragma endregion

#pragma region Shuffle(2)Done
void shuffle(Song* arr, int nrOfSongs)
{
	for (int i = 0; i < nrOfSongs; i++)
	{
		int ls = 0, rs = 0;
		while (ls == rs)
		{
			ls = rand() % nrOfSongs;
			rs = rand() % nrOfSongs;
		}
		swap(&arr[ls], &arr[rs]);
	}
}
#pragma endregion

#pragma region Sort list(3)Done
void sort(Song * arr, int nrOfSongs)
{
	for (int i = 0; i < nrOfSongs; i++)
	{
		for (int j = 0; j < nrOfSongs; j++)
		{
			if (arr[i].year < arr[j].year)
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
}
#pragma endregion

#pragma region Add a song(4)Done
Song* addSongFunk(Song* arr, char title[], char artist[], int year, int *nrOfSongs)
{
	realloc(arr, ++*nrOfSongs * sizeof(Song));
	int i = 0;
	for (;title[i] != '\0'; i++)
	{
		arr[*nrOfSongs - 1].title[i] = title[i];
	}
	arr[*nrOfSongs - 1].title[i] = '\0';
	i = 0;
	for (;artist[i] != '\0'; i++)
	{
		arr[*nrOfSongs - 1].artist[i] = artist[i];
	}
	arr[*nrOfSongs - 1].artist[i] = '\0';
	arr[*nrOfSongs - 1].year = year;
	return arr;
}
#pragma endregion

#pragma region Save to file(5)Done
void saveToFile(Song* arr, int nrOfSongs)
{
	FILE *saveFileptr;
	saveFileptr = fopen("newSongList.txt", "w");
	fprintf(saveFileptr, "%d\n", nrOfSongs);
	int i = 0;
	while (i < nrOfSongs)
	{
		fprintf(saveFileptr, "%s\n%s\n%d\n", arr->title, arr->artist, arr->year);
		i++;
		arr++;
	}
	fclose(saveFileptr);
}
#pragma endregion

#pragma region Read From File(6)Done
Song* readFromFile(Song* arr, int *nrOfSongs)
{
	FILE *readFilefptr = fopen("SongList.txt", "r");
	char currChar = 0;
	fscanf(readFilefptr, "%d", nrOfSongs);
	fseek(readFilefptr, 2, SEEK_CUR);
	Song tmp;
	arr = (Song*)realloc(arr, *nrOfSongs * sizeof(Song));

	for (int j = 0; j < *nrOfSongs; j++)
	{
		int i = 0;
		for (; i < MAX && ((currChar = fgetc(readFilefptr)) != '\n'); i++)
		{
			tmp.title[i] = currChar;
		}
		tmp.title[i] = '\0';
		i = 0;
		for (; i < MAX && ((currChar = fgetc(readFilefptr)) != '\n'); i++)
		{
			tmp.artist[i] = currChar;
		}
		tmp.artist[i] = '\0';
		fscanf(readFilefptr, "%d", &tmp.year);
		arr[j] = tmp;
		getc(readFilefptr);
	}

	printf("\n");
	fclose(readFilefptr);
	return arr;
}
#pragma endregion

#pragma region swap
void swap(Song *arr1, Song *arr2)
{
	Song temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}
#pragma endregion