#include "skiresorts_v2.h"
#pragma warning(disable:4996)
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
void calculateCost(Booking * booking)
{
	int leasetime = booking->leaseEnd % 100 - booking->leaseStart % 100;
	for (int i = 0; i < leasetime; i++)
	{
		if (booking->cabinNr >= 1 && booking->cabinNr <= 16)
		{
			booking->cost += 2800;
		}
		else if (booking->cabinNr >= 17 && booking->cabinNr <= 26)
		{
			booking->cost += 5600;
		}
		else if (booking->cabinNr >= 27 && booking->cabinNr <= 30)
		{
			booking->cost += 11200;
		}
		for (int i = 0; i < booking->nrOfSkiCardsAdult; i++)
		{
			booking->cost += 1500;
		}
		for (int i = 0; i < booking->nrOfSkiCardsTeen; i++)
		{
			booking->cost += 800;
		}
		for (int i = 0; i < booking->nrOfSkiCardsChild; i++)
		{
			booking->cost += 0;
		}
	}
}

void calculateSkiCards(Booking *booking)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	long long year = 0;
	long long age = 0;
	for (int i = 0; i < booking->nrOfPersons; i++)
	{
		year = booking->pNumber[i] / 100000000;
		age = tm.tm_year + 1900 - year;
		if (age <= 7 && age >= 0)
		{
			booking->nrOfSkiCardsChild++;
		}
		else if (age <= 15 && age > 7)
		{
			booking->nrOfSkiCardsTeen++;
		}
		else if (age > 15)
		{
			booking->nrOfSkiCardsAdult++;
		}
	}
}

void showBooking(Booking booking)
{
	printf("\n");
	printf("Name: %s\n", booking.name);
	printf("cabinType: %s\n", booking.cabinType);
	printf("cabinNr: %d\n", booking.cabinNr);
	printf("Startyear: %I64d and week: %I64d\n", booking.leaseStart % 1000000 / 100, booking.leaseStart % 100);
	printf("EndYear: %I64d and Week: %I64d\n", booking.leaseEnd % 1000000 / 100, booking.leaseEnd % 100);
	printf("nrOfSkiCards: Adults: %d\nTeens: %d\nChildren: %d\n", booking.nrOfSkiCardsAdult, booking.nrOfSkiCardsTeen, booking.nrOfSkiCardsChild);
	printf("cost: %d sek\n", booking.cost);
	for (int i = 0; i < booking.nrOfPersons; i++)
	{
		printf("Person %d: %I64d\n", i + 1, booking.pNumber[i]);
	}
	printf("\n");
}

Booking createBooking()
{
#pragma region var
	int cabinNr = 0, nrOfPersons = 0;
	int nrOfSkiCardsAdult = 0, nrOfSkiCardsTeen = 0, nrOfSkiCardsChild = 0, cost = 0;
	int flag1pNumber = 0, flag2pNumber = 0, flagCabin = 0, flag1lease = 0, flag2lease = 0;
	long long pNumber[8] = { 0 }, leaseStart = 0, leaseEnd = 0;
	char cabinType[3][CAP] = { "Ekonony", "Luxury", "business" }, name[CAP] = { 0 }, yn = 0;
	Booking booking = { 0 };
#pragma endregion

#pragma region Lease	
	printf("What time of do you wish to rent a cabbin year week\n");
	while (flag1lease != -1)
	{
		printf("Start time YYYYWW:");
		scanf("%I64d", &leaseStart);
		getchar();
		if (leaseStart % 100 > 52)
		{
			printf("Wrong format\n");
		}
		else
		{
			flag1lease = -1;
		}
	}
	while (flag2lease != -1)
	{
		printf("End time YYYYWW: ");
		scanf("%I64d", &leaseEnd);
		getchar();
		if (leaseEnd % 100 > 52)
		{
			printf("Wrong format\n");
		}
		else
		{
			flag2lease = -1;
		}
	}
#pragma endregion

#pragma region Cabin
	printf("|what type of cabbin and address				 |\n");
	printf("| cabbin nr	| cabin type	| Nr of cabbins	| Price Pre week |\n| 1-16		| Ekonony	| 16		| 2800 kr	 |\n| 17-26		| Luxury	| 10		| 5600 kr	 |\n| 18-30		| business	| 4 		| 11200 kr	 |\n");

	while (flagCabin != -1)
	{
		printf("Addres of the cabin you wish to rent: ");
		scanf("%d", &cabinNr);
		getchar();
		if (cabinNr >= 1 && cabinNr <= 30)
		{
			flagCabin = -1;
		}
		else
		{
			printf("That cabin does not exist!\n");
		}
	}
#pragma endregion

#pragma region social security number
	printf("Provide the social security number for all who is staying in the cabin, the max limit is eight persons in each cabin\n");

	for (int i = 0; i < 8 && flag1pNumber != -1; i++)
	{
		printf("Add person (y/n)\n");
		scanf("%c", &yn);
		getchar();
		if (yn == 'y')
		{
			flag2pNumber = 0;
			while (flag2pNumber != -1)
			{
				printf("%d: YYYYMMDDXXXX", nrOfPersons + 1);
				scanf("%I64d", &pNumber[i]);
				getchar();
				if (pNumber[i] % 1000000 / 10000 > 31 || pNumber[i] % 100000000 / 1000000 > 12)
				{
					printf("Wrong format");
				}
				else
				{
					flag2pNumber = -1;
					nrOfPersons++;
				}
			}
		}
		else if (yn == 'n')
		{
			flag1pNumber = -1;
			printf("stop\n");
		}
		else if (yn != 'n'&&yn != 'y')
		{
			printf("ERROR\n");
		}
	}
#pragma endregion

#pragma region booking person
	printf("Name on the person booking firstname lastname:");
	fgets(name, CAP, stdin);
#pragma endregion

#pragma region Assignment to struct
	booking.leaseStart = leaseStart;
	booking.leaseEnd = leaseEnd;
	booking.cabinNr = cabinNr;
	booking.nrOfPersons = nrOfPersons;
	booking.nrOfSkiCardsAdult = nrOfSkiCardsAdult;
	booking.nrOfSkiCardsChild = nrOfSkiCardsChild;
	booking.nrOfSkiCardsTeen = nrOfSkiCardsTeen;
	booking.cost = cost;
	int i = 0;
	for (; name[i] != '\0'; i++)
	{
		booking.name[i] = name[i];
	}
	booking.name[i] = '\0';
	for (; name[i] != '\0'; i++)
	{
		booking.name[i] = name[i];
	}
	booking.name[i] = '\0';

	i = 0;
	for (; name[i] != '\0'; i++)
	{
		booking.name[i] = name[i];
	}
	booking.name[i] = '\0';

	i = 0;
	for (; i < nrOfPersons; i++)
	{
		booking.pNumber[i] = pNumber[i];
	}

#pragma region Assignment of cabin
	if (booking.cabinNr >= 1 && booking.cabinNr <= 16)
	{
		i = 0;

		for (; cabinType[0][i] != '\0'; i++)
		{
			booking.cabinType[i] = cabinType[0][i];
		}
		booking.cabinType[i] = '\0';
	}

	else if (booking.cabinNr >= 17 && booking.cabinNr <= 26)
	{
		i = 0;
		for (; cabinType[1][i] != '\0'; i++)
		{
			booking.cabinType[i] = cabinType[1][i];
		}
		booking.cabinType[i] = '\0';
	}

	else if (booking.cabinNr >= 27 && booking.cabinNr <= 30)
	{
		i = 0;
		for (; cabinType[2][i] != '\0'; i++)
		{
			booking.cabinType[i] = cabinType[2][i];
		}
		booking.cabinType[i] = '\0';
	}
#pragma endregion
	calculateSkiCards(&booking);
	calculateCost(&booking);

#pragma endregion

	return booking;
}

