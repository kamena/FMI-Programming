#include "Employee.h"

Employee::Employee() {
	this->name_ = new char[strlen("Kamena") + 1];
	strcpy(this->name_, "Kamena");
	years_ = 18;
	salary_ = 3500;
	positionType_ = PROGRAMMER;
}

Employee::Employee(const char* name, int years, int salary, PositionType positionType) {
	this->name_ = new char[strlen(name) + 1];
	strcpy(this->name_, name);
	years_ = years;
	salary_ = salary;
	positionType_ = positionType;
}

Employee::~Employee() {
	delete [] name_;
}

Employee& Employee::operator=(const Employee& other) {
	if(this == &other) return *this;
	delete [] this->name_;
	this->name_ = new char[strlen(other.name_) + 1];
	strcpy(this->name_, other.name_);
	this->years_ = other.years_;
	this->salary_ = other.salary_;
	this->positionType_ = other.positionType_;

	return *this;
}

Employee::Employee(const Employee& other) {
	this->years_ = other.years_;
	this->name_ = new char[strlen(other.name_) + 1];
	strcpy(name_, other.name_);
	this->salary_ = other.salary_;
	this->positionType_ = other.positionType_;
}

char* Employee::getName(){
	return this->name_;
}
int Employee::getYears(){
	return this->years_;
}
int Employee::getSalary(){
	return this->salary_;
}
PositionType Employee::getPositionType(){
	return this->positionType_;
}

void Employee::setName(const char* name){
	this->name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}
void Employee::setYears(int years){
	this->years_ = years;
}
void Employee::setSalary(int salary){
	this->salary_ = salary;
}
void Employee::setPositionType(PositionType positionType){
	this->positionType_ = positionType;
}

int Employee::calcYearSalary(){
	return this->salary_ * 12;
}
void Employee::raiseSalary(double percent){
	this->salary_ = this->salary_ * (1 + percent / 100);
}
void Employee::reduceSalary(double percent){
	this->salary_ = this->salary_ * (1 - percent / 100);
}