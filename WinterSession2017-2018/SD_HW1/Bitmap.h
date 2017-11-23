#pragma once
#include <fstream>

struct BmpSignature {
    unsigned char data[2];
}; 

struct BmpHeader {
    unsigned int fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int dataOffset;
};

struct BmpInfoHeader { 
    unsigned int  biSize;
             int  biWidth;
             int  biHeight;
    unsigned short int  biPlanes;
    unsigned short int  biBitCount;
};

struct Pixel {
    char blue;
    char green;
    char red;
};

class Bitmap {
    std::ifstream ifsBmp_;
    int buffLength_;
    char* buffer_;

    int height_;
    int width_;

    BmpSignature *signature_;
    BmpHeader *header_;
    BmpInfoHeader *info_;
    Pixel** pix_;

    void resize(int, int);
    void readFile();
public:
    Bitmap();
    Bitmap(char*);
    ~Bitmap();

    const int getHeight() const;
    const int getWidth() const;

    void printHeader() ;
    void writeIcon(int, int, int, int, char*);
};