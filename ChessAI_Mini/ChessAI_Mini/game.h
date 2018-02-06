#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define XL 5	//往下為正
#define YL 5	//往右為正
#define NChess "RBQKBR\nPPPPPP\n000000\n000000\npppppp\nrbqkbr"
//#define NChess "RNBQKBNR\nPPPPPPPP\n00000000\n00000000\n00000000\n00000000\npppppppp\nrnbqkqnr"


FILE *fr, *fw;
bool bChess[XL + 1][YL + 1][2];
char ch, str[64], cChess[XL + 1][YL + 1], line[XL * 4 + 9];
int x, y, i, j, k, inf, iwin, iChess[XL + 1][YL + 1], Loading(), Print(), PStep(), CStep(), Step(bool), PrintB();

int Main()
{
START:
	system("cls");
	inf = Loading();
	if(inf)
		return inf;
	while(1)
	{
		system("cls");
		printf("0)先手 1)後手 : ");
		switch(_getche())
		{
		case '0':
			goto PFIRST;
			break;
		case '1':
			goto CFIRST;
			break;
		}
	}
	
	while(1)
	{
PFIRST:
		Print();
		switch(PStep())
		{
		case 1:
			goto START;
		case 2:
			goto END;
		}
CFIRST:
		Print();
		printf("Thinking...");
		//inf = CStep();
	}
END:
	return 0;
}

int Loading()
{
	printf("Please Press Esc If You Want To Reset This Program...");
	if(!(_getch() - 27))
	{
		system("rmdir Data /s /q");
		system("md Data");
		fopen_s(&fw, "Data\\NChess.dat", "w");
		if(fw)
		{
			fprintf(fw, NChess);
			fclose(fw);
		}
		fopen_s(&fw, "Data\\Step.dat", "w");
		fclose(fw);
	}
	fopen_s(&fr, "Data\\NChess.dat", "r");
		if(!fr)
			return 1;
	for(y = YL; y >= 0; y--)
	{
		for(x = 0; x <= XL; x++)
		{
			cChess[x][y] = fgetc(fr);
			switch(cChess[x][y])
			{
			case 'K':
				iChess[x][y] = 0;
				break;
			case 'Q':
				iChess[x][y] = 1;
				break;
			case 'R':
				iChess[x][y] = 2;
				break;
			case 'B':
				iChess[x][y] = 3;
				break;
			case 'N':
				iChess[x][y] = 4;
				break;
			case 'P':
				iChess[x][y] = 5;
				break;
			case 'k':
				iChess[x][y] = 6;
				break;
			case 'q':
				iChess[x][y] = 7;
				break;
			case 'r':
				iChess[x][y] = 8;
				break;
			case 'b':
				iChess[x][y] = 9;
				break;
			case 'n':
				iChess[x][y] = 10;
				break;
			case 'p':
				iChess[x][y] = 11;
				break;
			default:
				iChess[x][y] = -1;
				cChess[x][y] = 0;
			}
		}
		fgetc(fr);
	}
	fclose(fr);
	fopen_s(&fr, "Data\\Step.dat", "r");
		if(!fr)
			return 2;
	fclose(fr);
	line[0] = '\n';
	line[1] = ' ';
	line[2] = '+';
	line[3] = ' ';
	for(x = 0; x <= XL; x++)
	{
		line[4 * x + 4] = ' ';
		line[4 * x + 5] = '-';
		line[4 * x + 6] = ' ';
		line[4 * x + 7] = '+';
	}
	line[XL * 4 + 8] = '\0';
	return 0;
}

int Print()
{
	system("cls");
	printf("    ");
	for(x = 0; x <= XL; x++)
		printf("%c   ", x + 97);
	for(y = YL; y >= 0; y--)
	{
		printf("%s\n%d | ",line ,  y + 1);
		for(x = 0; x <= XL; x++)
			printf("%c | ", cChess[x][y]);
	}
	printf("%s\n\n", line);
	return 0;
}

int PrintB()
{
	printf("    ");
	for(x = 0; x <= XL; x++)
		printf("%c   ", x + 97);
	for(y = YL; y >= 0; y--)
	{
		printf("%s\n%d | ",line ,  y + 1);
		for(x = 0; x <= XL; x++)
			if(bChess[x][y][0] > bChess[x][y][1])
				if(iChess[x][y] + 1)
					printf("++| ");
				else
					printf("+ | ");
			else if(bChess[x][y][0] < bChess[x][y][1])
				if(iChess[x][y] + 1)
					printf("--| ");
				else
					printf("- | ");
			else
				printf("  | ");
	}
	printf("%s\n\n", line);
return 0;
}

