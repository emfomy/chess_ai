#include "stdafx.h"
#include "game.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	switch(Main())
	{
	case 1:
		system("cls");
		printf("NChess.dat error!!\n");
		break;
	case 2:
		system("cls");
		printf("Step.dat error!!\n");
		break;
	default:
		system("cls");
		printf("Goodbye~~\n");
	}
	_getch();
	return 0;
}

