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

	if ( c > 5 ) {
		cout << "0";
	} else {
		cout << "1";
	}

	cout << endl;

	return 0;
}