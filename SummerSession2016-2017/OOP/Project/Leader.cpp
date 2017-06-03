#include "Specialist.h"

Specialist::Specialist(){
	this->specialty_ = NULL;
}

Specialist::Specialist(const char* specialty, Employee& employee)
: Employee(employee) {
	this->specialty_ = new char[strlen(specialty) + 1];
	strcpy(this->specialty_, specialty);
}

Specialist::Specialist(const Specialist& other) : Employee(other) {
	this->specialty_ = new char[strlen(other.specialty_) + 1];
	strcpy(this->specialty_, other.specialty_);
}

Specialist::~Specialist(){
	delete [] this->specialty_;
}

Specialist& Specialist::operator=(const Specialist& other){
	if(this == &other) return *this;
	delete [] this->specialty_;
	
	Employee::operator=(other);

	this->specialty_ = new char[strlen(other.specialty_) + 1];
	strcpy(this->specialty_, other.specialty_);

	return *this;
}

char* Specialist::getSpecialty(){
	return specialty_;
}

void Specialist::setSpecialty(char* specialty){
	this->specialty_ = new char[strlen(specialty) + 1];
	strcpy(this->specialty_, specialty);
}