#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b;
	double c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	c = sqrt((a*a)+(b*b));

	if ( c > 2 ) {

		int a1 = a;
		int b1 = b - 3;

		double c1 = sqrt((a1*a1)+(b1*b1));
		if (c1 > 1) {
			cout << 0;
		} else {
			cout << 1;
		}

	} else {
		cout << 1;
	}

	cout << endl;

	return 0;
}