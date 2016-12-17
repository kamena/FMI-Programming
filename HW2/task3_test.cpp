/**
 * Task 3:
 *
 * Да се напише ф-ция, която по дадени указатели към два сортирани масива и съответните им размери 
 * и подаден трети масив, слива първите два масива втретия, така че полученият масив 
 * отново да е сортиран, без да се прилага допълнително сортиране. 
 * Приемаме, че масивите са от цели числа.
 **/

#include <iostream>

using namespace std;

void combine(int *arr1, int size1, int *arr2, int size2, int *arr3, int size3) {
	for (int i = 0; i < size1; i++) {
		arr3[i] = arr1[i];
	}
	int check = 0, pos2 = 0, pos1 = 0, start, end, used3 = size1 - 1, where_to = 1;
	while(check < size1) {
		int length_between = 0;
		if (arr2[pos2] >= arr1[pos1] && arr2[pos2] <= arr1[pos1+1]) {
		start = pos2;
		cout << "arr2[pos2] = " << arr2[pos2] << endl;
		cout << "arr1[pos1] = " << arr1[pos1] << endl;
		
			while( arr2[pos2] >= arr1[pos1] && arr2[pos2] <= arr1[pos1+1] ) {
				length_between++;
				pos2++;
				cout << pos2 << " ";
			}
			end = pos2;
			cout << "Start = " << start << endl;
			cout << "End = " << end << endl;
			cout << "Length Between = " << length_between << endl;
			for(int l = used3; l > where_to; l--) {
				arr3[l+length_between] = arr3[l];
			}

			for (int m = where_to; m < length_between + where_to; m++) {
				cout << "I am here\n";
				arr3[m] = arr2[start];
				start++;
			}
			for(int z = 0; z < size3; z++) {
				cout << arr3[z] << " ";
			}
			check++;
			pos1 ++;
			cout << "NEW POS1 = " << pos1 << endl;
			used3 += length_between;
			where_to += length_between+1;
		} else { pos1++;}
		
	}

	for(int i = 0; i < size3; i++) {
		cout << arr3[i] << " ";
	}
}

int main() {
	int arr1[5] = {1, 4, 8, 9, 10};
	int arr2[7] = {2, 3, 5, 7, 9, 26};
	int arr3[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	combine(arr1, 5, arr2, 7, arr3, 12);

	cout << endl;

	return 0;
}