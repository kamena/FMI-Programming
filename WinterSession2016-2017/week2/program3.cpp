// b * b - 4 * a * c

#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	d = b * b - 4 * a * c;

	if (d == 0) {
		cout << "Ima 1 koren";
	} else if (d > 0) {
		cout << "Ima 2 korena";
	} else {
		cout << "Error";
	}

	cout << endl;
	return 0;
}