#pragma once
#include "Gearbox.h"

class Transmission {
private:
	Gearbox type_;
	int gearLevel_;
public:
	Transmission();
	Transmission(Gearbox type, int gearLevel);

	Gearbox getGearbox();
	int getGearLevel();

	void setGearbox(Gearbox type);
	void setGearLevel(int gearLevel);
};
