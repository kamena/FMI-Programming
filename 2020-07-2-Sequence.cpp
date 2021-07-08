#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<class T>
class Sequence {
protected:
    T *curr;
    int curr_index;
    vector<T> sequence;
    int size;
public:
    Sequence() {};
    Sequence(T a, T d, int n) {
        this->createSequence(a, d, n);
        curr = &sequence[0];
        curr_index = 0;
        size = n;
    }
    
    void createSequence(T a, T d, int n) {
       for (int i = 0; i <= n; i++) {
            sequence.push_back(a + i * d);
        } 
    }

    T current() {
        T current_to_return = *curr;
        curr = &sequence[curr_index + 1];
        return current_to_return;
    }

    void next() {
        if (curr_index == size) return;
        curr_index++;
    }

    bool last() {
        return curr_index == size;
    }
};

template<class T>
class MappedSequence : public Sequence<T> {
public:
    MappedSequence(T a, T d, int n, int (*function)(int)) {
        for (int i = 0; i <= n; i++) {
            this->sequence.push_back(function(a + i * d));
        } 
        this->curr = &this->sequence[0];
        this->curr_index = 0;
        this->size = n;
    }
};

int square(int x) { return x * x; }

int main() {
    Sequence<int> s(0, 1, 10);
    cout << s.current() << " ";
    do {
        s.next();
        cout << s.current() << " ";
    } while (!s.last());
    cout << endl;

    MappedSequence<int> ms(0, 1, 10, square);
    cout << ms.current() << " ";
    do {
        ms.next();
        cout << ms.current() << " ";
    }
    while (!ms.last());
    cout << endl;
    return 0;
}
