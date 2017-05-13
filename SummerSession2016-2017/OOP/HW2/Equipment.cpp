#include "Equipment.h"

Equipment::Equipment() {
	this->name_ = new char[strlen("Computer") + 1];
	strcpy(this->name_, "Computer");
	this->price_ = 1000;
	this->expenses_ = 1000;
}

Equipment::Equipment(const char* name, double price, double expenses) {
	this->name_ = new char[strlen(name) + 1];
	strcpy(this->name_, name);
	this->price_ = price;
	this->expenses_ = expenses;
}

Equipment::~Equipment() {
	delete [] name_;
}

Equipment& Equipment::operator=(const Equipment& other) {
	if(this == &other) return *this;
	delete [] this->name_;
	this->name_ = new char[strlen(other.name_) + 1];
	strcpy(this->name_, other.name_);
	this->price_ = other.price_;
	this->expenses_ = other.expenses_;

	return *this;
}

Equipment::Equipment(const Equipment& other) {
	this->name_ = new char[strlen(other.name_) + 1];
	strcpy(name_, other.name_);
	this->price_ = other.price_;
	this->expenses_ = other.expenses_;
}

char* Equipment::getName(){
	return this->name_;
}

double Equipment::getPrice() {
	return this->price_;
}

double Equipment::getExpenses() {
	return this->expenses_;
}

void Equipment::setName(const char* name){
	this->name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

void Equipment::setPrice(double price) {
	this->price_ = price;
}

void Equipment::setExpenses(double expenses) {
	this->expenses_ = expenses;
}
