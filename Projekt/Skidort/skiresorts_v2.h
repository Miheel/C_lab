#ifndef SKIRESORT_H
#define SKIRESORT_H
#define CAP 128

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <crtdbg.h> 

#pragma warning(disable:4996)

typedef struct Booking
{
	char name[CAP];
	long long pNumber[8];
	int nrOfPersons;
	char cabinType[CAP];
	int cabinNr;
	long long leaseStart;
	long long leaseEnd;
	int nrOfSkiCardsAdult;
	int nrOfSkiCardsTeen;
	int nrOfSkiCardsChild;
	int cost;
}Booking;

void calculateCost(Booking *booking);

void calculateSkiCards(Booking *booking);

void showBooking(Booking booking);

struct Booking createBooking();

int isAvailable(Booking * booking, Booking tmp, int nrOfBookings);

void menu();

#endif // !SKIRESORT_H