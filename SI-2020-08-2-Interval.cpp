#include <iostream>
#include <vector>

using namespace std;

class Interval {
    int cur_index = 0;
    vector<int> interval;
public:
    Interval(int a, int k) {
        for (int i = 0; i <= k; i++) {
            interval.push_back(a + i);
        }
    }
    int operator*() {
        return interval[cur_index];
    }
    void operator++() {
        if (!last()) cur_index++;
    }
    void reset() {
        cur_index = 0;
    }
    bool last() {
        return cur_index == interval.size() - 1;
    }
};

class SquaredInterval : public Interval {
public:
    SquaredInterval(int a, int k) : Interval(a, k) {};
    int operator*() {
        return Interval::operator*() * Interval::operator*();
    }
};

int main()
{
    Interval i(0,10);
    cout << *i << " ";
    do {
        ++i;
        cout << *i << " ";
    } while (!i.last());
    cout << endl;

    SquaredInterval si(0, 10);
    cout << *si << " ";
    do {
        ++si;
        cout << *si << " ";
    } while (!si.last());

    return 0;
}
