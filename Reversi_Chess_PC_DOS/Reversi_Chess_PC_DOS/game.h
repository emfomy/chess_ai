#include "stdafx.h"
#include <iostream>
#include <conio.h>

#define ProgramName "Reversi Chess PC DOS"
#define Designer "Emfo && Lbsn"	
#define Date "Wed.04/08/09"

using namespace std;

int Do(), iChess[80][8][8], iIChess[8][8][9], iStep[80], is;
bool Watch(), bp;
void Print(int), Printstep(int*, int);
char ch;

int Main()
{
start:
	bp = 0, is = 0;
	for(int ix = 0; ix <= 7; ix++)
		for(int iy = 0; iy <= 7; iy++)
			iChess[0][ix][iy] = 0;
	iChess[0][3][3] = 1;
	iChess[0][3][4] = 2;
	iChess[0][4][3] = 2;
	iChess[0][4][4] = 1;
	while(1)
	{
		switch(Do())
		{
		case 1:
			is--;
			continue;
		case 2:
			goto end;
		}
	}
end:
	Print(is);
	cout << "Please Press L To Leave The Game....\n";
	cout << "Please Press S To Start The Game....\n";
	if(bp) cout << "Please Press W To Watch The Game....\n";
	ch = getch();
	if(ch == 'L' || ch == 'l')
		return 0;
	else if(ch == 'S' || ch == 's')
		goto start;
	else if(bp && (ch == 'W' || ch == 'w'))
		Watch();
	goto end;
}

int Do()
{
	int ix, iy, it = is % 2 + 1;
	bool bpause = 0;
	for(ix = 0; ix <= 7; ix++)
		for(iy = 0; iy <= 7; iy++)
			for(int i = 0; i <= 8; i++)
				iIChess[ix][iy][i] = 0;

	for(ix = 0; ix <= 7; ix++)
		for(iy = 0; iy <= 7; iy++)
			if(iChess[is][ix][iy] <= 0)
				for(int iz = 0; iz <= 8; iz++)
					for(int i = 1; ix + i * (iz / 3 - 1) >= 0 && ix + i * (iz / 3 - 1) <= 7 && iy + i * (iz % 3 - 1) >= 0 && iy + i * (iz % 3 - 1) <= 7; i++)
						if(iChess[is][ix + i * (iz / 3 - 1)][iy + i * (iz % 3 - 1)] > 0)
						{
							if(iChess[is][ix + i * (iz / 3 - 1)][iy + i * (iz % 3 - 1)] == it)
							{
								if(i == 1)
									break;
								iChess[is][ix][iy] = -1;
								iIChess[ix][iy][iz] = i;
								bpause = 1;
								break;
							}
						}
						else
							break;

	iStep[is + 1] = 100 * it + 88;
	if(!bpause)
	{
		if(!bp)
		{
			Print(is);
			cout << "Please Press U To Undo This Step....\n";
			cout << "Please Press E To Exit This Play....\n";
			cout << "Please Press Any Key To Continue....\n";
			ch = getche();
			if(is && (ch == 'U' || ch == 'u'))
				return 1;
			if(ch == 'E' || ch == 'e')
				return 2;
			bp = 1;
			is++;
			for(int i = 0; i <= 7; i++)
				for(int j = 0; j <= 7; j++)
					iChess[is][i][j] = iChess[is - 1][i][j];
			return 0;
		}
		else
		{
			iStep[is] = 99;
			return 2;
		}
	}
	bp = 0;

start:
	Print(is);
	cout << "Please Press U To Undo This Step....\n";
	cout << "Please Press E To Exit This Play....\n";
	cout << "Please Input The Position You Want :\n";
	ch = getche();
	if(is && (ch == 'U' || ch == 'u'))
		return 1;
	if(ch == 'E' || ch == 'e')
		return 2;
	if(ch < 48 || ch > 55)
		goto start;
	ix = ch - 48;
	ch = getche();
	if(is > 0 && (ch == 'U' || ch == 'u'))
		return 1;
	if(ch == 'E' || ch == 'e')
		return 2;
	if(ch < 48 || ch > 55)
		goto start;
	iy = ch - 48;
	if(iChess[is][ix][iy] >= 0)
		goto start;

	is++;
	for(int i = 0; i <= 7; i++)
		for(int j = 0; j <= 7; j++)
			if(iChess[is - 1][i][j] >= 0)
				iChess[is][i][j] = iChess[is - 1][i][j];
			else
				iChess[is][i][j] = 0;
	iStep[is] = 100 * it + 10 * ix + iy;
	iChess[is][ix][iy] = it;
	for(int iz = 0; iz <= 8; iz++)
		for(int i = 1; i < iIChess[ix][iy][iz]; i++)
			iChess[is][ix + i * (iz / 3 - 1)][iy + i * (iz % 3 - 1)] = it;
	return 0;
}

bool Watch()
{
	for(int in = 0; in < is; in++)
	{
		Print(in);
		cout << "Please Press U To Undo This Step....\n";
		cout << "Please Press E To Exit This Play....\n";
		cout << "Please Press Any Key To Continue....\n";
		ch = getch();
		if(in && (ch == 'U' || ch == 'u'))
			in -= 2;
		if(ch == 'E' || ch == 'e')
			return 0;
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
	for(int i = 0, j = 1; i < 6 && *im <= in ;i++, ++*im)
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