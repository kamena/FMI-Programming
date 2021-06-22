#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        cout << "Base::Base\n";
    }
    ~Base() {
        cout << "Base::~Base\n";
    }
    virtual void f() {
        cout << "Base::f\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived::Derived\n";
    }
    ~Derived() {
        cout << "Derived::~Derived\n";
    }
    virtual void f() {
        cout << "Derived::f\n";
    }
};

int main()
{
    // Other option
    // Base p;
    /*
      Base::Base
      Base::~Base
    */
    // p.f(); /* Base::f */
    // delete &p;
    
    // A)
    Base *p = new Derived();
    /*
      Base::Base
      Derived::Derived
    */
    p->f(); /*Derived::f*/
    delete p; /* Base::~Base */
    Derived d;
    /*
      Base::Base
      Derived::Derived
      Derived::~Derived
      Base::~Base
    */
    Base b = d; /* Base::~Base */
    b.f(); /* Base::f */
    
    cout << "B)\n";
    
    // B)
    Base *arr = new Base[3]; // Will create 3 Base - Base::Base Base::Base Base::Base
    delete[] arr; // will delete all 3 Base - Base::~Base Base::~Base Base::~Base
    delete[] arr; // Error: double free or corruption
    return 0;
}