int isAvailable(Booking * booking, Booking tmp, int nrOfBookings)
{
	int avilable = 1;
	for (int i = 0; i < nrOfBookings; i++)
	{
		if (tmp.cabinNr == booking[i].cabinNr && (tmp.leaseStart == booking[i].leaseStart || tmp.leaseEnd >= booking[i].leaseStart && tmp.leaseEnd <= booking[i].leaseEnd && tmp.leaseStart >= booking[i].leaseStart && tmp.leaseStart <= booking[i].leaseEnd || tmp.leaseStart <= booking[i].leaseStart && tmp.leaseEnd >= booking[i].leaseEnd || tmp.leaseStart <= booking[i].leaseStart && tmp.leaseEnd >= booking[i].leaseStart	&& tmp.leaseEnd <= booking[i].leaseEnd || tmp.leaseStart >= booking[i].leaseStart && tmp.leaseStart <= booking[i].leaseEnd && tmp.leaseEnd >= booking[i].leaseEnd))
		{
			avilable = 0;
		}
	}
	return avilable;
}

void menu()
{
	int menuSelect = 0, menuLoop = 0;
	int nrOfBookings = 0, choise = 0, finalise = 0, availableFlag = 0;
	Booking* arr = (Booking*)calloc(nrOfBookings, sizeof(Booking));
	Booking tmp = { 0 };
	
	while (menuLoop < 5 && menuLoop != -1)
	{
		printf("View booking (1), Create Booking (2) or Exit(-1)");
		scanf("%d", &menuSelect);
		printf("\n");
		getchar();
		switch (menuSelect)
		{
		case 1:
#pragma region Show booking

			if (nrOfBookings <= 0)
			{
				printf("it`s empty\n");
			}
			else if (nrOfBookings > 0)
			{
				printf("Bookinf nr: %d\n", nrOfBookings);
				showBooking(arr[nrOfBookings - 1]);
			}

#pragma endregion
			break;

		case 2:
#pragma region Create booking
			arr = (Booking*)realloc(arr, ++nrOfBookings * sizeof(Booking));
			printf("welcome\nDo you wish to create a booking (1) or get a Quotation (2).\n");
			scanf("%d", &choise);
			getchar();
			do
			{
				tmp = createBooking();
#pragma region Available
				if (isAvailable(arr, tmp, nrOfBookings) == 0)
				{
					printf("The Chosen cabin and start- and end date overlap with an already existing booking");
					printf("Please choose another cabin or a different date");
					availableFlag = 0;
				}
				else
				{
					availableFlag = 1;
				}
#pragma endregion

			} while (availableFlag == 0);

#pragma region finalise
			if (choise == 1)
			{

				printf("Congratulations you've successfully made the following booking\n");
				arr[nrOfBookings - 1] = tmp;
				showBooking(arr[nrOfBookings - 1]);

			}
			else if (choise == 2)
			{

				printf("The cast of the booking: %d\n", tmp.cost);
				printf("finalise booking (1) or remove (2)");
				scanf("%d", &finalise);
				if (finalise == 1)
				{
					printf("Congratulations you've successfully made the following booking\n");
					arr[nrOfBookings - 1] = tmp;
					showBooking(arr[nrOfBookings - 1]);
				}
				else if (finalise == 2)
				{
					printf("opt out of booking\n");
					nrOfBookings--;
				}
			}
#pragma endregion

#pragma endregion
			break;

		case -1:
			menuLoop = -1;
			break;
		}
	}
	free(arr);
}