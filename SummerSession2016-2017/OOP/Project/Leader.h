#pragma once

class Leader : public Specialist {
public:
	Leader();
	Leader(const char* department);
	Leader(const Leader& other);
	~Leader();

	Leader& operator=(const Leader& other);

	char* getSpecialty();
};
