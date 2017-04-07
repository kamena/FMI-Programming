#include <string>

#include "Player.h"

Player::Player() {
	name_ = "Kamena";
	position_ = 3;
	number_ = 12;
	salary_ = 5000;
}

Player::Player(string name, int position, int number, int salary) {
	name_ = name;
	position_ = position;
	number_ = number;
	salary_ = salary;
}

string Player::getName(){
	return this->name_;
}
int Player::getPosition(){
	return this->position_;
}
int Player::getNumber(){
	return this->number_;
}
int Player::getSalary(){
	return this->salary_;
}

void Player::setName(string name){
	name_ = name;
}
void Player::setPosition(int position){
	position_ = position;
}
void Player::setNumber(int number){
	number_ = number;
}
void Player::setSalary(int salary){
	salary_ = salary;
}

void Player::copyPlayer(Player& other){
	name_ = other.getName();
	position_ = other.getPosition();
	number_ = other.getNumber();
	salary_ = other.getSalary();
}