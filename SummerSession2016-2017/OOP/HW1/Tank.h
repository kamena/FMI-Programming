#pragma once

class Tank {
private:
	int capacity_;
public:
	Tank();
	Tank(int capacity);

	int getCapacity();

	void setCapacity(int capacity);
};