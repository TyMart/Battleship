#include "Player.h"

void Player::update_probabilities(int current_board[10][10]) {

}

void Player::search_for_battleship(int board[10][10]) {
	//Search side to side
	int current_position[5];
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10 - 5; x++) {
			//Get the comparison array
			for (int i = 0; i < 5; i++) {
				current_position[i] = board[x + i][y];
			}
			//Sort the array and see if they match
			sort_array(current_position, 5);
			bool not_possible = false;
			for (int i = 0; i < 5; i++) {
				if (battleship[i] != current_position[i]) {
					not_possible = true;
				}
			}
			if (!not_possible) {
				for (int i = 0; i < 5; i++) {
					probability_board[x+i][y]++;
				}
			}

		}
	}
}

void Player::search_ship(int board[10][10], int ship[], int ship_size) {
	sort_array(ship, ship_size);
	int possible_locations = 0;
	int temp_probability_board[10][10];
	//Initialize the temp_probability board
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			temp_probability_board[i][j] = 0;
		}
	}
	//Iterate over the entire board
	int* current_base;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			//Check to see if sideways is within bounds
			if (x + ship_size-1 < 10) {
				
				//If within bounds, get the array of the size of the ship
				current_base = new int[ship_size];
				//cout << "Current_Base[" << x << "][" << y << "]: ";
				for (int i = 0; i < ship_size; i++) {
					current_base[i] = board[x + i][y];
					//cout << current_base[i];
				}
				//cout << endl;
				//Sort the array and compare to the ship array
				sort_array(current_base, ship_size);
				bool possible = true;
				for (int i = 0; i < ship_size; i++) {
					if (current_base[i] != ship[i]) {
						possible = false;
					}
				}
				//If the location remains a possibility, add one to the possible locations and increment the temp probability board
				if (possible) {
					cout << "Posibility Pre: " << possible_locations << endl;
					possible_locations++;
					cout << "Posibility Post: " << possible_locations << endl;
					for (int i = 0; i <= ship_size; i++) {
						temp_probability_board[x + i][y]++;
					}
				}
			}
			/*
			//Check to see if up/down is within bounds
			if (y + ship_size < 10) {
				//If within bounds, get the array of the size of the ship
				current_base = new int[ship_size];
				for (int i = 0; i < ship_size; i++) {
					current_base[i] = board[x][y+i];
				}
				//Sort the array and compare to the ship array
				sort_array(current_base, ship_size);
				bool possible = true;
				for (int i = 0; i < ship_size; i++) {
					if (current_base[i] != ship[i]) {
						possible = false;
					}
				}
				//If the location remains a possibility, add one to the possible locations and increment the temp probability board
				if (possible) {
					possible_locations++;
					for (int i = 0; i < ship_size; i++) {
						temp_probability_board[x][y+i]++;
					}
				}
			}

			//Check to see if diagnal down is within bounds
			if ((x + ship_size < 10) && (y + ship_size < 10)) {
				//If within bounds, get the array of the size of the ship
				current_base = new int[ship_size];
				for (int i = 0; i < ship_size; i++) {
					current_base[i] = board[x + i][y + i];
				}
				//Sort the array and compare to the ship array
				sort_array(current_base, ship_size);
				bool possible = true;
				for (int i = 0; i < ship_size; i++) {
					if (current_base[i] != ship[i]) {
						possible = false;
					}
				}
				//If the location remains a possibility, add one to the possible locations and increment the temp probability board
				if (possible) {
					possible_locations++;
					for (int i = 0; i < ship_size; i++) {
						temp_probability_board[x + i][y + i]++;
					}
				}
			}
			*/
		}
	}
	print_board(temp_probability_board);
	cout << "Total Possibilities: " << possible_locations << endl;
}

void Player::print_board(int board[10][10]) {
	for (int y = 0; y < 10; y++) {
		cout << "[";
		for (int x = 0; x < 10; x++) {
			cout << board[x][y];
			if (x < 9) {
				cout << ",";
			}
			else {
				cout << "]";
			}
		}
		cout << endl;
	}
}

void Player::sort_array(int* a, int size) {
	int c = 0;
	while (c != size - 1) {
		if (a[c] > a[c + 1]) {
			int temp = a[c];
			a[c] = a[c + 1];
			a[c + 1] = temp;
			c = 0;
		}
		else {
			c++;
		}
	}
}