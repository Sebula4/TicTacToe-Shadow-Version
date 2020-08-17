// Boards.h : specification file
//

#ifndef BOARDS_H
#define BOARDS_H
#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm> //for random function
#include <cstdlib>
#include <ctime> //for time function
using namespace std;


//Player Class Declaration

class Boards
{
private:
	char b1[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //standard board
	int bConversion[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	char b2[9]; //shadow board

public:
	Boards::Boards() //construnctor
	{
		random_shuffle(std::begin(bConversion), std::end(bConversion)); //randomly shuffle the array based on system time.
		for (int i = 0; i < 9; i++) {
			b2[i] = b1[bConversion[i]]; //assign the characters based on the index of a randomly shuffled array.
		}
	}

	//setters
	void setB1(int i, char x) //get the character
		{b1[i] = x;}
	void setB2(int i, char x) //get the character
		{b2[i] = x;}
	void updateBoard(int i, char x) {
		setB1((i), x);
		setB2(getConvIndex(i), x); //find the index of the number in the randomly shuffled array.
	}

	//getters
	char getB1(int i) //get the character
		{return b1[i];}
	char getB2(int i) //get the character
		{return b2[i];}
	int getConvIndex(int i) { //find the index used to convert the numbers from the randomly shuffled array.
		for (int j = 0; j < 9; j++) {
			if (i == bConversion[j]) {
				return j;
			}
		}
	}
	
	//test to show arrays. Not used in the game, for testing purposes only.
	void getArray() {
		for (int i = 0; i < 9; i++) {
			cout << "array 1: " << getB1(i) << "  array 2: " << getB2(i) <<endl;
		}
	}

	
	//Win check. Checks both boards using the win(char) method.
	bool Win() {
		bool won = false;
		if (Win(b1) || Win(b2))
			won = true;
		return won;			
	}

	//Win conditions for horizontal, vertical, and diagnal.
	bool Win(char b[9]) {
		if (b[0] == b[3] && b[0] == b[6]) {
			return true;
		}
		else if (b[1] == b[4] && b[01] == b[7]) {
			return true;
		}
		else if (b[2] == b[5] && b[2] == b[8]) {
			return true;
		}
		else if (b[0] == b[1] && b[0] == b[2]) {
			return true;
		}
		else if (b[3] == b[4] && b[3] == b[5]) {
			return true;
		}
		else if (b[6] == b[7] && b[6] == b[8]) {
			return true;
		}
		else if (b[0] == b[4] && b[0] == b[8]) {
			return true;
		}
		else if (b[2] == b[4] && b[2] == b[6]) {
			return true;
		}
		else
			return false;
	}
	
	//Display the board
	void showBoards() {
		cout << "Main Board: " << endl;
		cout << "   |   |   " << endl;
		cout << " " << getB1(0) << " | " << getB1(1) << " | " << getB1(2) << " " << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << getB1(3) << " | " << getB1(4) << " | " << getB1(5) << " " << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << getB1(6) << " | " << getB1(7) << " | " << getB1(8) << " " << endl;
		cout << "   |   |   " << endl;

		cout << "Shadow Board: " << endl;
		cout << "   |   |   " << endl;
		cout << " " << getB2(0) << " | " << getB2(1) << " | " << getB2(2) << " " << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << getB2(3) << " | " << getB2(4) << " | " << getB2(5) << " " << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << getB2(6) << " | " << getB2(7) << " | " << getB2(8) << " " << endl;
		cout << "   |   |   " << endl;
	}

};
#endif
