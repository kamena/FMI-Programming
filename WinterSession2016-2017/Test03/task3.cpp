/* Task 3
 * Реализирайте рекурсивна функция void replace(int* arr, int size, int oldElem, int newElem) ,
 * която присвоява стойността newElem на всички елементи в масива arr, които имат стойност
 * oldElem.
*/

#include <iostream>

using namespace std;
int i = 0;
void replace(int* arr, int size, int oldElem, int newElem) {
	if( i <= size ) {
		if(arr[i] == oldElem) {
			arr[i] = newElem;
		}
		i++;
		return replace(arr, size, oldElem, newElem);
	}
}

int main() {
	int oldElem, newElem, size;
	cout << "size = ";
	cin >> size;
	int arr[size];
	cout << "arr: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "oldElem = ";
	cin >> oldElem;

	cout << "newElem = ";
	cin >> newElem;
	
	replace(arr, size, oldElem, newElem);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}