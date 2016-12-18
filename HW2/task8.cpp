/**
 * Task 6:
 *
 * Да се напише ф-ция, която по даден масив от цели числа (и неговия размер) 
 * и цяло число, търси(по възможност двоично) числото в масива и ако го намери, 
 * връща указател към първото му срещане, в противен случай връща NULL.
 **/

#include <iostream>

using namespace std;

int* removeN(int *arr, int size, int n) {

	for(int i = 0; i < size; i++) {
		if(arr[i] == n) {
			return &arr[i];
		}
	}

	return NULL;
}

int main() {
	// 2.6 and 0.5
	int arr[10] = {1010, 0001, 0101, 1010, 0110, 1000, 00010010, 1011, 1010}; 
	int n = 1010;

	cout << removeN(arr, 10, n);

	cout << endl;

	return 0;
}
