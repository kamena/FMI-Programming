#pragma once

class Employee {
private:
	char* name_;
	char* address_;
	int egn_;
	char* department_;
	int salary_;

	void copyEmployee(const Employee& other);
	void deleteEmployee();
public:
	Employee();
	Employee(const char* name, const char* address, int egn, const char* department, int salary);
	Employee(const Employee& other);
	~Employee();

	Employee& operator=(const Employee& other);

	char* getName();
	char* getAddress();
	int getEGN();
	char* getDepartment();
	int getSalary();

	void setName(char* name);
	void setAddress(char* address);
	void setEGN(int egn);
	void setDepartment(char* department);
	void setSalary(int salary);
};
