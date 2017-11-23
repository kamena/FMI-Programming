#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Decrypt.h"
#include "Stack.cpp"


/* Идея:
Записвам си в един стек числата, с които ще умножаваме. Записваме в един временно динамично заделен масив подадения масив без числата.
Обхождаме отзад напред и записваме в един нов стек:
когато има просто буква или цифра, без да сме имали затваряща скоба преди това просто я записваме, 
когато сме намерили затваряща скоба - преписваме това, което е между скобите еди колко си пъти според броя от първия стек, попваме 
и продължаваме

*/

Decrypt::Decrypt(const char* fname, const char* ofname) 
: iffile_(fname), offile_(ofname) {
	if(!iffile_) {
        std::cerr << "Error: cannot open file " << fname <<  std::endl;
        return;
    } 

    if(!offile_) {
        std::cerr << "Error: cannot open file " << ofname <<  std::endl;
        return;
    } 

	read();
}

Decrypt::~Decrypt() {
	iffile_.close();
	offile_.close();
}

/*
 * void decrypt(char* buff);
 * char* buff - variable for the text that should be decrypted
 *
 * decrypt() decrypts the given text and calls the write() method.
*/
void Decrypt::decrypt(char* buff) {
	char* decrypted = new char[1024];
	char* temp = new char[125];

	int number;
	int index = 0, j, position;
	int check = 0;

	int howManyTimes = 0;

	// Stack for the numbers of how many times to repeat the string in the brackets
	Stack<int> list;

	for(int i = 0; i < strlen(buff); i++) {
		// Check for opening bracket
		if(buff[i] == '(') {
			number = 0;
			
			check++;
			j = i-1;
			// Go back until chars are numbers
			while((buff[j] >= '0' && buff[j] <= '9')) {
				number = atoi(&buff[j]);
		
				j--;
			}
			list.push(number);
		}
		// Check for closing bracket
		if(buff[i] == ')') {
			check--;
			howManyTimes = list.top();
			list.pop();
			position = -1;
			// Go back until opening bracket
			while(decrypted[index] != '(') {
				temp[position] = decrypted[index];
				position++;
				index--;
			}
			for(int z = 0; z < howManyTimes; z++) {
				for(int q = position - 1; q >= 0; q--) {
					decrypted[index] = temp[q];
					index++;
				}
			}
		}

		// Check if the brackets are incorrectly used - more closing brackets then expected
		if(check < 0) {
			cerr << "Sorry - the code cannot be decrypted by using this method!";
			return;
		}

		// Write the decrypted code in char array
		if ((!(buff[i] >= '0' && buff[i] <= '9') || buff[i - 1] == '\\') && buff[i] != ')' && !(buff[i] == '\\' && buff[i - 1] != '\\') ) {
			decrypted[index] = buff[i];
			index++;
		}
	}

	write(decrypted);
}

/*
 * void read();
 *
 * read() reads from given text file line by line and calls decrypted() for each line.
*/

void Decrypt::read() {
	char buffer[1024];
	while (this->iffile_.getline(buffer, 1024)) {  
		decrypt(buffer);
	}
}

/*
 * void write(const char* text);
 * const char* text - variable for the text that should be written in the given file.
 *
 * write() writes in given text file the decrypted code.
*/
void Decrypt::write(const char* text) {
	if(offile_.is_open()) {
		for(int i = 0; i < strlen(text); i++) {
			offile_ << text[i];
			// std::cout << text[i];
		}
		// std::cout << std::endl;
		offile_ << "\n";
	}
}
