#include "Tank.h"

Tank::Tank() {
	capacity_ = 0;
}

Tank::Tank(int capacity) {
	capacity_ = capacity;
}

int Tank::getCapacity(){
	return capacity_;
}

void Tank::setCapacity(int capacity){
	capacity_ = capacity;
}
