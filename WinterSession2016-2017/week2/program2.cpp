// Dali se deli na 2 i 3, no ne se deli na 5

#include <iostream>

using namespace std;

int main() {
	int a;
	cout << "a = ";
	cin >> a;

	if ( (a % 2 == 0) && (a % 3 == 0) && ( a % 5 != 0) ) {
		cout << a << " se deli na 2 i 3, no ne se deli na 5\n";
	}

	return 0;
}