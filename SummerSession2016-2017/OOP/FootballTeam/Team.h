#pragma once

class Team {
	string teamName_;
	Player* players_;
	int playersCount_;
	int capacity_;
	int budget_;

	void teamResize(int capacity);
public:
	// Constructor & Destructor:
	Team();
	Team(string teamName, Player* players, int playersCount, int budget);
	~Team();

	// Getters & setters:
	string getTeamName();
	int getPlayersCount();
	int getCapacity();
	int getBudget();

	void setTeamName(string name);
	void setPlayers(Player* players, int playersCount);
	void setPlayersCount(int playersCount);
	void setBudget(int budget);

	void addPlayer(Player& player);

	void printTeamInfo();

	void isBudgetEnough();

	// int getPlayerIndex(string name);
	// void printPlayersInfo(string name);
};