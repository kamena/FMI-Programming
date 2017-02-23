/**
 * Task 2:
 *
 * Иванчо е студент, който няма пари да си купи новия албум на любимия си изпълнител, защото предната вечер 
 * е дал всичките си пари, за да хвърля салфетки в Плаза. Затова той стигнал до извода, 
 * че може да си свали песните от интернет. Успял да намери своите песни, но те били в разбъркан ред.
 * Напишете функция, която да помогне на Иванчо да държи в правилен ред своите песни. За тази цел функцията
 * ви трябва да приема списък с изтеглените досега песни и мястото на новата песен в албума. 
 * Функцията трябва да добави новата песен в списъка от песни.
**/

#include <iostream>

using namespace std;

const int SIZE = 20;
int LENGTH = 5;

int getArray( int arr[] ) {

	cout << "Write your array: ";
	for (int i = 0; i < LENGTH; i++) {
		cin >> arr[i];
	}

	return arr[SIZE];
}

int sortArray( int arr[] ) {
	int helper;

	for (int i = 0; i < LENGTH; i++) {
		for ( int j = 0; j < LENGTH - 1; j++ ) {
			if ( arr[j] > arr[j+1] ) {
				helper = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = helper;
			}
		}
	}	

	return arr[SIZE];
}

void printArray( int arr[] ) {
	for (int i = 0; i < LENGTH; i++) {
		cout << arr[i];
	}	
}

int main() {
	int arr[SIZE];
	int new_num;

	getArray(arr);

	cout << "What's the number of the new song? ";
	cin >> new_num;
	LENGTH++;

	arr[LENGTH-1] = new_num;

	sortArray(arr);

	printArray(arr);

	cout << endl;

	return 0;
}