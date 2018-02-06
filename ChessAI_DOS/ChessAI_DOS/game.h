#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define NChess "RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr"

char Chess[8][8], string[8];
int iError, iwin, PStep(), CStep(), Print(), Loading();

int Main()
{
	iError = Loading();
	if(iError)
		return iError;
	while(1)
	{
		system("cls");
		printf("0)先手 1)後手 : ");
		switch(getche())
		{
		case '0':
			goto PFIRST;
			break;
		case '1':
			goto CFIRST;
			break;
		default:
			system("cls");
		}
	}
	
	while(1)
	{
		Print() ; 
PFIRST:
		PStep();
CFIRST:
		Print();
		printf("Thinking...");
		getch();
		CStep();
    }
	return 0;
}

int Loading()
{
	printf("Press Esc To Reset...\n");
	if(getch() == 27)
		system("rmdir Data /s /q");
	system("md Data");
	system("cls");
	FILE *fr, *fw;
	fw = fopen("Data\\NChess.dat", "w");
	if(fw)
	{
		fprintf(fw, NChess);
		fclose(fw);
	}
	fr = fopen("Data\\NChess.dat", "r");
		if(!fr)
			return 1;
	for(int j = 7; j >= 0; j--)
		for(int i = 0; i <= 7; i++)
			Chess[i][j] = fgetc(fr);
	fclose(fr);
}

int Print()
{
	system("cls");
	printf("    a   b   c   d   e   f   g   h\n");
	for(int j = 7; j >= 0; j--)
	{
		printf("  + - + - + - + - + - + - + - + - +  \n%d | ", j + 1);
		for(int i = 0; i <= 7; i++)
			printf("%c | ", Chess[i][j]);
		printf("\n");
	}
	printf("  + - + - + - + - + - + - + - + - +  \n\n");
	return 0;
}

int PStep()
{
	return 0;
}

int CStep()
{
	return 0;
}