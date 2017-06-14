#include "Counters.h"

template <typename T>
Counters<T>::Counters() {
    x_ = new T;
    countRead_ = 0;
    countChange_ = 0;
}
   
template <typename T>
Counters<T>::Counters(T& x, int countRead, int countChange){
	x_ = x;
	countRead_ = countRead;
	countChange_ = countChange;
}

template <typename T>
Counters<T>& Counters<T>::operator+=(const Counters& other){
	if(this->x == other.x) {
		this->countRead_ += other.countRead_;
		this->countChange_ += other.countChange_;
	}
}
template <typename T>
int Counters<T>::getCountRead() {
	return countRead_;
}

template <typename T>
int Counters<T>::getCountChange() {
	return countChange_;
}