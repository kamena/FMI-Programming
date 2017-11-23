/*
 * Kamena Dacheva, 71672
 * Homework 1
 * 
 * OS used: Linux
 */


#include <iostream>
#include <fstream>
#include <cstring>
#include "Bitmap.cpp"

using namespace std;

const char bmpEx[5] = ".bmp";


int main(int argc, char** argv) {
	ifstream ifs;

	Bitmap bitmap((char*)"dogs.bmp");

	bitmap.printHeader();

	// bitmap.writeIcon(0, 0, 200, 200, (char*)"test2.bmp");

	// ifstream ifs;

 //    ifs.open("dogs.tdf");
 //    if (ifs.is_open()) {
 // 	// 	while (true) {
	// 	//     char x;
	// 	//     ifs >> x;
	// 	//     if( ifs.eof() ) break;
	// 	//     cout << x;
	// 	// }
 //    	char buffer[1024];
 
	// 	while (ifs.getline(buffer, sizeof(buffer))) {
	// 		char* output = NULL;
	// 		if (buffer[0] != ';')
	// 	    	cout << buffer << endl;
	// 		    output = strstr (buffer, bmpEx);
	// 			if(output) {
	// 			    printf("String Found");
	// 			}
	// 	}
	// } else {
	// 	cerr << "Error opening the file!";
	// }
	// ifs.close();
	
	return 0;
}