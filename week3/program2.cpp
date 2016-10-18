#include <iostream>
using namespace std;

int main() {
	int x;

	cout << "x= ";
	cin >> x;

	for ( int i = 2; i <= 10; i++ ) {
		int devide = x % i;
		switch(devide) {
			case 0 : cout << "The number can be devide by " << i << endl;
		                break;
			default: cout << "The number can't be devide by " << i << endl;
		               break;
		}
	}

	return 0;
}