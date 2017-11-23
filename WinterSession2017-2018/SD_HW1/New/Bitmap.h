#pragma once

#include <fstream>

class Bitmap {
public:
    Bitmap();
	Bitmap(const char* fname);
    ~Bitmap();

	void printHeader();
	void resize(int x, int y, int width, int height);
    void write(const char* fname);
    
private:
    struct BmpSignature {
        unsigned char data[2];
    };
    
    struct BmpHeader {
        unsigned int     fileSize;
        unsigned short   reserved1;
        unsigned short   reserved2;
        unsigned int     dataOffset;
    };
    
    struct BmpInfoHeader {
        unsigned int  biSize;
        int           biWidth;
        int           biHeight;
        unsigned int  biPlanes;
        unsigned int  biBitCount;
    };
    
    struct Pixel {
        char blue;
        char green;
        char red;
    };
    
    void read();
    
	std::ifstream 	file_;

    Pixel*          pixels_;
    size_t          numberOfPixels_;
    
	BmpHeader 		header_;
	BmpSignature 	signature_;
	BmpInfoHeader 	info_;

	char* 			buffer_;
	size_t 			bufferLength_;
};
