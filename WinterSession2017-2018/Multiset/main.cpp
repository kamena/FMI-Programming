/* Multiset
 * by
 * Kamena Dacheva, 71672
 *
 * OS used: Linux
 */


#include <iostream>
#include "Multiset.h"

using namespace std;


int main() {
	remove("multisetLastVersion55896.dat");
	Multiset<int> firstSet;

    firstSet.add(1);
	firstSet.add(2);
	// mSet.add(1);
	firstSet.add(3);
	firstSet.add(1);	
	firstSet.add(1);

	Multiset<int> newSet;
	newSet.add(2);
	// newSet.add(1);
	newSet.add(3);
	// newSet.add(7);

	Multiset<string> anotherone;
	anotherone.add("Kami");

	cout << firstSet.isSubSet(newSet.getRoot()) << endl;	

	firstSet.print();

	cout << endl;

	Multiset<int> mergedSet;

	firstSet.merge(newSet, &mergedSet);

	mergedSet.print();

	// cout << endl;

	cout << "Count all: " << firstSet.count() << endl;

	firstSet.removeIt(2);

	// cout << endl;

	// firstSet.print();

	// cout << "Count: " << firstSet.count(1);

	// cout << endl;

	// firstSet.print();

	return 0;
}