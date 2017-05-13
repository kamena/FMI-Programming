#include <iostream>
#include <cstring>
using namespace std;

#include "Employee.cpp"
#include "Equipment.cpp"
#include "Company.cpp"

int main() {
	Employee employee1("Kamena", 18, 3500, PROGRAMMER);
	Employee employee2("Hristo", 20, 4000, MANAGER);
	Employee employee3("Hristina", 30, 3600, HR);

	int employeesCount = 3;
	Employee* employees = new Employee[employeesCount];

	employees[0] = employee1;
	employees[1] = employee2;
	employees[2] = employee3;

	Equipment equipment1("Equipment 1", 200.0, 150.0);
	Equipment equipment2("Equipment 2", 1500.0, 317.52);
	Equipment equipment3("Equipment 2", 214.3, 160.20);

	int equipmentsCount = 3;
	Equipment* equipments = new Equipment[equipmentsCount];

	equipments[0] = equipment1;
	equipments[1] = equipment2;
	equipments[2] = equipment3;	

	Company myCompany("My Company", employees, 3, equipments, 3);

	myCompany.printCompanyInfo();

	myCompany.raiseAllSalaries(50);

	myCompany.printCompanyInfo();

	delete [] employees;
	delete [] equipments;

	return 0;
}