// Player.h : specification file
//

#ifndef PLAYER_H
#define PLAYER_H
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


//Player Class Declaration

class Player
{
private:
	char pChar; //store the players chosen character
	int wins; //count the number of wins
	bool computer; //determine if the player is a computer
public:
	Player::Player(char c) //default construnctor
	{
		pChar = c; //set the character
		wins = 0;
		computer = false;
	}

	//setters
	void setCh(char p) //set the character
		{pChar = p;}
	void setComp(bool b) //set if a computer is playing
		{computer=b;}
	void winUp()
		{wins++;} //increase wins by 1;

	//getters
	char getCh() //get the character
		{return pChar;}
	bool getComp()
		{return computer;} //get if a computer is playing
	int getWins()
		{return wins;} //get number of wins

};
#endif
