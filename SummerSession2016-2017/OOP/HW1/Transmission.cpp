#include "Transmission.h"

Transmission::Transmission() {
	type_ = MANUAL;
	gearLevel_ = 6;
}

Transmission::Transmission(Gearbox type, int gearLevel) {
	this->type_ = type;
	gearLevel_ = gearLevel;
}

Gearbox Transmission::getGearbox(){
	return this->type_;
}

int Transmission::getGearLevel(){
	return gearLevel_;
}

void Transmission::setGearbox(Gearbox type) {
	type_ = type;
}

void Transmission::setGearLevel(int gearLevel){
	gearLevel_ = gearLevel;
}
