/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

template<class T>
class Polynom {
private:
    T* points_;
    int n_;
    
    size_t size() const {
        int size = 0;
        while (this->points_[size]) {
            size++;
        }
        return size;
    }
public:
    Polynom(T *points, int n) {
        points_ = new T[n + 1];
        for (int i = 0; i <= n; i++) {
            this->points_[i] = points[i];
        }

        this->n_ = n;
    }
    
    Polynom &operator=(const Polynom &other) {
        return *this;
    }
    
    T operator[](const T &idx) {
        if (idx > n_ || idx < 0) {
            throw invalid_argument("The index is not valid!");
        }
        return this->points_[idx];
    }
    
    T operator()(const T &x) {
        T result = this->points_[0];
        for (int i = 1; i < this->n_; i++) {
           result += this->points_[i] * pow(x, (this->n_ - i)); 
        }
        return result;
    }
    
    friend Polynom operator+(const Polynom& lhs, const Polynom& rhs) {
        // size_t bigger = lhs.size() > rhs.size() ? lhs.size() : rhs.size();
        
        int is_lhs_bigger_n = lhs.n_ > rhs.n_;
        Polynom bigger_n = is_lhs_bigger_n ? lhs : rhs;
        Polynom smaller_n = !is_lhs_bigger_n ? lhs : rhs;
        
        T points[bigger_n.n_];
        int idx = 0;
        if (lhs.n_ != rhs.n_) {
            while (bigger_n.n_ - idx > smaller_n.n_) {
                points[idx] = bigger_n.points_[idx];
                idx++;
            }
        }
        
        /* Add offset if smaller n */
        int lhs_offset = is_lhs_bigger_n ? 0 : idx;
        int rhs_offset = is_lhs_bigger_n ? idx : 0;

        while (bigger_n.n_ - idx > 0) {
            if (lhs.points_[idx - lhs_offset] && rhs.points_[idx - rhs_offset]) {
                points[idx] = lhs.points_[idx - lhs_offset] + rhs.points_[idx - rhs_offset];
            } else {
                points[idx] = lhs.points_[idx - lhs_offset] ? lhs.points_[idx - lhs_offset] : rhs.points_[idx - rhs_offset];
            }
            idx++;
        }
        
        Polynom<int> summedPolynom(points, bigger_n.n_);
        return summedPolynom;
    }
    
    friend Polynom operator-(const Polynom& lhs, const Polynom& rhs) {
        // size_t bigger = lhs.size() > rhs.size() ? lhs.size() : rhs.size();

        int is_lhs_bigger_n = lhs.n_ > rhs.n_;
        Polynom bigger_n = is_lhs_bigger_n ? lhs : rhs;
        Polynom smaller_n = !is_lhs_bigger_n ? lhs : rhs;
        
        T points[bigger_n.n_];
        int idx = 0;
        if (lhs.n_ != rhs.n_) {
            while (bigger_n.n_ - idx > smaller_n.n_) {
                points[idx] = bigger_n.points_[idx];
                idx++;
            }
        }
        
        /* Add offset to the Polynom with smaller n */
        int lhs_offset = !is_lhs_bigger_n ? idx : 0;
        int rhs_offset = is_lhs_bigger_n ? idx : 0;

        while (bigger_n.n_ - idx > 0) {
            if (lhs.points_[idx - lhs_offset] && rhs.points_[idx - rhs_offset]) {
                points[idx] = lhs.points_[idx - lhs_offset] - rhs.points_[idx - rhs_offset];
            } else {
                points[idx] = lhs.points_[idx - lhs_offset] ? lhs.points_[idx - lhs_offset] : rhs.points_[idx - rhs_offset];
            }
            idx++;
        }

        Polynom<int> productedPolynom(points, bigger_n.n_);
        return productedPolynom;
    }
    
    friend Polynom operator*(const Polynom& pol, const T &op) {
        for (int i = 0; i < pol.n_; i++) {
            pol.points_[i] = pol.points_[i] * op;
        }
        return pol;
    }
    
    friend ostream& operator<<(ostream& os, const Polynom& pol) {
        for (int i = 0; i < pol.n_; i++) {
            os << pol.points_[i] << "x^" << pol.n_ - i << " ";
        }
        os << endl;
        return os;
    }
};

int main()
{
    int arr1[4] = {1, 2, 3, 4};
    int arr2[5] = {1, 2, 3, 4, 5};
    Polynom<int> pol1(arr1, 4);
    Polynom<int> pol2(arr2, 5);
    cout << pol1[3] << endl;
    cout << pol1[2] << endl;
    
    Polynom<int> newpol = pol1 + pol2;

    cout << pol1;
    cout << pol2;
    cout << newpol;
    
    cout << newpol(1) << endl;
    cout << pol2(2) << endl;

    return 0;
}
