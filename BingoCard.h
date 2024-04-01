#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <time.h>
#include <random>
#include <algorithm>
using namespace std;

class BingoCard
{
private:
	vector<vector<int>*> *board;
	vector<vector<bool>*> *marked;
	int board_size;
	void fill();
	bool checkVertical();
	bool checkHorizontal();
	bool checkDiagonal();
public:
	BingoCard(int);
	string toString();
	void call(int);
	void clearBoard();
	bool checkBingo();

};

int randomfunc(int j);
int badRand(int j);
