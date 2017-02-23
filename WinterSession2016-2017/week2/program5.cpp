#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;

	int first, second;
	first = a % 10;
	a = a / 10;
	second = a % 10;
	a = a / 10;

	if ( ( first == second ) || ( second == a ) ) {
		cout << "1";
	} else {
		cout << "0";
	}

	cout << endl;

	return 0;
}
