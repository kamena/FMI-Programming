/* Task 2
 * Напишете (рекурсивна) функция void count(int* arr, int size, int elem, type occurrences) , която в
 * променливата occurences запазва броя на срещанията на променливата elem в масива arr.
 */

#include <iostream>

using namespace std;
int i = 0, occurrences = 0;
void count(int* arr, int size, int elem, int& occurrences) {
	if( i <= size ) {
		if(arr[i] == elem) {
			occurrences++;
		}
		i++;
		return count(arr, size, elem, occurrences);
	}

}

int main() {
	int size, elem;
	cout << "size = ";
	cin >> size;
	int arr[size];
	cout << "Arr: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	cout << "elem = ";
	cin >> elem;

	count(arr, size, elem, occurrences);

	cout << "occurrences = " << occurrences << endl;
	return 0;
}