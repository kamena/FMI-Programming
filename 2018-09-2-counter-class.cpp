#include <iostream>

using namespace std;

class Counter {
private:
    static int count;

public:
    Counter() {
        count++;
    }
    
    ~Counter() {
        count--;
    }
    
    Counter(const Counter &c) {
        count++;
    }
    
    Counter& operator=(const Counter& other) {
        count = other.GetObjCount();
    }
    
    static int GetObjCount() {
        return count;
    }
};

int Counter::count = 0;

int main()
{
    cout << Counter::GetObjCount() << endl; // 0
    Counter* p = new Counter[10];
    cout << Counter::GetObjCount() << endl; // 10
    delete[] p;
    cout << Counter::GetObjCount() << endl; // 0
    Counter a, b;
    Counter c = a;
    a = b;
    cout << Counter::GetObjCount(); // 3
    return 0;
}
