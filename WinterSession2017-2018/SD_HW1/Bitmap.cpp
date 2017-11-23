#include <iostream>
#include "Bitmap.h"

Bitmap::Bitmap() :file_(NULL), pixels_(NULL), buffer_(NULL) {}

Bitmap::Bitmap(const char* fname) 
:file_(fname), pixels_(NULL), buffer_(NULL) 
{
    if(!file_) {
        std::cerr << "Error: cannot open file " << fname <<  std::endl;
        return;
    } 
    read();
}

Bitmap::~Bitmap() {
    delete [] buffer_;
    buffer_ = NULL;
    
    delete [] pixels_;
    pixels_ = NULL;
}

void Bitmap::read() {
    // Read header
    file_.seekg(0, std::ios::beg);

    file_.read((char*) &signature_,	 sizeof(signature_));
    file_.read((char*) &header_, 	 sizeof(header_));
    file_.read((char*) &info_, 	 	 sizeof(info_));
    if(!file_) {
        std::cerr << "Something went wrong" << std::endl;
        return;
    }

    // printHeader();

    bufferLength_ = header_.dataOffset - file_.tellg(); 

    buffer_ = new char[bufferLength_];

    // Read all of the rest bytes until pixels
    file_.read(buffer_, bufferLength_);
    if(!file_) {
        std::cerr << "Something went wrong" << std::endl;
        return;
    }
    
    numberOfPixels_ = info_.biWidth * info_.biHeight;
    
    pixels_ = new Pixel[numberOfPixels_];

    file_.seekg(header_.dataOffset, std::ios::beg);

    file_.read((char*) pixels_, numberOfPixels_ * sizeof(Pixel));
    if(!file_) {
        std::cerr << "Something went wrong" << std::endl;
        return;
    }
    
    file_.close();
}

void Bitmap::printHeader() {
    std::cout << "**** Bitmap header info ****" << std::endl;
    std::cout << "* Signature  : " << signature_.data[0] << signature_.data[1] << std::endl;
    std::cout << "* File Size  : " << header_.fileSize << std::endl;
    std::cout << "* Reserved1  : " << header_.reserved1 << std::endl;
    std::cout << "* Reserved2  : " << header_.reserved2 << std::endl;
    std::cout << "* Data Offset: " << header_.dataOffset << std::endl;

    std::cout << "* Size       : " << info_.biSize << std::endl;
    std::cout << "* Width      : " << info_.biWidth << std::endl;
    std::cout << "* Height     : " << info_.biHeight << std::endl;
 
    std::cout << "* Planes     : " << info_.biPlanes << std::endl;
    std::cout << "* Bitcount   : " << info_.biBitCount << std::endl;   
}

void Bitmap::write(const char* fname) {
    if(!file_) {
        return;
    }
    
    std::ofstream out(fname, std::ios::binary);
    if (!out) {
        std::cerr << "Error: cannot open file " << fname << std::endl;
        return;
    }
    
    // Write header
    out.write((char*) &signature_,  sizeof(signature_));
    out.write((char*) &header_,     sizeof(header_));
    out.write((char*) &info_,       sizeof(info_));
    out.write((char*) buffer_,      bufferLength_);
    if(!out) {
        std::cerr << "Something went wrong" << std::endl;
        return;
    }
    
    // Calculate number of bytes to be written for each row
    size_t bytes = info_.biWidth * sizeof(Pixel);
    
    // Calculate padding for row
    size_t paddingBytes = (bytes % 4) ? 4 - (bytes % 4) : 0;
    
    // Writing rows
    for (size_t rowIndex = 0; rowIndex < info_.biHeight; ++rowIndex) {
        out.write((char*) (pixels_ + info_.biWidth * rowIndex),  bytes);
        if(!out) {
            std::cerr << "Something went wrong" << std::endl;
        }
        
        out.write("    ", paddingBytes);

        if(!out) {
            std::cerr << "Something went wrong" << std::endl;
            return;
        }
    }
    
}

void Bitmap::resize(int positionX, int positionY, int width, int height) {   
    if(!file_) {
        return;
    } 

    if ( (positionX + width > info_.biWidth) || (positionY + height > info_.biHeight)) {
        std::cerr << "Overflowing image size" << std::endl;
        return;
    }

    // Allocate new buffer for the cropped image
    size_t newPixelsSize = width * height;
    Pixel* newPixels = new Pixel[newPixelsSize];
    
    size_t index = 0;

    // In order to change the (0,0) pixel to be the left one from the top, not from bottom
    // positionY = info_.biHeight - positionY - height;

    for (int row = positionY; row < (positionY + height); ++row) {   
        for (int col = positionX; col < (positionX + width); ++col) {        
            newPixels[index++] = pixels_[row * info_.biWidth + col];
        }
    }
    
    // Write the new dimensions in the header
    info_.biWidth = width;
    info_.biHeight = height;
    
    // Free old buffer
    delete [] pixels_;
    
    // Assagn the new one to the member
    pixels_ = newPixels;
    
    numberOfPixels_ = newPixelsSize;
}
