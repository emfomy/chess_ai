#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define maxstep 256

unsigned char Type[maxstep][32], Man[maxstep][32], Board[maxstep][144];
char Piece[256], str[256], ch;
bool Ablestep[32][144];

int Game(), Reset(), Print(int), Next(int), Move(int, int, int), PStep(int), CStep(int), AStep(int, bool, int, int), XStep(int, bool);

int main()
{
	srand((unsigned)time(0));
	switch(Game())
	{
	case 1:
		printf("NChess.dat error!!\n");
		break;
	}
	system("pause");
	return 0;
}

int Game()
{
	int n = 0;
	Reset();
	while(1)
	{
		n = PStep(n);
		if(n == -1)
			return 0;
		n = CStep(n);
		if(n == -1)
			return 0;
	}
	return 0;
}

int Reset()
{
	/*
	printf("Please Press Esc To Reset...\n");
	if(getch() == 27)
	{
		printf("Really Want to Reset?(Y)");
		ch = getch();
		if(ch == 'Y' || ch == 'y')
			system("rmdir Data /s /q");
	}
	system("md Data");
	system("cls");
	FILE *fr, *fw;
	fw = fopen("Data\\NChess.dat", "w");
	if(fw)
	{
		fprintf(fw, NType);
		fclose(fw);
	}
	fr = fopen("Data\\NChess.dat", "r");
		if(!fr)
			return 1;
	for(int i = 0x00; i <= 0xFF; i++)
		Piece[i] = fgetc(fr);
	fclose(fr);*/
	
	Piece[0x00] = 'k';	Piece[0x01] = 'q';	Piece[0x02] = 'r';	Piece[0x03] = 'b';	Piece[0x04] = 'n';	Piece[0x05] = 'p';	Piece[0x06] = 'k';	Piece[0x07] = 'r';	Piece[0x08] = 'p';	Piece[0x09] = 'p';
	Piece[0x10] = 'K';	Piece[0x11] = 'Q';	Piece[0x12] = 'R';	Piece[0x13] = 'B';	Piece[0x14] = 'N';	Piece[0x15] = 'P';	Piece[0x16] = 'K';	Piece[0x17] = 'R';	Piece[0x18] = 'P';	Piece[0x19] = 'P';
//	Piece[0x00] = 'k';	Piece[0x01] = 'q';	Piece[0x02] = 'r';	Piece[0x03] = 'b';	Piece[0x04] = 'n';	Piece[0x05] = 'p';	Piece[0x06] = 'l';	Piece[0x07] = 's';	Piece[0x08] = 'o';	Piece[0x09] = 'd';
//	Piece[0x10] = 'K';	Piece[0x11] = 'Q';	Piece[0x12] = 'R';	Piece[0x13] = 'B';	Piece[0x14] = 'N';	Piece[0x15] = 'P';	Piece[0x16] = 'L';	Piece[0x17] = 'S';	Piece[0x18] = 'O';	Piece[0x19] = 'D';

	Type[0x0][0x00] = 0x07;	Type[0x0][0x01] = 0x04;	Type[0x0][0x02] = 0x03;	Type[0x0][0x03] = 0x01;	Type[0x0][0x04] = 0x06;	Type[0x0][0x05] = 0x03;	Type[0x0][0x06] = 0x04;	Type[0x0][0x07] = 0x07;
	Type[0x0][0x08] = 0x08;	Type[0x0][0x09] = 0x08;	Type[0x0][0x0A] = 0x08;	Type[0x0][0x0B] = 0x08;	Type[0x0][0x0C] = 0x08;	Type[0x0][0x0D] = 0x08;	Type[0x0][0x0E] = 0x08;	Type[0x0][0x0F] = 0x08;
	Type[0x0][0x10] = 0x17;	Type[0x0][0x11] = 0x14;	Type[0x0][0x12] = 0x13;	Type[0x0][0x13] = 0x11;	Type[0x0][0x14] = 0x16;	Type[0x0][0x15] = 0x13;	Type[0x0][0x16] = 0x14;	Type[0x0][0x17] = 0x17;
	Type[0x0][0x18] = 0x18;	Type[0x0][0x19] = 0x18;	Type[0x0][0x1A] = 0x18;	Type[0x0][0x1B] = 0x18;	Type[0x0][0x1C] = 0x18;	Type[0x0][0x1D] = 0x18;	Type[0x0][0x1E] = 0x18;	Type[0x0][0x1F] = 0x18;
	
	Man[0x0][0x00] = 26;	Man[0x0][0x01] = 27;	Man[0x0][0x02] = 28;	Man[0x0][0x03] = 29;	Man[0x0][0x04] = 30;	Man[0x0][0x05] = 31;	Man[0x0][0x06] = 32;	Man[0x0][0x07] = 33;
	Man[0x0][0x08] = 38;	Man[0x0][0x09] = 39;	Man[0x0][0x0A] = 40;	Man[0x0][0x0B] = 41;	Man[0x0][0x0C] = 42;	Man[0x0][0x0D] = 43;	Man[0x0][0x0E] = 44;	Man[0x0][0x0F] = 45;
	Man[0x0][0x10] =110;	Man[0x0][0x11] =111;	Man[0x0][0x12] =112;	Man[0x0][0x13] =113;	Man[0x0][0x14] =114;	Man[0x0][0x15] =115;	Man[0x0][0x16] =116;	Man[0x0][0x17] =117;
	Man[0x0][0x18] = 98;	Man[0x0][0x19] = 99;	Man[0x0][0x1A] =100;	Man[0x0][0x1B] =101;	Man[0x0][0x1C] =102;	Man[0x0][0x1D] =103;	Man[0x0][0x1E] =104;	Man[0x0][0x1F] =105;
	
	for(int i = 0; i < 144; i++)
		Board[0x0][i] = 0x2F;
	
	Board[0x0][26] = 0x00;	Board[0x0][27] = 0x01;	Board[0x0][28] = 0x02;	Board[0x0][29] = 0x03;	Board[0x0][30] = 0x04;	Board[0x0][31] = 0x05;	Board[0x0][32] = 0x06;	Board[0x0][33] = 0x07;
	Board[0x0][38] = 0x08;	Board[0x0][39] = 0x09;	Board[0x0][40] = 0x0A;	Board[0x0][41] = 0x0B;	Board[0x0][42] = 0x0C;	Board[0x0][43] = 0x0D;	Board[0x0][44] = 0x0E;	Board[0x0][45] = 0x0F;
	Board[0x0][50] = 0xFF;	Board[0x0][51] = 0xFF;	Board[0x0][52] = 0xFF;	Board[0x0][53] = 0xFF;	Board[0x0][54] = 0xFF;	Board[0x0][55] = 0xFF;	Board[0x0][56] = 0xFF;	Board[0x0][57] = 0xFF;
	Board[0x0][62] = 0xFF;	Board[0x0][63] = 0xFF;	Board[0x0][64] = 0xFF;	Board[0x0][65] = 0xFF;	Board[0x0][66] = 0xFF;	Board[0x0][67] = 0xFF;	Board[0x0][68] = 0xFF;	Board[0x0][69] = 0xFF;
	Board[0x0][74] = 0xFF;	Board[0x0][75] = 0xFF;	Board[0x0][76] = 0xFF;	Board[0x0][77] = 0xFF;	Board[0x0][78] = 0xFF;	Board[0x0][79] = 0xFF;	Board[0x0][80] = 0xFF;	Board[0x0][81] = 0xFF;
	Board[0x0][86] = 0xFF;	Board[0x0][87] = 0xFF;	Board[0x0][88] = 0xFF;	Board[0x0][89] = 0xFF;	Board[0x0][90] = 0xFF;	Board[0x0][91] = 0xFF;	Board[0x0][92] = 0xFF;	Board[0x0][93] = 0xFF;
	Board[0x0][98] = 0x18;	Board[0x0][99] = 0x19;	Board[0x0][100]= 0x1A;	Board[0x0][101]= 0x1B;	Board[0x0][102]= 0x1C;	Board[0x0][103]= 0x1D;	Board[0x0][104]= 0x1E;	Board[0x0][105]= 0x1F;
	Board[0x0][110]= 0x10;	Board[0x0][111]= 0x11;	Board[0x0][112]= 0x12;	Board[0x0][113]= 0x13;	Board[0x0][114]= 0x14;	Board[0x0][115]= 0x15;	Board[0x0][116]= 0x16;	Board[0x0][117]= 0x17;
	
	return 0;
}

