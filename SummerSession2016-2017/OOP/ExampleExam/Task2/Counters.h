#pragma once

template <typename T>
class Counters {
    T x_;
    int countRead_;
    int countChange_;
public:
    Counters();
    Counters(T& x, int countRead, int countChange);

    Counters& operator+=(const Counters& other);

    int getCountRead();
    int getCountChange();
};
