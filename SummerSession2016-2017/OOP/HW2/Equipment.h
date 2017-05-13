#pragma once

class Equipment {
private:
	char* name_;
	double price_;
	double expenses_;
public:
	Equipment();
	Equipment(const char* name, double price, double expenses);
	Equipment(const Equipment& other);
	~Equipment();

	Equipment& operator=(const Equipment& other);

	char* getName();
	double getPrice();
	double getExpenses();

	void setName(const char*);
	void setPrice(double);
	void setExpenses(double);
};