int Print(int n)
{
	system("cls");
	printf("%03d a   b   c   d   e   f   g   h", n);
	for(int i = 9; i >= 2; i--)
	{
		printf("\n  + - + - + - + - + - + - + - + - +\n%d | ", i-1);
		for(int j = 12*i+2; j < 12*i+10; j++)
		{
			if((unsigned)Board[n][j] < 0x20)
				printf("%c | ", Piece[Type[n][Board[n][j]]]);
			else if(Board[n][j] == 0xFF)
				printf("  | ");
			else if(Board[n][j] == 0x2F)
				printf("@ | ");
			else
				printf("? | ");
		}
	}
	printf("\n  + - + - + - + - + - + - + - + - +\n");
/*
	printf("%03d  @   @   a   b   c   d   e   f   g   h   @   @", n);
	for(int i = 11; i >= 0; i--)
	{
		printf("\n   + - + - + - + - + - + - + - + - + - + - + - + - +\n%2d | ", i-1);
		for(int j = 12*i; j < 12*i+12; j++)
		{
			if((unsigned)Board[n][j] < 0x20)
				printf("%c | ", Piece[Type[n][Board[n][j]]]);
			else if(Board[n][j] == 0xFF)
				printf("  | ");
			else if(Board[n][j] == 0x2F)
				printf("@ | ");
			else if(Board[n][j] == 0x3F)
				printf("# | ");
			else
				printf("? | ");
		}
	}
	printf("\n   + - + - + - + - + - + - + - + - + - + - + - + - +\n\n");
*/
	return 0;
}

