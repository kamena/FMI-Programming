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
	int pos2 = 0, used3 = size1;
	int start = 0, pos1;
	if (arr2[pos2] < arr3[start]){
		for(int l = used3; l > start; l--) {
			arr3[l] = arr3[l-1];
		}
		used3++;
		arr3[start] = arr2[pos2];
		pos2++;
		start++;
	}
	while (start < size3 - 1) {
		if (arr3[start + 1] == 0) {
			for(int l = used3; l < size3; l++) {
				arr3[l] = arr2[pos2];
				pos2++;
			}
		} else {
			if(arr2[pos2] >= arr3[start] && arr2[pos2] <= arr3[start + 1]) {
				for(int l = used3; l > start+1; l--) {
					arr3[l] = arr3[l-1];
				}
				used3++;
				arr3[start+1] = arr2[pos2];
				pos2++;

			} 
			start++;
		}
	}

	for(int i = 0; i < size3; i++) {
		cout << arr3[i] << " ";
	}
}

int main() {
	int arr1[5] = {2, 4, 8, 9, 9};
	int arr2[7] = {2, 3, 4, 7, 9, 9};
	int arr3[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	combine(arr1, 5, arr2, 7, arr3, 11);

	cout << endl;

	return 0;
}