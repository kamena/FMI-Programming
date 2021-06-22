#include <iostream>

using namespace std;
class Base {
public:
    static Base& getInstance() {
        static Base instance;
        return instance;
    } 
private:
    Base() {}
    Base (const Base &);
    Base & operator=(const Base &);
};

class Derived : public Base {};

int main() {
    Base& b1 = Base::getInstance();
    Base& b2 = Base::getInstance();
    
    cout << (&b1 == &b2);
    return 0;
}
