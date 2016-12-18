/**
 * Task 7:
 *
 * Да се напише ф-ция, която по даден масив от цели числа (и неговия размер) 
 * и цяло число n, премахва от масива всички срещания на даденото число. 
 * Ако има премахнати елементи, функцията връща true, в противен случай, 
 * ако елементът със стойност n не се среща в дадения масив, функцията връща false.
 **/

#include <iostream>

using namespace std;

string removeN(int *arr, int size, int n) {
	string isN = "false";
	for(int i = 0; i < size; i++) {
		if(arr[i] == n) {
			isN = "true";
			for(int l = i; l < size-1; l++) {
				arr[l] = arr[l+1];
			}	
			size--;
		}
	}

	return isN;
}

int main() {
	// 2.6 and 0.5
	int arr[10] = {2, 5, 3, 4, 3, 1, 9, 3, 5}; 
	int n = 3;

	cout << removeN(arr, 10, n);

	cout << endl;

	return 0;
}
