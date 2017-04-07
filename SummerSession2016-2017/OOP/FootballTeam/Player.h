#pragma once

class Player {
	// Team team_;
	string name_;
	int position_;
	int number_;
	int salary_;
public:
	// Constructor & Destructor:
	Player();
	Player(string name, int position, int number, int salary);

	// Getters & setters:
	string getName();
	int getPosition();
	int getNumber();
	int getSalary();

	void setName(string name);
	void setPosition(int position);
	void setNumber(int number);
	void setSalary(int salary);

	void copyPlayer(Player& other);
	// void printPlayerInfo();
};