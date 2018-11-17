#pragma once

#define MAX 128

typedef struct Song
{
	char title[MAX];
	char artist[MAX];
	int year;
}Song;

Song* addSongFunk(Song* arr, char title[], char artist[], int year, int *nrOfSongs);

void viewSongList(Song* arr, int nrOfSongs);

Song* readFromFile(Song* arr, int *nrOfSongs);

void shuffle(Song* arr, int nrOfSongs);

void saveToFile(Song* arr, int nrOfSongs);

void swap(Song* arr1, Song* arr2);

void sort(Song* arr, int nrOfSongs);