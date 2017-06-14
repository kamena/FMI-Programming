#include "CounterArray.h"

template <typename T>
const T& CounterArray<T>::operator[](int idx) const {
	if ( idx >= 0 && idx <= this->countersCount_ ) {
		return this->countersData_[idx];
	} else return;
}

template <typename T>
T& CounterArray<T>::leastRead() {
	T& leastReadValue = this->countersData_[0];
	for(int i = 1; i < this->countersCount_; i++) {
		if(this->countersData_[i].getCountRead() < leastReadValue.getCountRead()) {
			leastReadValue = this->countersData_[i];
		}
	}
	return leastReadValue;
}

template <typename T>
void CounterArray<T>::statistics() {
	//TODO: statistics, която използва операцията +=, за да изведе статистика за използването всеки уникален елемент от масива.
	// for(int i = 0; i < this->countersCount_; i++) {
	// 	T& compareThis = this->countersData_[i];
	// 	for(int j = 1; j < this->countersCount_; j++) {

	// 	}
	// }
}