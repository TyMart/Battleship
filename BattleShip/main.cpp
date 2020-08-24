#include <iostream>
#include "Player.h"
using namespace std;

int main() {
	int board[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 0;
		}
	}
	Player me;
	//board[1][1] = 1;
	board[9][2] = 1;
	//me.print_board(board);

	cout << endl << endl;
	int ship[4] = { 1,0,0,0 };
	
	me.search_ship(board, ship, 4);
};