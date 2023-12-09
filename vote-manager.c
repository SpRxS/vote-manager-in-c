#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	SetConsoleTitle("Vote Manager for Sports-v0.1");
	system("color 04");
	
	char letter;
	int athletics = 0, swimming = 0, football = 0, badminton = 0;
	
	do
	{
		printf("--------------------|Vote Manager made by pRx|--------------------\n\n");
		printf("--|Type in the letter chosen or |Q| to finish or |OP| to options[BETA]:\n\n");
		printf("-|1 [A]: Athketics\n");
		printf("-|2 [S]: Swimming\n");
		printf("-|3 [F]: Football\n");
		printf("-|4 [B]: Badminton\n\n");
		printf("--|Enter the character you want to vote for (A, a): ");
		
		scanf(" %c", &letter);
		printf("\n");
		system("cls");
		
		if(letter == 'A' || letter == 'a')
			athletics = athletics + 1;
		
		else if(letter == 'S' || letter == 's')
			swimming = swimming + 1;
		
		else if(letter == 'F' || letter == 'f')
			football = football + 1;
		
		else if(letter == 'B' || letter == 'b')
			badminton = badminton + 1;
		
	} while(letter != 'Q' && letter != 'q');
	
	printf("\n-Athletics scored %d votes.\n", athletics);
	printf("-Swimming scored %d votes.\n", swimming);
	printf("-Football scored %d votes.\n", football);
	printf("-Badminton scored %d votes.\n\n", badminton);
	
	createFile(athletics, swimming, football, badminton);
}

void createFile(int x, int y, int z, int t)
{
	char txt;
	
	printf("--|NOTE| It will create the file in the folder where the program runs and set its name to (vote-manager.txt).\n\n-Do you want this data to be output as a file? -|Y|: YES |N|: NO(quit)-: ");
	scanf(" %c", &txt);
	
	FILE *fptr;
	
	if(txt == 'Y' || txt == 'y')
	{
		fptr = fopen("vote-manager.txt", "w");
		fprintf(fptr, "Athletics: %d\nSwimming: %d\nFootball: %d\nBadminton: %d", x, y, z, t);
	}
	else if(txt == 'N' || txt == 'n')
	{
		exit(0);
	}
}
