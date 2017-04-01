#pragma once

#include "Tank.h"
#include "Engine.h"
#include "Transmission.h"

class Car {
private:
	int numSeats_;
	int yearMade_;
	Engine engine_;
	Tank tank_;
	Transmission transmission_;
public:
	Car();
	Car(int numSeats, int yearMade, Engine& engine, Tank& tank, Transmission& transmission);

	int getNumSeats();
	int getYearMade();
	Engine& getEngine();
	Tank& getTank();
	Transmission& getTransmission();

	void setNumSeats(int numSeats);
	void setYearMade(int yearMade);
	void setEngine(Engine& engine);
	void setTank(Tank& tank);
	void setTransmission(Transmission& transmission);

	double calculateEmissions();
	double calculateTax();
	double fuelConsumption();
	double maxAvailablePath();
	int calcGear(int speed);
};
