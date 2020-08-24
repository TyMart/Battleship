#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Player
{
public:
	int battleship[5] = {0,0,0,0,0};
	int cruiser[4] = {0,0,0,0};
	int destroyer[3] = {0,0,0};
	int sub[2] = {0,0};
	double probability_board[10][10];
	void update_probabilities(int current_board[10][10]);
	void search_for_battleship(int current_board[10][10]);
	void sort_array(int a[], int size);
	void search_ship(int board[10][10], int ship[], int ship_size);
	void search(int board[10][10]);
	void print_board(int board[10][10]);
	void print_board(double board[10][10]);
};

