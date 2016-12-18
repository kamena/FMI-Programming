/**
 * Task 6:
 *
 * Да се напише ф-ция, която по даден масив от дробни числа (и неговия размер) намира индека на последния негов елемент, 
 * който е равен на средното аритметично от неговире съседни елементи (крайните елементи имат само по един съседен). 
 * Ако такъв елемент не съществува, да се връща -1.

 * a, e, i, o, u 
 **/

#include <iostream>

using namespace std;

int checkTheLast(float *arr, int size) {
	int theLast;
	if(arr[0] == arr[1]) {
		theLast = 0;
	}
	if(arr[size-1] == arr[size-2]) {
		return theLast = size - 1;
	}

	for(int i = 1; i < size-1; i++) {
		if ( arr[i] == (arr[i-1] + arr[i+1])/2 ) {
			theLast = i;
		}
	}

	return theLast;
}

int main() {
	// 2.6 and 0.5
	float arr[6] = {1.5, 2.6, 3.7, 0.5, -2.7, 1}; // answer = 3 (0.5)
	// float arr[6] = {1.5, 1.5, 3.7, 0.5, 2.7, 1}; // answer = 0 (1.5)
	// float arr[6] = {3.7, 0.5, 2.7, 1, 1.5, 1.5}; // answer = 5 (1.5)

	cout << checkTheLast(arr, 6);

	cout << endl;

	return 0;
}
