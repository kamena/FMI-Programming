#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	if ( (a == 0) || (b == 0) ) { // if !(a && b)
		cout << "Leji na os";
	} else if ( a > 0 ) {
		if ( b > 0 ) {
			cout << 1;
		} else {
			cout << 4;
		}
	} else if ( a < 0 ) {
		if ( b > 0 ) {
			cout << 2;
		} else {
			cout << 3;
		}
	}

	cout << endl;

	return 0;
}