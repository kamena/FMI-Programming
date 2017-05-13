#include "Company.h"

const int DEFAULT_CAP = 16;

Company::Company() {
	this->name_ = new char[strlen("Company Name") + 1];
	strcpy(this->name_, "Company Name");
	employees_ = new Employee[DEFAULT_CAP];
	employeesCount_ = 0;
	employeesCapacity_ = DEFAULT_CAP;
	equipments_ = new Equipment[DEFAULT_CAP];
	equipmentsCount_ = 0;
	equipmentCapacity_ = DEFAULT_CAP;
}

Company::Company(const char* name, Employee* employees, int employeesCount, Equipment* equipments, int equipmentsCount) {
	this->name_ = new char[strlen(name) + 1];
	strcpy(this->name_, name);

	if(employeesCount >= DEFAULT_CAP) {
		this->employeesCapacity_ = employeesCount * 2;
	} else {
		this->employeesCapacity_ = DEFAULT_CAP;
	}
	employees_ = new Employee[employeesCapacity_];
	for (int i = 0; i < employeesCount; ++i) {
		employees_[i] = employees[i];
	}
	employeesCount_ = employeesCount;	

	if(equipmentsCount >= DEFAULT_CAP) {
		this->equipmentCapacity_ = equipmentsCount * 2;
	} else {
		this->equipmentCapacity_ = DEFAULT_CAP;
	}
	equipments_ = new Equipment[equipmentCapacity_];
	for (int i = 0; i < equipmentsCount; ++i) {
		equipments_[i] = equipments[i];
	}
	equipmentsCount_ = equipmentsCount;	

}

Company::~Company() {
	delete [] name_;
	delete [] employees_;
	delete [] equipments_;
}

Company::Company(const Company& other) {

}

char* Company::getName() {
	return this->name_;
}
Employee* Company::getEmployees() {
	return this->employees_;
}
int Company::getEmployeesCount() {
	return this->employeesCount_;
}
Equipment* Company::getEquipments() {
	return this->equipments_;
}
int Company::getEquipmentsCount() {
	return this->equipmentsCount_;
}

void Company::setName(const char* name) {
	this->name_ = new char[strlen(name) + 1];
	strcpy(this->name_, name);
}
void Company::setEmployees(Employee* employees) {
	this->employees_ = new Employee[this->employeesCount_];
	for(int i = 0; i < this->employeesCount_; i++) {
	    this->employees_[i] = employees[i];
	}
}
void Company::setEmployeesCount(int employeesCount) {
	this->employeesCount_ = employeesCount;
}
void Company::setEquipments(Equipment* equipments) {
	this->equipments_ = new Equipment[this->equipmentsCount_];
	for(int i = 0; i < this->equipmentsCount_; i++) {
	    this->equipments_[i] = equipments[i];
	}
}
void Company::setEquipmentsCount(int equipmentsCount) {
	this->equipmentsCount_ = equipmentsCount;
}

int Company::countAllSalary() {
	int sum = 0;
	for(int i = 0; i < this->employeesCount_; i++) {
		sum += this->employees_[i].getSalary();
	}
	return sum;
}
double Company::countAllExpenses() {
	double sum = 0;
	for(int i = 0; i < this->equipmentsCount_; i++) {
		sum += this->equipments_[i].getExpenses();
	}
	return sum;
}
void Company::raiseEmployeeSalary(const char* name, int percent) {
    for(int i = 0; i < employeesCount_; i++) {

        if( !strcmp(employees_[i].getName(), name) ) {
            employees_[i].setSalary(employees_[i].getSalary() * (1 + percent / 100));
            break;
        }
    }
}
void Company::reduceEmployeeSalary(const char* name, int percent) {
    for(int i = 0; i < employeesCount_; i++) {
        if( !strcmp(employees_[i].getName(), name) ) {
            employees_[i].setSalary( employees_[i].getSalary() * (1 - percent / 100) );
            break;
        }
    }
}
void Company::raiseAllSalaries(int percent) {
	for(int i = 0; i < employeesCount_; i++) {
		employees_[i].setSalary( employees_[i].getSalary() * (1 + percent / 100) );
	}
}
void Company::reduceAllSalaries(int percent) {
	for(int i = 0; i < employeesCount_; i++) {
		employees_[i].setSalary( employees_[i].getSalary() * (1 - percent / 100) );
	}
}

void Company::resizeEmployees(int capacity){
	Employee* temp = new Employee[capacity];
    for (int i = 0; i < this->employeesCount_; ++i) {
       temp[i] = this->employees_[i];
    }

    delete[] this->employees_;
    this->employees_ = temp;
	this->employeesCapacity_ = capacity;
}

void Company::resizeEquipment(int capacity) {
	Equipment* temp = new Equipment[capacity];
    for (int i = 0; i < this->equipmentsCount_; ++i) {
       temp[i] = this->equipments_[i];
    }

    delete[] this->equipments_;
    this->equipments_ = temp;
	this->equipmentCapacity_ = capacity;
}

void Company::addEmployee(Employee& employee) {
	if(this->employeesCount_ >= this->employeesCapacity_) {
		this->resizeEmployees(this->employeesCapacity_ * 2);
	}
	employees_[employeesCount_] = employee;
	employeesCount_++;
}
void Company::addEquioment(Equipment& equipment) {
	if(this->equipmentsCount_ >= this->equipmentCapacity_) {
		this->resizeEquipment(this->equipmentCapacity_ * 2);
	}
	equipments_[equipmentsCount_] = equipment;
	equipmentsCount_++;
}

void Company::printCompanyInfo() {
	cout << "Company name: " << this->name_ << endl;
	cout << "--------------------------------------\n";
	cout << "Employees (" << this->employeesCount_ << "): " << endl;
	for(int i = 0; i < employeesCount_; i++) {
		cout << this->employees_[i].getName() << "\t: " << employees_[i].getSalary() << endl; 
	}
	cout << "Equipments (" << this->equipmentsCount_ << "): " << endl;
	for(int i = 0; i < equipmentsCount_; i++) {
		cout << this->equipments_[i].getName() << "\t: " << equipments_[i].getExpenses() << endl; 
	}
	cout << "--------------------------------------\n";
	cout << "Total for salaries: " << this->countAllSalary() << endl;
	cout << "Total for expenses: " << this->countAllExpenses() << endl;
}