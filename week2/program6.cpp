#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;

	int first;
	first = a % 1000;
	a = a / 1000;

	if ( a < first ) {
		cout << "1";
	} else {
		cout << "0";
	}

	cout << endl;

	return 0;
}
