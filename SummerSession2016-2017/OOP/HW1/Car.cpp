#include "Car.h"
#include <ctime>
#include <iostream>

Car::Car() {
	numSeats_ = 4;
	yearMade_ = 2002;
}

Car::Car(int numSeats, int yearMade, Engine& engine, Tank& tank, Transmission& transmission) {
	numSeats_ = numSeats;
	yearMade_ = yearMade;
	engine_ = engine;
	tank_ = tank;
	transmission_ = transmission;
}

int Car::getNumSeats(){
	return numSeats_;
}
int Car::getYearMade(){
	return yearMade_;
}
Engine& Car::getEngine(){
	return engine_;
}
Tank& Car::getTank(){
	return tank_;
}
Transmission& Car::getTransmission(){
	return transmission_;
}

void Car::setNumSeats(int numSeats){
	numSeats_ = numSeats;
}
void Car::setYearMade(int yearMade){
	yearMade_ = yearMade;
}
void Car::setEngine(Engine& engine){
	engine_ = engine;
}
void Car::setTank(Tank& tank){
	tank_ = tank;
}
void Car::setTransmission(Transmission& transmission){
	transmission_ = transmission;
}

double Car::calculateEmissions(){
	return this->engine_.getHp() * this->engine_.getVolume() * this->engine_.getEngineType();
}
double Car::calculateTax(){
	int carHp = this->engine_.getHp();
	double tax;
	int carYear = getYearMade();

	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	int yearToday = timePtr->tm_year + 1900;
	int carYearOld = yearToday - carYear;

	if (carHp <= 105) {
		tax = (double)carHp * 0.8;
	} else {
		tax = (double)carHp * 0.9;
	}

	if (carYearOld > 5 && carYearOld < 14) {
		tax *= 1.5;
	} else if (carYearOld <= 5) {
		tax *= 2.8;
	}

	return tax;

}
double Car::fuelConsumption(){
	return ( this->transmission_.getGearLevel() * this->engine_.getHp() * ( (double)this->engine_.getVolume() / 1000 ) ) / 100;
}
double Car::maxAvailablePath(){
	return ( this->tank_.getCapacity() / this->fuelConsumption() ) / 100;
}

int Car::calcGear(int speed) {
	int gear = this->transmission_.getGearLevel();

	if (speed > 0 && speed <= 20) {
		return 1;
	} else if (speed > 20 && speed <= 30) {
		return 2;
	} else if (speed > 30 && speed <= 50) {
		if (gear < 3) return gear;
		return 3;
	} else if (speed > 50 && speed <= 80) {
		if (gear < 4) return gear;
		return 4;
	} else if (speed > 80 && speed <= 200) {
		if (gear < 5) return gear;
		return 5;
	} else if (speed > 200) {
		if (gear < 6) return gear;
		return 6;
	} else return 0;
}