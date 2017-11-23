/* TODO!!
 * The color table is not copying
 * Crop image
 * Check if the file type is BM.
 * Check after opening if the file is still ok
 */



#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

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
    unsigned int  biPlanes;
    unsigned int  biBitCount;
};

struct Pixel {
    char blue;
    char green;
    char red;
};

void ReadHeader(ifstream &fin, BmpSignature & sig, BmpHeader &header, BmpInfoHeader &info) {
    if(!fin)
        return;

    fin.seekg(0, ios::beg);
    fin.read((char*) &sig, sizeof(sig));
    fin.read((char*) &header, sizeof(header));
    fin.read((char*) &info, sizeof(info));
}

void PrintHeader(BmpSignature sig, BmpHeader header, BmpInfoHeader info) {
    cout << "==== BMP HEADER ====" << endl;
    cout << "+ Signature  : " << sig.data[0] << sig.data[1] << endl;
    cout << "+ File Size  : " << header.fileSize << " byte(s)" << endl;
    cout << "+ Reserved1  : " << header.reserved1 << endl;
    cout << "+ Reserved2  : " << header.reserved2 << endl;
    cout << "+ Data Offset: " << header.dataOffset << " byte(s)" << endl;

    cout << "===== BMP INFO =====" << endl;
    cout << "+ Size       : " << info.biSize << endl;
    cout << "+ width      : " << info.biWidth << endl;
    cout << "+ height     : " << info.biHeight << endl;
    
    cout << "+ Planes     : " << info.biPlanes << endl;
    cout << "+ Bitcount   : " << info.biBitCount << endl;
    
    // cout << "+ Compression: " << info.biCompression << endl;
    // cout << "+ Img size   : " << info.biSizeImage << endl;
    // cout << "+ XPels      : " << info.biXPelsPerMeter << endl;
    // cout << "+ YPels      : " << info.biYPelsPerMeter << endl;

    // cout << "+ ClrUsed    : " << info.biClrUsed << endl;    
}

int main() {
    
    ifstream fin("dogs.bmp", ios::binary);
    if (!fin) {
        cerr << "Error: Fail to open file. " << endl;
    }
    ofstream test("test.bmp", ios::binary);
    
    BmpSignature sig;
    BmpHeader hdr;
    BmpInfoHeader ihdr;

    ReadHeader(fin, sig, hdr, ihdr);
    PrintHeader(sig, hdr, ihdr);

    // Read all of the rest bytes between the header and the pixels
    int length = hdr.dataOffset - fin.tellg();  
    char* buffer = new char [length];
    fin.read(buffer, length);

    // Create 2D arrawy for all pixels
    Pixel pic[ihdr.biHeight][ihdr.biWidth];

    // Move to the bytes for the pixels
    fin.seekg(hdr.dataOffset, ios::beg);
    fin.read((char*) &pic, sizeof(pic));

    // Resize the image
    int iconWidth = 200;
    int iconHeight = 200;

    ihdr.biWidth = iconWidth;
    ihdr.biHeight = iconHeight;

    // Write the header in the new file   
    test.write((char*) &sig, sizeof(sig));
    test.write((char*) &hdr, sizeof(hdr));
    test.write((char*) &ihdr, sizeof(ihdr));
    test.write((char*) &buffer, length);

    // Write the selected pixels in the new file
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++){
            // cout << "pic(" << i << ", " << j << "); " << endl;
            // fin.read((char*) &pic[i][j], sizeof(Pixel));
            test.write((char*) &pic[i][j], sizeof(Pixel));
        }
    }

    // Close the files
    fin.close();
    test.close();
    
    return 0;  
}