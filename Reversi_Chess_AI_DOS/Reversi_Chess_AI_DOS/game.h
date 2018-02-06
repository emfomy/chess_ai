#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>

#define ProgramName "Reversi Chess PC DOS"
#define Designer "Emfo && Lbsn"	
#define Date "Wed.04/10/09"

#define maxsteps 10
#define totelsteps 100

using namespace std;

int Do(), iChess[totelsteps][8][8], iIChess[8][8][9], iCChess[64], iStep[totelsteps], is, itime;
bool Watch(), bPlayer[2], bp;
void IDo(int*, int*, int), Can(int, int*), Print(int), Printstep(int*, int);
char ch;

int Main()
{
start:
	system("cls");
	bp = 0, is = 0;
	for(int ix = 0; ix <= 7; ix++)
		for(int iy = 0; iy <= 7; iy++)
			iChess[0][ix][iy] = 0;
	iChess[0][3][3] = 1;
	iChess[0][3][4] = 2;
	iChess[0][4][3] = 2;
	iChess[0][4][4] = 1;

	cout << "Who Would Be ¡´ [Player(P) / Computer(C)]?";
	do
	{
		ch = getch();
		switch(ch)
		{
		case 'C':
		case 'c':
			bPlayer[0] = 0;
			break;
		case 'P':
		case 'p':
			bPlayer[0] = 1;
			break;
		default:
			continue;
		}
		cout << ch << '\n';
		break;
	}while(1);
	cout << "Who Would Be ¡³ [Player(P) / Computer(C)]?";
	do
	{
		ch = getch();
		switch(ch)
		{
		case 'C':
		case 'c':
			bPlayer[1] = 0;
			break;
		case 'P':
		case 'p':
			bPlayer[1] = 1;
			break;
		default:
			continue;
		}
		cout << ch << '\n';
		break;
	}while(1);
	cout << "Please Press Any Key To Start The Game....\n";
	ch = getch();

	do
	{
		switch(Do())
		{
		case 1:
			is--;
			continue;
		case 2:
			break;
		default:
			continue;
		}
		break;
	}while(1);

	do
	{
		Print(is);
		cout << "Please Press L To Leave The Game....\n";
		cout << "Please Press S To Start The Game....\n";
		if(bp) cout << "Please Press W To Watch The Game....\n";
		ch = getche();
		switch(ch)
		{
		case 'L':
		case 'l':
			return 0;
		case 'S':
		case 's':
			goto start;
		case 'W':
		case 'w':
			if(bp)
				Watch();
		}
	}while(1);
}

int Do()
{
	int ix, iy, iz, it = is % 2 + 1, ic = 0;
	for(ix = 0; ix <= 7; ix++)
		for(iy = 0; iy <= 7; iy++)
			for(int i = 0; i <= 8; i++)
				iIChess[ix][iy][i] = 0;
	for(int i = 0; i <= 63; i++)
		iCChess[i] = 99;

	Can(is, &ic);

	iStep[is + 1] = 100 * it + 88;
	if(!ic)
	{
		if(!bp)
		{
			do
			{
				Print(is);
				cout << "Please Press U To Undo This Step....\n";
				cout << "Please Press E To Exit This Play....\n";
				cout << "Please Press Any Key To Continue....\n";
				ch = getche();
				switch(ch)
				{
				case 'U':
				case 'u':
					if(is)
						return 1;
					else
						continue;
				case 'E':
				case 'e':
					return 2;
				default:
					bp = 1;
					is++;
					for(int i = 0; i <= 7; i++)
						for(int j = 0; j <= 7; j++)
							iChess[is][i][j] = iChess[is - 1][i][j];
					return 0;
				}
				break;
			}while(1);
		}
		else
		{
			iStep[is] = 99;
			return 2;
		}
	}
	bp = 0;
	if(bPlayer[it - 1])
	{
		do
		{
			Print(is);
			cout << "Please Press U To Undo This Step....\n";
			cout << "Please Press E To Exit This Play....\n";
			cout << "Please Input The Position You Want :\n";
			ch = getche();
			switch(ch)
			{
			case 'U':
			case 'u':
				if(is)
					return 1;
				else
					continue;
			case 'E':
			case 'e':
				return 2;
			case 48:
			case 49:
			case 50:
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
				ix = ch - 48;
				break;
			default:
				continue;
			}
			ch = getche();
			switch(ch)
			{
			case 'U':
			case 'u':
				if(is)
					return 1;
				else
					continue;
			case 'E':
			case 'e':
				return 2;
			case 48:
			case 49:
			case 50:
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
				iy = ch - 48;
				break;
			default:
				continue;
			}
		}while(iChess[is][ix][iy] >= 0);
	}
	else
	{
		do
		{
			Print(is);
			cout << "Please Press U To Undo This Step....\n";
			cout << "Please Press E To Exit This Play....\n";
			cout << "Please Press Any Key To Continue....\n";
			ch = getche();
			switch(ch)
			{
			case 'U':
			case 'u':
				if(is)
					return 1;
				else
					continue;
				break;
			case 'E':
			case 'e':
				return 2;
			default:
				IDo(&ix, &iy, ic);
			}
			break;
		}while(1);
	}

	is++;
	for(int i = 0; i <= 7; i++)
		for(int j = 0; j <= 7; j++)
			if(iChess[is - 1][i][j] >= 0)
				iChess[is][i][j] = iChess[is - 1][i][j];
			else
				iChess[is][i][j] = 0;
	iStep[is] = 100 * it + 10 * ix + iy;
	iChess[is][ix][iy] = it;
	for(iz = 0; iz <= 8; iz++)
		for(int i = 1; i < iIChess[ix][iy][iz]; i++)
			iChess[is][ix + i * (iz / 3 - 1)][iy + i * (iz % 3 - 1)] = it;
	return 0;
}

