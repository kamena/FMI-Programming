#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	c = b % a;

	if (c == 0) {
		cout << a << " e delitel na " << b << endl;
	}

	return 0;
}