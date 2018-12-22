#include "pch.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cin;
#include <string>
using std::string;

#include<Windows.h>
#include<conio.h>

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

const char space = '.';
const char me = '@';
char lvl1[15][15] = { { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
					{ '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'  },
					{ 'X', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'  },
					{ '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'  },
					{ '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', 'O'  },
					{ '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'  },
					{ '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'  },
					{ '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'  },
					{ '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#' },
					{ '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#' },
					{ '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
					{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };




int main(void) {
	welcome();
begin:
	system("CLS");
	cout << "\n\n\n\n\n\n\n    \t\t\t";
	cout << "1 Yazip entere basin. \t\t\t";
	int lvl;
	cin >> lvl;
	if (lvl != 1 && lvl > 0) {
		cout << endl << endl;
		cout << "\t\t";
		cout << "Lutfen 1 e basiniz." << endl;
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
					cout << "Cikisi Buldun!" << endl;
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
					cout << "Cikisi Buldun!" << endl;
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
					cout << "Cikisi Buldun!" << endl;
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
					cout << "Cikisi Buldun!" << endl;
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
	string start = "AKO GOTUNU SIKEYIM";
	string indev = "HAZIRLAYAN:Akif Kerim Turan";
	string howto = "Ok tuslarini kullanarak O harfine ulasmaya calis.";
	cout << endl;
	cout << "\n\n\n\n\n\n\n    \t\t\t";
	for (auto ch : start) {
		cout << ch;
		Sleep(40);
	} cout << endl << endl;
	cout << "    \t   ";
	for (auto ch : indev) {
		cout << ch;
		Sleep(40);
	} cout << endl << endl << endl;
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

}

void setMe(int lvl) {
	int x, y;
	if (lvl == 1) {
		x = getX(lvl, y);
		lvl1[x][y] = me;
	}
	
}

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
		if (lvl1[x][y] == 'O') {
			return true;
		}
		else {
			return false;
		}
	}
	
}

int getPos(int lvl, int &y) {
	int xCoord;
	if (lvl == 1) {
		for (int i = 0; i != 15; ++i) {
			for (int j = 0; j != 15; ++j) {
				if (lvl1[i][j] == '@') {
					xCoord = i;
					y = j;
					return xCoord;
				}
			}
		}
	}
	
}

bool isWall(int x, int y, int lvl) {
	if (lvl == 1) {
		if (lvl1[x][y] == '#') {
			cout << "\n\t\t\tIlerleyemezsin! Duvar var .";
			Sleep(400);
			system("CLS");
			printLevel(lvl);
			return true;
		}
		else {
			return false;
		}
	}
	
}

int getX(int lvl, int &y) {
	int xCoord;
	if (lvl == 1) {
		for (int i = 0; i != 15; ++i) {
			for (int j = 0; j != 15; ++j) {
				if (lvl1[i][j] == 'X') {
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
	
}

void makeSpace(int lvl, int x, int y) {
	if (lvl == 1) {
		lvl1[x][y] = space;
	}
	
}