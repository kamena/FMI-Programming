#pragma once

#include "PositionType.h"

class Employee {
private:
	char* name_;
	int years_;
	int salary_;
	PositionType positionType_;
public:
	Employee();
	Employee(const char* name, int years, int salary, PositionType positionType);
	Employee(const Employee& other);
	~Employee();

	Employee& operator=(const Employee& other);

	char* getName();
	int getYears();
	int getSalary();
	PositionType getPositionType();

	void setName(const char*);
	void setYears(int);
	void setSalary(int);
	void setPositionType(PositionType);

	int calcYearSalary();
	void raiseSalary(double percent);
	void reduceSalary(double percent);
};
