#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include<Windows.h>
#include<conio.h>
#include <string>
#include <stdio.h>

using std::endl;
using std::cout;
using std::cin;
using std::string;


void welcome();
char getKeyPress();
void printLevel(int);
void setMe(int);
bool isExit(int, int, int);
bool isWall(int, int, int);
int getPos(int, int&);
int getX(int, int &);
void update(int, int, int);
void makeSpace(int, int, int);

const char space = ' ';
const char me = '.';
const char wall = 'W';

char lvl1[15][15] =
{ { "WWWWWWWWW"},
 { "W     W !"},
 { "W WWW W W" },
 { "W W W W W" },
 { "W W W   W" },
 { "W W WWW W" },
 { ". W W W W" },
 { "W   W   W" },
 { "WWWWWWWWW" } };

char lvl2[15][15] =
{ { "WWWW!WWWW"},
 { "WWW   W W"},
 { "WW  W W W" },
 { "WW WW W W" },
 { "WW WW  WW" },
 { "WW W  WWW" },
 { ".W WW W W" },
 { "    W   W" },
 { "WWWWWWWWW" } };




using namespace std;
int main()
{

	int count;

	// Display the numbers 1 through 10

	for (count = 0; count <= 7; count++)

		printf("%d ", count);

	printf("\n");

	cout <<
		"8 7 6 5 4 3 2 1\n"
		"8 7 6 4 3 2 1\n"
		"1 3 5 7 9\n"
		"9 4 1 0 1 4 9\n"
		"0 1 2 3 4 0 1 2\n"
		"1 13 169 149 145 93 185 101 33 173" << endl;

	

	int rows;
	cout << "Enter number of rows: ";
	cin >> rows;
	for (int i = 0; i <= rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << j << " ";
		}
		cout << "\n";
	}

	{
		int n, num = 0, i;
		cout << "\n\n Print a number in words:\n";
		cout << "-----------------------------\n";
		cout << " Input four numbers: ";
		cin >> n;
		while (n != 0) {
			num = (num * 10) + (n % 10);
			n /= 10;
		}
		for (i = num; i > 0; i = i / 10) {

			switch (i % 10) {
			case 0:
				cout << "Zero ";
				break;
			case 1:
				cout << "One ";
				break;
			case 2:
				cout << "Two ";
				break;
			case 3:
				cout << "Three ";
				break;
			case 4:
				cout << "Four ";
				break;
			case 5:
				cout << "Five ";
				break;
			case 6:
				cout << "Six ";
				break;
			case 7:
				cout << "Seven ";
				break;
			case 8:
				cout << "Eight ";
				break;
			case 9:
				cout << "Nine ";
				break;
			}
		}
		cout << endl;

	}

	int main(void);
		welcome();
	begin:
		system("CLS");
		cout << "\n\n    \t\t\t";
		cout << "PLEASE SELECT A LEVEL \n\n    \t\t\t1---2\n    \t\t\t";
		int lvl;
		cin >> lvl;
		if (lvl != 2 && lvl != 1 && lvl > 0) {
			cout << endl << endl;
			cout << "\t\t";
			cout << "Level not available yet, please check back later." << endl;
			Sleep(1000);
			goto begin;
		}
		system("CLS");
		setMe(lvl);
		printLevel(lvl);
		int x, y;

		while (1) {

			char move = getKeyPress();

			switch (move) {

			case 'u':
				x = getPos(lvl, y);
				if (!isWall(x - 1, y, lvl)) {
					if (isExit(x - 1, y, lvl)) {
						system("CLS");
						cout << "You Win!" << endl;
						Sleep(2000);
						goto begin;;
					}
					system("CLS");
					makeSpace(lvl, x, y);
					update(lvl, x - 1, y);
				}
				break;
			case 'd':
				x = getPos(lvl, y);
				if (!isWall(x + 1, y, lvl)) {
					if (isExit(x + 1, y, lvl)) {
						system("CLS");
						cout << "You Win!" << endl;
						Sleep(2000);
						goto begin;;
					}
					system("CLS");
					makeSpace(lvl, x, y);
					update(lvl, x + 1, y);
				}
				break;
			case 'l':
				x = getPos(lvl, y);
				if (!isWall(x, y - 1, lvl)) {
					if (isExit(x, y - 1, lvl)) {
						system("CLS");
						cout << "You Win!" << endl;
						Sleep(2000);
						goto begin;;
					}
					system("CLS");
					makeSpace(lvl, x, y);
					update(lvl, x, y - 1);
				}
				break;
			case 'r':
				x = getPos(lvl, y);
				if (!isWall(x, y + 1, lvl)) {
					if (isExit(x, y + 1, lvl)) {
						system("CLS");
						cout << "You Win!" << endl;
						Sleep(2000);
						goto begin;;
					}
					system("CLS");
					makeSpace(lvl, x, y);
					update(lvl, x, y + 1);
				}
				break;
			default:
				break;
			}

		}

		return 0;
	}

	void welcome() {
		string start = "Hello to Emil's Maze";
		string howto = "Use the arrow keys and traverse through the maze. Exit is marked '!'.";
		cout << endl;
		cout << "\n\n\    \t\t\t";
		for (auto ch : start) {
			cout << ch;
			Sleep(40);
		} cout << endl << endl;
		cout << "    \t   ";

		cout << "\t";
		for (auto ch : howto) {
			cout << ch;
			Sleep(40);
		}
		Sleep(1500);
	}


	void printLevel(int lvl) {
		cout << "\n\n\n\n\n";
		if (lvl == 1) {
			for (int i = 0; i != 15; ++i) {
				cout << endl << "\t\t\t\t";
				for (int j = 0; j != 15; ++j) {
					cout << lvl1[i][j];
				}
			} cout << endl;
		}
		if (lvl == 2) {
			for (int i = 0; i != 15; ++i) {
				cout << endl << "\t\t\t\t";
				for (int j = 0; j != 15; ++j) {
					cout << lvl2[i][j];
				}
			} cout << endl;
		}
	}

	void setMe(int lvl) {
		int x, y;
		if (lvl == 1) {
			x = getX(lvl, y);
			lvl1[x][y] = me;
		}
		if (lvl == 2) {
			x = getX(lvl, y);
			lvl2[x][y] = me;
		}
	}
	//got this function from a CPP forum
	char getKeyPress() {

		char key = 127;

		key = _getch();

		if (key == 0 || key == -32) {

			key = _getch();

			if (key == 72) {
				key = 'u';
			}
			else if (key == 75) {
				key = 'l';
			}
			else if (key == 77) {
				key = 'r';
			}
			else if (key == 80) {
				key = 'd';
			}
		}
		return key;
	}

	bool isExit(int x, int y, int lvl) {
		if (lvl == 1) {
			if (lvl1[x][y] == '!') {
				return true;
			}
			else {
				return false;
			}
		}
		if (lvl == 2) {
			if (lvl2[x][y] == '!') {
				return true;
			}
			else {
				return false;
			}
		}
		return true;
	}

	int getPos(int lvl, int &y) {
		int xCoord;
		if (lvl == 1) {
			for (int i = 0; i != 15; ++i) {
				for (int j = 0; j != 15; ++j) {
					if (lvl1[i][j] == '.') {
						xCoord = i;
						y = j;
						return xCoord;
					}
				}
			}
		}
		if (lvl == 2) {
			for (int i = 0; i != 15; ++i) {
				for (int j = 0; j != 15; ++j) {
					if (lvl2[i][j] == '.') {
						xCoord = i;
						y = j;
						return xCoord;
					}
				}
			}
		}
		return 0;
	}

	bool isWall(int x, int y, int lvl) {
		if (lvl == 1) {
			if (lvl1[x][y] == 'W') {
				cout << "\n\t\t\tCannot move! That is a wall / boundary.";
				Sleep(400);
				system("CLS");
				printLevel(lvl);
				return true;
			}
			else {
				return false;
			}
		}
		if (lvl == 2) {
			if (lvl2[x][y] == 'W') {
				cout << "\n\t\t\tCannot move! That is a wall / boundary.";
				Sleep(400);
				system("CLS");
				printLevel(lvl);
				return true;
			}
			else {
				return false;
			}
		}
		return true;
	}

	int getX(int lvl, int &y) {
		int xCoord;
		if (lvl == 1) {
			for (int i = 0; i != 15; ++i) {
				for (int j = 0; j != 15; ++j) {
					if (lvl1[i][j] == '.') {
						xCoord = i;
						y = j;
						return xCoord;
					}
				}
			}
		}
		if (lvl == 2) {
			for (int i = 0; i != 15; ++i) {
				for (int j = 0; j != 15; ++j) {
					if (lvl2[i][j] == '.') {
						xCoord = i;
						y = j;
						return xCoord;
					}
				}
			}
		}
		return 0;
	}

	void update(int lvl, int x, int y) {
		if (lvl == 1) {
			lvl1[x][y] = me;
			printLevel(lvl);
		}
		if (lvl == 2) {
			lvl2[x][y] = me;
			printLevel(lvl);
		}
	}

	void makeSpace(int lvl, int x, int y) {
		if (lvl == 1) {
			lvl1[x][y] = space;
		}
		if (lvl == 2) {
			lvl2[x][y] = space;
		}
	}


