#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<class T>
class Sequence {
private:
    int curr_index = 0;
protected:
    vector<T> sequence;
public:
    Sequence() {};
    Sequence(T a, T d, int n) {
        for (int i = 0; i <= n; i++) {
            sequence.push_back(a + i * d);
        }
    }

    T current() {
        return sequence[curr_index];
    }

    void next() {
        if (last()) return;
        curr_index++;
    }

    bool last() {
        return curr_index == sequence.size() - 1;
    }
};

template<class T>
class MappedSequence : public Sequence<T> {
public:
    MappedSequence(T a, T d, int n, int (*function)(int)) {
        for (int i = 0; i <= n; i++) {
            this->sequence.push_back(function(a + i * d));
        } 
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
