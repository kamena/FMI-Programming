#pragma once

class Company {
private:
	char* name_;
	Employee* employees_;
	int employeesCount_;
	int employeesCapacity_;
	Equipment* equipments_;
	int equipmentsCount_;
	int equipmentCapacity_;

	void resizeEmployees(int newCapcity);
	void resizeEquipment(int newCapacity);	
public:
	Company();
	Company(const char* name, Employee* employees, int employeesCount, Equipment* equipments, int equipmentsCount);
	Company(const Company& other);
	~Company();

	char* getName();
	Employee* getEmployees();
	int getEmployeesCount();
	Equipment* getEquipments();
	int getEquipmentsCount();

	void setName(const char*);
	void setEmployees(Employee*);
	void setEmployeesCount(int);
	void setEquipments(Equipment*);
	void setEquipmentsCount(int);

	int countAllSalary();
	double countAllExpenses();
	void raiseEmployeeSalary(const char* name, int percent);
	void reduceEmployeeSalary(const char* name, int percent);
	void raiseAllSalaries(int percent);
	void reduceAllSalaries(int percent);

	void addEmployee(Employee& employee);
	void addEquioment(Equipment& equipment);

	void printCompanyInfo();
};
