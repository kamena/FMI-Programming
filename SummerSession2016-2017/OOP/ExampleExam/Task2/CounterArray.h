#pragma once
#include "Counters.h"

template <typename T>
class CounterArray {
    Counters<T>* countersData_;
    int countersCount_;
public:
    CounterArray();
    virtual ~CounterArray();
    CounterArray(const Counters<T>* countersData);

	const T& operator[](int idx) const;

	T& leastRead();

	void statistics();
};