void IDo(int *ix, int *iy, int ic)
{
	int iz;
	itime = (int)time(NULL);
	do
	{
		srand(itime++);
		iz = iCChess[rand() % ic];
		*ix = iz / 10;
		*iy = iz % 10;
	}while(iChess[is][*ix][*iy] >= 0);
}

void Can(int in, int *ic)
{
	int ix, iy, iz, it = in % 2 + 1;
	for(ix = 0; ix <= 7; ix++)
		for(iy = 0; iy <= 7; iy++)
			if(iChess[is][ix][iy] <= 0)
				for(iz = 0; iz <= 8; iz++)
					for(int i = 1; ix + i * (iz / 3 - 1) >= 0 && ix + i * (iz / 3 - 1) <= 7 && iy + i * (iz % 3 - 1) >= 0 && iy + i * (iz % 3 - 1) <= 7; i++)
						if(iChess[is][ix + i * (iz / 3 - 1)][iy + i * (iz % 3 - 1)] > 0)
						{
							if(iChess[is][ix + i * (iz / 3 - 1)][iy + i * (iz % 3 - 1)] == it)
							{
								if(i == 1)
									break;
								iChess[is][ix][iy] = -1;
								iIChess[ix][iy][iz] = i;
								iCChess[(*ic)++] = 10 * ix + iy;
								break;
							}
						}
						else
							break;
}

bool Watch()
{
	for(int in = 0; in < is; in++)
	{
		Print(in);
		cout << "Please Press U To Undo This Step....\n";
		cout << "Please Press E To Exit This Play....\n";
		cout << "Please Press Any Key To Continue....\n";
		ch = getche();
		switch(ch)
		{
		case 'U':
		case 'u':
			if(in)
				in -= 2;
			else
				in--;
			break;
		case 'E':
		case 'e':
			return 0;
		}
	}
	return 0;
}

void Print(int in)
{
	system("cls");
	int ib = 0, iw = 0, im = 1;
	for(int ix = 0; ix <= 7; ix++)
		for(int iy = 0; iy <= 7; iy++)
			switch(iChess[in][ix][iy])
			{
			case 1:
				ib++;
				break;
			case 2:
				iw++;
				break;
			}
	if(iStep[in] == 99)
		if(ib > iw)
			cout << "¡³" << "Win!";
		else if(ib < iw)
			cout << "¡´" << "Win!";
		else
			cout << "Draw";
	else
		switch(iStep[in + 1] / 100 % 10)
		{
		case 1:
			cout << "¡³";
			break;
		case 2:
			cout << "¡´";
			break;
		}
	cout << "\11\11¡³:" << ib << "\11¡´:" << iw << "\11\11¢x    ¡³    ¡´    ¡³    ¡´    ¡³    ¡´\n";
	cout << "¡@¡@¢¯¡@¢°¡@¢±¡@¢²¡@¢³¡@¢´¡@¢µ¡@¢¶¡@\11¢x";
	Printstep(&im, in);
	cout << "\n¡@¢z¢w¢s¢w¢s¢w¢s¢w¢s¢w¢s¢w¢s¢w¢s¢w¢{\11¢x";
	Printstep(&im, in);
	for(int iy = 7; iy >= 0; iy--)
	{
		cout << '\n' << (char)162 << (char)(175 + iy) << "¢x";
		for(int ix = 0; ix <= 7; ix++)
			switch(iChess[in][ix][iy])
			{
			case 1:
				cout << "¡³¢x";
				break;
			case 2:
				cout << "¡´¢x";
				break;
			case -1:
				cout << "¡E¢x";
				break;
			default:
				cout << "¡@¢x";
			}
		cout << (char)162 << (char)(175 + iy) << "\11¢x";
		Printstep(&im, in);
		if(iy)
		{
			cout << "\n¡@¢u¢w¢q¢w¢q¢w¢q¢w¢q¢w¢q¢w¢q¢w¢q¢w¢t\11¢x";
			Printstep(&im, in);
		}
	}
	cout << "\n¡@¢|¢w¢r¢w¢r¢w¢r¢w¢r¢w¢r¢w¢r¢w¢r¢w¢}\11¢x";
	Printstep(&im, in);
	cout << "\n¡@¡@¢¯¡@¢°¡@¢±¡@¢²¡@¢³¡@¢´¡@¢µ¡@¢¶¡@\11¢x\n";
}

void Printstep(int *im, int in)
{
	for(int i = 0, j = 1; i < 6 && *im <= in;i++, ++*im)
	{
		if(iStep[*im] != 99)
		{
			cout << " -> ";
			if(iStep[*im] % 100 == 88)
					cout << "**";
			else
				cout << iStep[*im] / 10 % 10 << iStep[*im] % 10;
		}
		if(iStep[*im + 1] == 99)
			cout << '!';
	}
}