int Next(int n)
{
	for(int i = 0; i < 32; i++)
	{
		Type[n+1][i] = Type[n][i];
		Man[n+1][i] = Man[n][i];
	}
	for(int i =   0; i <  24; i++)
		Board[n+1][i] = 0x2F;
	for(int i =  24; i < 120; i++)
		Board[n+1][i] = Board[n][i];
	for(int i = 120; i < 144; i++)
		Board[n+1][i] = 0x2F;
	return 0;
}

int Move(int n, int z1, int z2)
{
	int m1, m2;
	m1 = Board[n][z1];
	m2 = Board[n][z2];
	Board[n+1][z1] = 0xFF;
	Board[n+1][z2] = m1;
	Man[n+1][m1] = z2;
	switch(Type[n][m1])
	{
	case 0x05://p
		if(Type[n][m2] == 0x19)//en passant
		{
			Board[n+1][z2] = 0xFF;
			Board[n+1][z2+12] = m1;
			Man[n+1][m1] = z2+12;
		}
		break;

	case 0x06://l
		Type[n+1][m1] = 0x00;
		if(z2 == 28)//ooo
		{
			Board[n+1][26] = 0xFF;
			Board[n+1][29] = 0x00;
			Man[n+1][0x00] = 29;
			Type[n+1][0x00] = 0x02;
		}
		if(z2 == 32)//oo
		{
			Board[n+1][33] = 0xFF;
			Board[n+1][31] = 0x07;
			Man[n+1][0x07] = 31;
			Type[n+1][0x07] = 0x02;
		}
		break;

	case 0x07://s
		Type[n+1][m1] = 0x02;
		break;

	case 0x08://o
		if(z2 - z1 == 24)
		{
			Type[n+1][m1] = 0x09;
			Board[n+1][z1%12] = 0x3F;
			break;
		}
		Type[n+1][m1] = 0x05;
		break;

	case 0x09://d
		Type[n+1][m1] = 0x05;
		break;

	case 0x15://P
		if(Type[n][m2] == 0x09)//en passant
		{
			Board[n+1][z2] = 0xFF;
			Board[n+1][z2-12] = m1;
			Man[n+1][m1] = z2-12;
		}
		break;

	case 0x16://L
		Type[n+1][m1] = 0x10;
		if(z2 == 112)//ooo
		{
			Board[n+1][110] = 0xFF;
			Board[n+1][113] = 0x10;
			Man[n+1][0x10] = 113;
			Type[n+1][0x10] = 0x12;
		}
		if(z2 == 116)//oo
		{
			Board[n+1][117] = 0xFF;
			Board[n+1][115] = 0x17;
			Man[n+1][0x17] = 115;
			Type[n+1][0x17] = 0x12;
		}
		break;

	case 0x17://S
		Type[n+1][m1] = 0x12;
		break;

	case 0x18://O
		if(z1 - z2 == 24)
		{
			Type[n+1][m1] = 0x19;
			Board[n+1][z1%12+132] = 0x3F;
			break;
		}
		Type[n+1][m1] = 0x15;
		break;

	case 0x19://D
		Type[n+1][m1] = 0x15;
		break;
	}
	if(m2 != 0xFF)
	{
		Man[n+1][m2] = 0xFF;
		Type[n+1][m2] = 0xFF;
	}
	return 0;
}

int PStep(int n)
{
	int x1, x2, y1, y2, z1, z2;
	Print(n);
	XStep(n, 0);
	Next(n);
	while(1)
	{
		printf("\nPlease Input Step...\n");
		scanf("%s", &str);
		if(str[0] == 'e')
			if(str[1] == 'x')
				if(str[2] == 'i')
					if(str[3] == 't')
						return -1;
		x1 = str[0] - 95;
		if(x1 > 9 && x1 < 2)
		{
			printf("Wrong Input!!\n");
			system("pause");
			system("cls");
			Print(n);
			continue;
		}
		y1 = str[1] - 47;
		if(y1 > 9 && y1 < 2)
		{
			printf("Wrong Input!!\n");
			system("pause");
			system("cls");
			Print(n);
			continue;
		}
		x2 = str[2] - 95;
		if(x2 > 9 && x2 < 2)
		{
			printf("Wrong Input!!\n");
			system("pause");
			system("cls");
			Print(n);
			continue;
		}
		y2 = str[3] - 47;
		if(y2 > 9 && y2 < 2)
		{
			printf("Wrong Input!!\n");
			system("pause");
			system("cls");
			Print(n);
			continue;
		}
		z1 = x1+12*y1;
		z2 = x2+12*y2;
		if(Ablestep[Board[n][z1]][z2])
			break;
		printf("Wrong Input!!\n");
		system("pause");
		system("cls");
		Print(n);
	}
	Move(n, z1, z2);
	return n+1;
}

