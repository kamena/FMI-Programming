#include <iostream>

using namespace std;

int main() {
	const int COUNT = 8;
	double array[COUNT] = {1, 2, 1, 3.14, 2, 1, 1};

	int equalPairs = 0; 

	for ( int i = 0; i < COUNT; i++ ) {
		for ( int j = i + 1; j < COUNT; j++ ) {
			if ( array[i] == array[j] ) {
				equalPairs++;
			}
		}
	}

	cout << equalPairs << endl;

	return 0;
}