#include <iostream>
using namespace std;

int main() {
	int x, a, b, c, d, h, shape, r;

	const double PI = 3.14;

	cout << "The figure shape (1 - triangle; 2 - square; 3 - circle; 4 - rectangle; 5 - trapeze):  ";
	cin >> shape;

		switch(shape) {
			case 1 : cout << "What is the size of a? ";
					cin >> a;
					cout << "What is the size of b? ";
					cin >> b;
					cout << "What is the size of c? ";
					cin >> c;
					cout << "What is the size of ha? ";
					cin >> h;
					
					if ( ( a < b + c ) && ( b < a + c ) && ( c < a + b ) ) {
						cout << "P = " << a + b + c << endl;
						cout << "S = " << ( a * h ) / 2 << endl;
					} else {
						cout << "There must be something wrong here!";
					}
		        	break;
			case 2 : cout << "What is the size of a? ";
					cin >> a;
					cout << "S = " << a*  a << endl;
					cout << "P = " << 4 * a << endl;
		        	break;
		    case 3 : cout << "What is the size of r? ";
					cin >> r;
					cout << "S = " << PI * r * r << endl;
					cout << "P = " << 2 * PI * r << endl;
		        	break;
		    case 4 : cout << "What is the size of a? ";
					cin >> a;
					cout << "What is the size of b? ";
					cin >> b;
					cout << "S = " << a * b << endl;
					cout << "P = " << 2 * a + 2 * b << endl;
					break;
			case 5 : cout << "What is the size of a? ";
					cin >> a;
					cout << "What is the size of b? ";
					cin >> b;
					cout << "What is the size of c? ";
					cin >> c;
					cout << "What is the size of d? ";
					cin >> d;
					cout << "What is the size of h? ";
					cin >> h;
					cout << "S = " << ((a + b) * h)/2 << endl;
					cout << "P = " << a + b + c + d << endl;
					break;
			default: cout << "I don't know yet." << endl;
			break;
		}

	return 0;
}