int CStep(int n)
{
	int x1, x2, y1, y2, z1, z2;
	Print(n);
	XStep(n, 1);
	Next(n);
	while(1)
	{
		x1 = rand()%8 + 2;
		x2 = rand()%8 + 2;
		y1 = rand()%8 + 2;
		y2 = rand()%8 + 2;
		z1 = x1+12*y1;
		z2 = x2+12*y2;
		if(Ablestep[Board[n][z1]][z2])
			break;
	}
	Move(n, z1, z2);
	return n+1;
}

int AStep(int n, bool s, int z1, int z2)
{
//	int r, z1, z2, zz, m1, m2;
//	m1 = Board[n][z1];
//	m2 = Board[n][z2];
//	if(m2/16 == s)
//		return 1;
//	if(s)//KQRBNP
//	{
//		switch(Type[n][m1])
//		{
//		case 0x16://L
//			if(z2 == 112)
//				if(Type[n][Board[n][110]] == 0x17)
//					if(Board[n][111] == 0xFF)
//						if(Board[n][112] == 0xFF)
//							if(Board[n][113] == 0xFF)
//								return 0;
//			if(z2 == 116)
//				if(Type[n][Board[n][117]] == 0x17)
//					if(Board[n][116] == 0xFF)
//						if(Board[n][115] == 0xFF)
//								return 0;
//
//		case 0x10://K
//			switch(z2 - z1)
//			{
//			case -13:
//			case -12:
//			case -11:
//			case -1:
//			case +1:
//			case +11:
//			case +12:
//			case +13:
//				return 0;
//			}
//			break;
//
//		case 0x11://Q
//			r = 0;
//
//		case 0x12://R
//		case 0x17://S
//			if((z2 - z1)%12 == 0)
//			{
//				zz = z1-12
//				if(zz == z2)
//					return 0;
//				while(Board[n][zz] == 0xFF)
//				{
//					if(zz == z2)
//						return 0;
//				}
//			}
//
//			if(r)
//				break;
//
//		case 0x13://B
//			break;
//
//		case 0x14://N
//			switch(z2 - z1)
//			{
//			case -25:
//			case -23:
//			case -14:
//			case -10:
//			case +10:
//			case +14:
//			case +23:
//			case +25:
//				return 0;
//			}
//			break;
//
//		case 0x18://O
//			if(z2 == z1-24)
//				if(Board[n][z1-12] == 0xFF)
//					if(Board[n][z1-24] == 0xFF)
//						return 0;
//
//		case 0x15://P
//			if(z2 == z1-1)
//				if(Type[n][Board[n][z1-1]] == 0x09)
//					if(Board[n][z1%12-1] == 0x3F)
//						if(Board[n][z1-13] == 0xFF)
//							return 0;
//			if(z2 == z1+1)
//				if(Type[n][Board[n][z1+1]] == 0x09)
//					if(Board[n][z1%12+1] == 0x3F)
//						if(Board[n][z1-11] == 0xFF)
//							Ablestep[iman][z1+1] = 1;
//			
//		case 0x19://D
//			if(Board[n][z1-12] == 0xFF)
//				Ablestep[iman][z1-12] = 1;
//			if(Board[n][z1-13]/16 == 0)
//				Ablestep[iman][z1-13] = 1;
//			if(Board[n][z1-11]/16 == 0)
//				Ablestep[iman][z1-11] = 1;
//
//			break;
//		}
//	}
//	else//kqrnbp
//	{
//		switch(Type[n][iman])
//		{
//		case 0x06://l
//			if(Type[n][Board[n][26]] == 0x07)
//				if(Board[n][27] == 0xFF)
//					if(Board[n][28] == 0xFF)
//						if(Board[n][29] == 0xFF)
//							Ablestep[iman][28] = 1;
//			if(Type[n][Board[n][33]] == 0x07)
//				if(Board[n][32] == 0xFF)
//					if(Board[n][31] == 0xFF)
//						Ablestep[iman][32] = 1;
//		case 0x00://k
//			if(Board[n][z1-13] == 0xFF)
//				Ablestep[iman][z1-13] = 1;
//			if(Board[n][z1-12] == 0xFF)
//				Ablestep[iman][z1-12] = 1;
//			if(Board[n][z1-11] == 0xFF)
//				Ablestep[iman][z1-11] = 1;
//			if(Board[n][z1- 1] == 0xFF)
//				Ablestep[iman][z1- 1] = 1;
//			if(Board[n][z1+ 1] == 0xFF)
//				Ablestep[iman][z1+ 1] = 1;
//			if(Board[n][z1+11] == 0xFF)
//				Ablestep[iman][z1+11] = 1;
//			if(Board[n][z1+12] == 0xFF)
//				Ablestep[iman][z1+12] = 1;
//			if(Board[n][z1+13] == 0xFF)
//				Ablestep[iman][z1+13] = 1;
//
//			if(Board[n][z1-13]/16 == 1)
//				Ablestep[iman][z1-13] = 1;
//			if(Board[n][z1-12]/16 == 1)
//				Ablestep[iman][z1-12] = 1;
//			if(Board[n][z1-11]/16 == 1)
//				Ablestep[iman][z1-11] = 1;
//			if(Board[n][z1- 1]/16 == 1)
//				Ablestep[iman][z1- 1] = 1;
//			if(Board[n][z1+ 1]/16 == 1)
//				Ablestep[iman][z1+ 1] = 1;
//			if(Board[n][z1+11]/16 == 1)
//				Ablestep[iman][z1+11] = 1;
//			if(Board[n][z1+12]/16 == 1)
//				Ablestep[iman][z1+12] = 1;
//			if(Board[n][z1+13]/16 == 1)
//				Ablestep[iman][z1+13] = 1;
//
//			break;
//
//		case 0x01://q
//			r = 0;
//
//		case 0x02://r
//		case 0x07://s
//			z2 = z1-12;
//			if(Board[n][z2]/16 == 1)
//				Ablestep[iman][z2] = 1;
//			while(Board[n][z2] == 0xFF)
//			{
//				Ablestep[iman][z2] = 1;
//				z2 -= 12;
//				if(Board[n][z2]/16 == 1)
//				{
//					Ablestep[iman][z2] = 1;
//					break;
//				}
//			}
//
//			z2 = z1+12;
//			if(Board[n][z2]/16 == 1)
//				Ablestep[iman][z2] = 1;
//			while(Board[n][z2] == 0xFF)
//			{
//				Ablestep[iman][z2] = 1;
//				z2 += 12;
//				if(Board[n][z2]/16 == 1)
//				{
//					Ablestep[iman][z2] = 1;
//					break;
//				}
//			}
//
//			z2 = z1-1;
//			if(Board[n][z2]/16 == 1)
//				Ablestep[iman][z2] = 1;
//			while(Board[n][z2] == 0xFF)
//			{
//				Ablestep[iman][z2] = 1;
//				z2--;
//				if(Board[n][z2]/16 == 1)
//				{
//					Ablestep[iman][z2] = 1;
//					break;
//				}
//			}
//
//			z2 = z1+1;
//			if(Board[n][z2]/16 == 1)
//				Ablestep[iman][z2] = 1;
//			while(Board[n][z2] == 0xFF)
//			{
//				Ablestep[iman][z2] = 1;
//				z2++;
//				if(Board[n][z2]/16 == 1)
//				{
//					Ablestep[iman][z2] = 1;
//					break;
//				}
//			}
//
//			if(r)
//				break;
//
//		case 0x03://b
//			z2 = z1-13;
//			if(Board[n][z2]/16 == 1)
//				Ablestep[iman][z2] = 1;
//			while(Board[n][z2] == 0xFF)
//			{
//				Ablestep[iman][z2] = 1;
//				z2 -= 13;
//				if(Board[n][z2]/16 == 1)
//				{
//					Ablestep[iman][z2] = 1;
//					break;
//				}
//			}
//
//			z2 = z1+13;
//			if(Board[n][z2]/16 == 1)
//				Ablestep[iman][z2] = 1;
//			while(Board[n][z2] == 0xFF)
//			{
//				Ablestep[iman][z2] = 1;
//				z2 += 13;
//				if(Board[n][z2]/16 == 1)
//				{
//					Ablestep[iman][z2] = 1;
//					break;
//				}
//			}
//
//			z2 = z1-11;
//			if(Board[n][z2]/16 == 1)
//				Ablestep[iman][z2] = 1;
//			while(Board[n][z2] == 0xFF)
//			{
//				Ablestep[iman][z2] = 1;
//				z2 -= 11;
//				if(Board[n][z2]/16 == 1)
//				{
//					Ablestep[iman][z2] = 1;
//					break;
//				}
//			}
//
//			z2 = z1+11;
//			if(Board[n][z2]/16 == 1)
//				Ablestep[iman][z2] = 1;
//			while(Board[n][z2] == 0xFF)
//			{
//				Ablestep[iman][z2] = 1;
//				z2 += 11;
//				if(Board[n][z2]/16 == 1)
//				{
//					Ablestep[iman][z2] = 1;
//					break;
//				}
//			}
//
//			break;
//
//		case 0x04://n
//			if(Board[n][z1-25] == 0xFF)
//				Ablestep[iman][z1-25] = 1;
//			if(Board[n][z1-23] == 0xFF)
//				Ablestep[iman][z1-23] = 1;
//			if(Board[n][z1-14] == 0xFF)
//				Ablestep[iman][z1-14] = 1;
//			if(Board[n][z1-10] == 0xFF)
//				Ablestep[iman][z1-10] = 1;
//			if(Board[n][z1+10] == 0xFF)
//				Ablestep[iman][z1+10] = 1;
//			if(Board[n][z1+14] == 0xFF)
//				Ablestep[iman][z1+14] = 1;
//			if(Board[n][z1+23] == 0xFF)
//				Ablestep[iman][z1+23] = 1;
//			if(Board[n][z1+25] == 0xFF)
//				Ablestep[iman][z1+25] = 1;
//
//			if(Board[n][z1-25]/16 == 1)
//				Ablestep[iman][z1-25] = 1;
//			if(Board[n][z1-23]/16 == 1)
//				Ablestep[iman][z1-23] = 1;
//			if(Board[n][z1-14]/16 == 1)
//				Ablestep[iman][z1-14] = 1;
//			if(Board[n][z1-10]/16 == 1)
//				Ablestep[iman][z1-10] = 1;
//			if(Board[n][z1+10]/16 == 1)
//				Ablestep[iman][z1+10] = 1;
//			if(Board[n][z1+14]/16 == 1)
//				Ablestep[iman][z1+14] = 1;
//			if(Board[n][z1+23]/16 == 1)
//				Ablestep[iman][z1+23] = 1;
//			if(Board[n][z1+25]/16 == 1)
//				Ablestep[iman][z1+25] = 1;
//
//			break;
//
//		case 0x08://o
//			if(Board[n][z1+12] == 0xFF)
//				if(Board[n][z1+24] == 0xFF)
//					Ablestep[iman][z1+24] = 1;
//
//		case 0x05://p
//			if(Type[n][Board[n][z1-1]] == 0x19)
//				if(Board[n][z1%12+131] == 0x3F)
//					if(Board[n][z1+11] == 0xFF)
//						Ablestep[iman][z1-1] = 1;
//			if(Type[n][Board[n][z1+1]] == 0x19)
//				if(Board[n][z1%12+133] == 0x3F)
//					if(Board[n][z1+13] == 0xFF)
//						Ablestep[iman][z1+1] = 1;
//
//		case 0x09://d
//			if(Board[n][z1+12] == 0xFF)
//				Ablestep[iman][z1+12] = 1;
//			if(Board[n][z1+13]/16 == 1)
//				Ablestep[iman][z1+13] = 1;
//			if(Board[n][z1+11]/16 == 1)
//				Ablestep[iman][z1+11] = 1;
//
//			break;
//		}
//	}
//
	return 0;
}
int XStep(int n, bool s)
{
	int r, z1, z2, i, j;
	for(i = 0; i < 32; i++)
		for(j = 0; j < 144; j++)
			Ablestep[i][j] = 0;
	if(s)//KQRBNP
	{
		for(int iman = 16; iman < 32; iman++)
		{
			r = 1;
			z1 = Man[n][iman];
			switch(Type[n][iman])
			{
			case 0x16://L
				if(Type[n][Board[n][110]] == 0x17)
					if(Board[n][111] == 0xFF)
						if(Board[n][112] == 0xFF)
							if(Board[n][113] == 0xFF)
								Ablestep[iman][112] = 1;
				if(Type[n][Board[n][117]] == 0x17)
					if(Board[n][116] == 0xFF)
						if(Board[n][115] == 0xFF)
							Ablestep[iman][116] = 1;

			case 0x10://K
				if(Board[n][z1-13] == 0xFF)
					Ablestep[iman][z1-13] = 1;
				if(Board[n][z1-12] == 0xFF)
					Ablestep[iman][z1-12] = 1;
				if(Board[n][z1-11] == 0xFF)
					Ablestep[iman][z1-11] = 1;
				if(Board[n][z1- 1] == 0xFF)
					Ablestep[iman][z1- 1] = 1;
				if(Board[n][z1+ 1] == 0xFF)
					Ablestep[iman][z1+ 1] = 1;
				if(Board[n][z1+11] == 0xFF)
					Ablestep[iman][z1+11] = 1;
				if(Board[n][z1+12] == 0xFF)
					Ablestep[iman][z1+12] = 1;
				if(Board[n][z1+13] == 0xFF)
					Ablestep[iman][z1+13] = 1;

				if(Board[n][z1-13]/16 == 0)
					Ablestep[iman][z1-13] = 1;
				if(Board[n][z1-12]/16 == 0)
					Ablestep[iman][z1-12] = 1;
				if(Board[n][z1-11]/16 == 0)
					Ablestep[iman][z1-11] = 1;
				if(Board[n][z1- 1]/16 == 0)
					Ablestep[iman][z1- 1] = 1;
				if(Board[n][z1+ 1]/16 == 0)
					Ablestep[iman][z1+ 1] = 1;
				if(Board[n][z1+11]/16 == 0)
					Ablestep[iman][z1+11] = 1;
				if(Board[n][z1+12]/16 == 0)
					Ablestep[iman][z1+12] = 1;
				if(Board[n][z1+13]/16 == 0)
					Ablestep[iman][z1+13] = 1;

				break;

			case 0x11://Q
				r = 0;

			case 0x12://R
			case 0x17://S
				z2 = z1-12;
				if(Board[n][z2]/16 == 0)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 -= 12;
					if(Board[n][z2]/16 == 0)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1+12;
				if(Board[n][z2]/16 == 0)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 += 12;
					if(Board[n][z2]/16 == 0)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1-1;
				if(Board[n][z2]/16 == 0)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2--;
					if(Board[n][z2]/16 == 0)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1+1;
				if(Board[n][z2]/16 == 0)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2++;
					if(Board[n][z2]/16 == 0)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				if(r)
					break;

			case 0x13://B
				z2 = z1-13;
				if(Board[n][z2]/16 == 0)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 -= 13;
					if(Board[n][z2]/16 == 0)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1+13;
				if(Board[n][z2]/16 == 0)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 += 13;
					if(Board[n][z2]/16 == 0)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1-11;
				if(Board[n][z2]/16 == 0)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 -= 11;
					if(Board[n][z2]/16 == 0)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1+11;
				if(Board[n][z2]/16 == 0)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 += 11;
					if(Board[n][z2]/16 == 0)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				break;

			case 0x14://N
				if(Board[n][z1-25] == 0xFF)
					Ablestep[iman][z1-25] = 1;
				if(Board[n][z1-23] == 0xFF)
					Ablestep[iman][z1-23] = 1;
				if(Board[n][z1-14] == 0xFF)
					Ablestep[iman][z1-14] = 1;
				if(Board[n][z1-10] == 0xFF)
					Ablestep[iman][z1-10] = 1;
				if(Board[n][z1+10] == 0xFF)
					Ablestep[iman][z1+10] = 1;
				if(Board[n][z1+14] == 0xFF)
					Ablestep[iman][z1+14] = 1;
				if(Board[n][z1+23] == 0xFF)
					Ablestep[iman][z1+23] = 1;
				if(Board[n][z1+25] == 0xFF)
					Ablestep[iman][z1+25] = 1;

				if(Board[n][z1-25]/16 == 0)
					Ablestep[iman][z1-25] = 1;
				if(Board[n][z1-23]/16 == 0)
					Ablestep[iman][z1-23] = 1;
				if(Board[n][z1-14]/16 == 0)
					Ablestep[iman][z1-14] = 1;
				if(Board[n][z1-10]/16 == 0)
					Ablestep[iman][z1-10] = 1;
				if(Board[n][z1+10]/16 == 0)
					Ablestep[iman][z1+10] = 1;
				if(Board[n][z1+14]/16 == 0)
					Ablestep[iman][z1+14] = 1;
				if(Board[n][z1+23]/16 == 0)
					Ablestep[iman][z1+23] = 1;
				if(Board[n][z1+25]/16 == 0)
					Ablestep[iman][z1+25] = 1;

				break;

			case 0x18://O
				if(Board[n][z1-12] == 0xFF)
					if(Board[n][z1-24] == 0xFF)
						Ablestep[iman][z1-24] = 1;

			case 0x15://P
				if(Type[n][Board[n][z1-1]] == 0x09)
					if(Board[n][z1%12-1] == 0x3F)
						if(Board[n][z1-13] == 0xFF)
							Ablestep[iman][z1-1] = 1;
				if(Type[n][Board[n][z1+1]] == 0x09)
					if(Board[n][z1%12+1] == 0x3F)
						if(Board[n][z1-11] == 0xFF)
							Ablestep[iman][z1+1] = 1;
				
			case 0x19://D
				if(Board[n][z1-12] == 0xFF)
					Ablestep[iman][z1-12] = 1;
				if(Board[n][z1-13]/16 == 0)
					Ablestep[iman][z1-13] = 1;
				if(Board[n][z1-11]/16 == 0)
					Ablestep[iman][z1-11] = 1;

				break;
			}
		}
	}
	else//kqrnbp
	{
		for(int iman = 0; iman < 16; iman++)
		{
			r = 1;
			z1 = Man[n][iman];
			switch(Type[n][iman])
			{
			case 0x06://l
				if(Type[n][Board[n][26]] == 0x07)
					if(Board[n][27] == 0xFF)
						if(Board[n][28] == 0xFF)
							if(Board[n][29] == 0xFF)
								Ablestep[iman][28] = 1;
				if(Type[n][Board[n][33]] == 0x07)
					if(Board[n][32] == 0xFF)
						if(Board[n][31] == 0xFF)
							Ablestep[iman][32] = 1;
			case 0x00://k
				if(Board[n][z1-13] == 0xFF)
					Ablestep[iman][z1-13] = 1;
				if(Board[n][z1-12] == 0xFF)
					Ablestep[iman][z1-12] = 1;
				if(Board[n][z1-11] == 0xFF)
					Ablestep[iman][z1-11] = 1;
				if(Board[n][z1- 1] == 0xFF)
					Ablestep[iman][z1- 1] = 1;
				if(Board[n][z1+ 1] == 0xFF)
					Ablestep[iman][z1+ 1] = 1;
				if(Board[n][z1+11] == 0xFF)
					Ablestep[iman][z1+11] = 1;
				if(Board[n][z1+12] == 0xFF)
					Ablestep[iman][z1+12] = 1;
				if(Board[n][z1+13] == 0xFF)
					Ablestep[iman][z1+13] = 1;

				if(Board[n][z1-13]/16 == 1)
					Ablestep[iman][z1-13] = 1;
				if(Board[n][z1-12]/16 == 1)
					Ablestep[iman][z1-12] = 1;
				if(Board[n][z1-11]/16 == 1)
					Ablestep[iman][z1-11] = 1;
				if(Board[n][z1- 1]/16 == 1)
					Ablestep[iman][z1- 1] = 1;
				if(Board[n][z1+ 1]/16 == 1)
					Ablestep[iman][z1+ 1] = 1;
				if(Board[n][z1+11]/16 == 1)
					Ablestep[iman][z1+11] = 1;
				if(Board[n][z1+12]/16 == 1)
					Ablestep[iman][z1+12] = 1;
				if(Board[n][z1+13]/16 == 1)
					Ablestep[iman][z1+13] = 1;

				break;

			case 0x01://q
				r = 0;

			case 0x02://r
			case 0x07://s
				z2 = z1-12;
				if(Board[n][z2]/16 == 1)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 -= 12;
					if(Board[n][z2]/16 == 1)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1+12;
				if(Board[n][z2]/16 == 1)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 += 12;
					if(Board[n][z2]/16 == 1)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1-1;
				if(Board[n][z2]/16 == 1)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2--;
					if(Board[n][z2]/16 == 1)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1+1;
				if(Board[n][z2]/16 == 1)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2++;
					if(Board[n][z2]/16 == 1)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				if(r)
					break;

			case 0x03://b
				z2 = z1-13;
				if(Board[n][z2]/16 == 1)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 -= 13;
					if(Board[n][z2]/16 == 1)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1+13;
				if(Board[n][z2]/16 == 1)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 += 13;
					if(Board[n][z2]/16 == 1)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1-11;
				if(Board[n][z2]/16 == 1)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 -= 11;
					if(Board[n][z2]/16 == 1)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				z2 = z1+11;
				if(Board[n][z2]/16 == 1)
					Ablestep[iman][z2] = 1;
				while(Board[n][z2] == 0xFF)
				{
					Ablestep[iman][z2] = 1;
					z2 += 11;
					if(Board[n][z2]/16 == 1)
					{
						Ablestep[iman][z2] = 1;
						break;
					}
				}

				break;

			case 0x04://n
				if(Board[n][z1-25] == 0xFF)
					Ablestep[iman][z1-25] = 1;
				if(Board[n][z1-23] == 0xFF)
					Ablestep[iman][z1-23] = 1;
				if(Board[n][z1-14] == 0xFF)
					Ablestep[iman][z1-14] = 1;
				if(Board[n][z1-10] == 0xFF)
					Ablestep[iman][z1-10] = 1;
				if(Board[n][z1+10] == 0xFF)
					Ablestep[iman][z1+10] = 1;
				if(Board[n][z1+14] == 0xFF)
					Ablestep[iman][z1+14] = 1;
				if(Board[n][z1+23] == 0xFF)
					Ablestep[iman][z1+23] = 1;
				if(Board[n][z1+25] == 0xFF)
					Ablestep[iman][z1+25] = 1;

				if(Board[n][z1-25]/16 == 1)
					Ablestep[iman][z1-25] = 1;
				if(Board[n][z1-23]/16 == 1)
					Ablestep[iman][z1-23] = 1;
				if(Board[n][z1-14]/16 == 1)
					Ablestep[iman][z1-14] = 1;
				if(Board[n][z1-10]/16 == 1)
					Ablestep[iman][z1-10] = 1;
				if(Board[n][z1+10]/16 == 1)
					Ablestep[iman][z1+10] = 1;
				if(Board[n][z1+14]/16 == 1)
					Ablestep[iman][z1+14] = 1;
				if(Board[n][z1+23]/16 == 1)
					Ablestep[iman][z1+23] = 1;
				if(Board[n][z1+25]/16 == 1)
					Ablestep[iman][z1+25] = 1;

				break;

			case 0x08://o
				if(Board[n][z1+12] == 0xFF)
					if(Board[n][z1+24] == 0xFF)
						Ablestep[iman][z1+24] = 1;

			case 0x05://p
				if(Type[n][Board[n][z1-1]] == 0x19)
					if(Board[n][z1%12+131] == 0x3F)
						if(Board[n][z1+11] == 0xFF)
							Ablestep[iman][z1-1] = 1;
				if(Type[n][Board[n][z1+1]] == 0x19)
					if(Board[n][z1%12+133] == 0x3F)
						if(Board[n][z1+13] == 0xFF)
							Ablestep[iman][z1+1] = 1;

			case 0x09://d
				if(Board[n][z1+12] == 0xFF)
					Ablestep[iman][z1+12] = 1;
				if(Board[n][z1+13]/16 == 1)
					Ablestep[iman][z1+13] = 1;
				if(Board[n][z1+11]/16 == 1)
					Ablestep[iman][z1+11] = 1;

				break;
			}
		}
	}
//	for(i = 0; i < 32; i++)
//		for(j = 0; j < 144; j++)
//			if(Ablestep[i][j])
//				printf("%c%c%c%c ", Man[n][i]%12+95, Man[n][i]/12+47, j%12+95, j/12+47);
	return 0 ;
}
