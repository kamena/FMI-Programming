#pragma once

#include <fstream>

class Tdf {
public:
    Tdf();
	Tdf(const char* fname);
    ~Tdf();

    void readAndCrop();
	
private:    
	std::ifstream 	file_;

    int checkName(char*& name);
};