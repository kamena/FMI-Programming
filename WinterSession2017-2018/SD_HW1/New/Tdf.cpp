#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Tdf.h"
#include "Bitmap.h"

Tdf::Tdf() : file_(NULL) {}

Tdf::Tdf(const char* fname) : file_(fname) {
	if(!file_) {
        std::cerr << "Error: cannot open file " << fname <<  std::endl;
        return;
    } 
}

Tdf::~Tdf() {
	file_.close();
}

int Tdf::checkName(char*& name) {
	if(!strstr(name, ".bmp")) return 0;

    if(name[strlen(name) - 1] != 'p' || name[strlen(name) - 2] != 'm' || 
       name[strlen(name) - 3] != 'b' || name[strlen(name) - 4] != '.') return 0;

	if(strstr(name, ";")) {
        
        int count = 0;

        if(name[0] == ';') return 0;

        for(int i = 1; i < strlen(name); i++) {
            if(name[i] == ';' && name[i-1] != '\\') return 0;
            else if (name[i] == ';') count++;
        }

        for(int i = 1; i < strlen(name); i++) {
            if(name[i] == ';') {
                for(int j = i; j < strlen(name); j++) {
                    name[j-1] = name[j];
                }
            }
        }

        char* newName = new char[125];

        for(int i = 0; i < strlen(name) - count; i++) {
            newName[i] = name[i];
        }
        newName[strlen(name)] = '\0';

        name = newName;
    	
    	return 1;
    }

    return 1;
}

void Tdf::readAndCrop() {
	if(!file_) {
		std::cerr << "Error: cannot open tdf file" << std::endl;
        return;
	}

   	char buffer[1024];

    int i = 0;
    char* pch;

    char* fileName =    new char[125];
    char* newFileName = new char[125];

    int x, y, width, height;
    int count, notValid;
    while (file_.getline(buffer, 1024)) {    

        pch = fileName = newFileName = NULL;
        count = 0;
        notValid = 0;

        pch = strtok(buffer, " ,()");
        if(pch[0] == ';') continue; 

        while (pch != NULL) {
            if(pch == ";" && count < 5) notValid = 1;
            switch(count) {
                case 0: fileName = pch;
                        count++;
                        break;
                case 1: 
                        if(strstr(pch, ";")) notValid = 1;
                        else {
                            x = strtol(pch, &pch, 10);
                            count++;
                        }
                        break;
                case 2: if(strstr(pch, ";")) notValid = 1;
                        else { 
                            y = strtol(pch, &pch, 10);
                            count++;
                        }
                        break;
                case 3: if(strstr(pch, ";")) notValid = 1;
                        else {
                            width = strtol(pch, &pch, 10);
                            count++;
                        }
                        break;
                case 4: if(strstr(pch, ";")) notValid = 1;
                        else {
                            height = strtol(pch, &pch, 10);
                            count++;
                        }
                        break;
                case 5: newFileName = pch;
                		count++;
                        break;
                case 6: if( pch[0] != ';') notValid = 1;
                        count++;
                		break;
                default:break;

                if(notValid == 1) break;
            }
            
            pch = strtok(NULL, " ,()");

        }
        
        if(checkName(fileName) && checkName(newFileName) && notValid == 0) {
            Bitmap file(fileName);
            file.resize(x, y, width, height);   
            file.write(newFileName);           
        } else {
            std::cerr << "Not valid bmp file name/s or command found. " << std::endl;
        }

        i++;
    }
}
