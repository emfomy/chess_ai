#include "stdafx.h"
#include "game.h"
#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int iPNl = sizeof(ProgramName);
	int iDel = sizeof(Designer);
	int iDal = sizeof(Date);
	system("cls");
	cout << "бубубубубубубубубубубубубубубубубубубубубу\n";
	for(int i = 0; i < 10 - iPNl/ 4; i++) cout << "бу";
	if(iPNl % 4 <= 1) cout << ' ';
	cout << ProgramName;
	if(iPNl % 2 == 0) cout << ' ';
	if(iPNl % 4 <= 1) cout << ' ';	
	for(int i = 0; i < 10 - iPNl/ 4; i++) cout << "бу";
	cout << "\nбубубубубубубубубубубубубубубубубубубубубу\n";
	for(int i = 0; i < 10 - iDel/ 4; i++) cout << "бу";
	if(iDel % 4 <= 1) cout << ' ';
	cout << Designer;
	if(iDel % 2 == 0) cout << ' ';
	if(iDel % 4 <= 1) cout << ' ';
	for(int i = 0; i < 10 - iDel/ 4; i++) cout << "бу";
	cout << "\nбубубубубубубубубубубубубубубубубубубубубу\n\n\n";
	cout << "Please Press Any Key To Start The Game....\n";
	getch();
	Main();
	system("cls");
	cout << "Thank You For Your Support To The Game....\n\n\n";
	cout << "бубубубубубубубубубубубубубубубубубубубубу\n";
	for(int i = 0; i < 10 - iPNl/ 4; i++) cout << "бу";
	if(iPNl % 4 <= 1) cout << ' ';
	cout << ProgramName;
	if(iPNl % 2 == 0) cout << ' ';
	if(iPNl % 4 <= 1) cout << ' ';	
	for(int i = 0; i < 10 - iPNl/ 4; i++) cout << "бу";
	cout << '\n';
	for(int i = 0; i < 10 - iDel/ 4; i++) cout << "бу";
	if(iDel % 4 <= 1) cout << ' ';
	cout << Designer;
	if(iDel % 2 == 0) cout << ' ';
	if(iDel % 4 <= 1) cout << ' ';
	for(int i = 0; i < 10 - iDel/ 4; i++) cout << "бу";
	cout << '\n';
	for(int i = 0; i < 10 - iDal/ 4; i++) cout << "бу";
	if(iDal % 4 <= 1) cout << ' ';
	cout << Date;
	if(iDal % 2 == 0) cout << ' ';
	if(iDal % 4 <= 1) cout << ' ';
	for(int i = 0; i < 10 - iDal/ 4; i++) cout << "бу";
	cout << "\nбубубубубубубубубубубубубубубубубубубубубу\n\n\n";
	cout << "Please Press Any Key To Leave The Game....\n";	
	getch();
	return 0;
}