#pragma once

class Specialist : public Employee {
	char* specialty_;
public:
	Specialist();
	Specialist(const char* specialty, Employee& employee);
	Specialist(const Specialist& other);
	~Specialist();

	Specialist& operator=(const Specialist& other);

	char* getSpecialty();

	void setSpecialty(char*);
};
