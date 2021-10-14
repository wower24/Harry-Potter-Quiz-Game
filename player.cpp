#include "player.h"

Player::Player()
{
	this->id = vID + 1;
	vID++;
	this->name = "Default Player";
	this->score = 0;
	//players.push_back(this);
}

Player::Player(std::string vName)
{
	this->id = vID + 1;
	vID++;
	this->name = vName;
	this->score = 0;
	//players.push_back(this);
}

Player::~Player()
{
	
}

void Player::printScore()
{
	std::cout << "\nGreat Job " << this->name << "!\nYou've got " << this->score << " points out of 10\n";
}