int PStep()
{
	Step(1);
PSTEPS:
	printf("請輸入位置：");
	scanf_s("%s", str, sizeof(str));
	if(str[0] == 'p' && str[1] == 'l' && str[2] == 'a' && str[3] == 'y')
		return 1;
	if(str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't')
		return 2;
	x = str[0] - 97;
	y = str[1] - 49;
	i = str[2] - 97;
	j = str[3] - 49;
	if(x < 0 || x > XL || y < 0 || y > YL || i < 0 || i > XL || j < 0 || j > YL)
	{
		printf("格式錯誤！！\n");
		goto PSTEPS;
	}
	fopen_s(&fr, "Data\\Step.dat", "r");
	while(1)
	{
		fscanf_s(fr, "%s", str, sizeof(str));
		if(str[0] == '0')
		{
			fclose(fr);
			printf("此步違法！！\n");
			goto PSTEPS;
		}
		if(x == str[1] - 48 && y == str[2] - 48 && i == str[3] - 48 && j == str[4] - 48)
			break;
	}
	cChess[i][j] = cChess[x][y];
	cChess[x][y] = 0;
	iChess[i][j] = iChess[x][y];
	iChess[x][y] = -1;
	fclose(fr);
	return 0;
}

int CStep()
{
	Step(0);
	return 0;
}

int Step(bool bs)
{
	int is;
	bool bqueen, bbs;
	fopen_s(&fw, "Data\\Step.dat", "w");
	for(x = 0; x <= XL; x++)
	{
		for(y = 0; y <= YL; y++)
		{
			if(!(iChess[x][y] + 1))
				continue;
			is = (unsigned)iChess[x][y] / 6;
			bqueen = 0;
			bbs = (is == (int)bs);
			switch(iChess[x][y])
			{
			case 0:
			case 6:
				for(i = x - 1; i <= x + 1; i++)
				{
					if(i < 0 || i > XL)
						continue;
					for(j = y - 1; j <= y + 1; j++)
					{
						if(j < 0 || j > XL)
							continue;
						bChess[i][j][is] = 1;
						if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					}
				}
				break;
			case 1:
			case 7:
				bqueen = 1;
			case 2:
			case 8:
				for(i = x + 1, j = y; i <= XL; i++)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					if(iChess[i][j] + 1)
							break;
				}
				for(i = x - 1, j = y; i >= 0; i--)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					if(iChess[i][j] + 1)
							break;
				}
				for(i = x, j = y + 1; j <= YL; j++)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					if(iChess[i][j] + 1)
							break;
				}
				for(i = x, j = y - 1; j >= 0; j--)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					if(iChess[i][j] + 1)
							break;
				}
				if(!bqueen)
					break;
			case 3:
			case 9:
				for(i = x + 1, j = y + 1; i <= XL && j <= YL; i++, j++)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					if(iChess[i][j] + 1)
							break;
				}
				for(i = x + 1, j = y - 1; i <= XL && j >= 0; i++, j--)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					if(iChess[i][j] + 1)
							break;
				}
				for(i = x - 1, j = y + 1; i >= 0 && j <= YL; i--, j++)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					if(iChess[i][j] + 1)
							break;
				}
				for(i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 != (int)bs)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
					if(iChess[i][j] + 1)
							break;
				}
				break;
			case 4:
			case 10:
				//略
				break;
			case 5:
			case 11:
				i = x - 1;
				j = y - 1 + 2 * is;
				if(i >= 0)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 + (int)bs == 1)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
				}
				i++;
				if(bbs && iChess[i][j] == -1)
					fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
				i++;
				if(i <= YL)
				{
					bChess[i][j][is] = 1;
					if(bbs && (unsigned)iChess[i][j] / 6 + (int)bs == 1)
							fprintf(fw, "%c%d%d%d%d\n", cChess[x][y], x, y, i, j);
				}
				break;
			}
		}
	}
	fprintf(fw, "0");
	fclose(fw);
	return 0;
}