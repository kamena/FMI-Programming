#include "Employee.h"

void Employee::copyEmployee(const Employee& other){
	this->name_ = new char[strlen(other.name_) + 1];
	strcpy(this->name_, other.name_);

	this->address_ = new char[strlen(other.address_) + 1];
	strcpy(this->address_, other.address_);

	this->egn_ = other.egn_;

	this->department_ = new char[strlen(other.department_) + 1];
	strcpy(this->department_, other.department_);

	this->salary_ = other.salary_;
}

void Employee::deleteEmployee() {
	delete [] this->name_;
	delete [] this->address_;
	delete [] this->department_;
}

Employee::Employee(){
	this->name_ = NULL;
	this->address_ = NULL;
	this->egn_ = 0;
	this->department_ = NULL;
	this->salary_ = 0;
}
Employee::Employee(const char* name, const char* address, int egn, const char* department, int salary){
	this->name_ = new char[strlen(name) + 1];
	strcpy(this->name_, name);

	this->address_ = new char[strlen(address) + 1];
	strcpy(this->address_, address);

	this->egn_ = egn;

	this->department_ = new char[strlen(department_) + 1];
	strcpy(this->department_, department_);

	this->salary_ = salary;	
}
Employee::Employee(const Employee& other){
	copyEmployee(other);
}
Employee::~Employee(){
	deleteEmployee();
}

Employee& Employee::operator=(const Employee& other){
	if(this == &other) {
		return *this;
	}
	deleteEmployee();

	copyEmployee(other);

	return *this;
}

char* Employee::getName(){
	return this->name_;
}
char* Employee::getAddress(){
	return this->address_;
}
int Employee::getEGN(){
	return this->egn_;
}
char* Employee::getDepartment(){
	return this->department_;
}
int Employee::getSalary(){
	return this->salary_;
}

void Employee::setName(char* name){
	this->name_ = new char[strlen(name) + 1];
	strcpy(this->name_, name);
}
void Employee::setAddress(char* address){
	this->address_ = new char[strlen(address) + 1];
	strcpy(this->address_, address);
}
void Employee::setEGN(int egn){
	this->egn_ = egn;
}
void Employee::setDepartment(char* department){
	this->department_ = new char[strlen(department) + 1];
	strcpy(this->department_, department);
}
void Employee::setSalary(int salary){
	this->salary_ = salary;
}