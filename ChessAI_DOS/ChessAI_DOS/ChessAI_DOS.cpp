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
		printf("NChess.dat error!!\n");
		break;
	}
	getch();
	return 0;
}

