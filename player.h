#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

extern int vID = 0; //the basic ID

class Player
{
	int id{};
public:
	std::string name{};
	int score{};
	Player();
	Player(std::string vName);
	~Player();
	void printScore();
};

std::vector<Player> players;

#endif 