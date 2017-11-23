#include "Bitmap.h"

Bitmap::Bitmap() {
    
}

Bitmap::Bitmap(char* fileName) {
    
    this->ifsBmp_.open(fileName, std::ios::binary);

    if(!ifsBmp_) std::cerr << "Error: Fail to open file. " << std::endl;

    signature_ = new BmpSignature;
    header_ = new BmpHeader;
    info_ = new BmpInfoHeader;

    readFile();
}

Bitmap::~Bitmap() {
    //deallocate the array
    for(int i = 0; i < getHeight(); i++)
        delete [] pix_[i];
    delete [] pix_;

    delete signature_;
    delete header_;
    delete info_;

    ifsBmp_.close();
}

const int Bitmap::getHeight() const {
    return this->info_->biWidth;
}

const int Bitmap::getWidth() const {
    return this->info_->biHeight;
}

void Bitmap::resize(int newWidth, int newHeight) {
    this->info_->biWidth = newWidth;
    this->info_->biHeight = newHeight;
}


void Bitmap::printHeader() {
    std::cout << "==== BMP HEADER ====" << std::endl;
    std::cout << "+ Signature  : " << signature_->data[0] << signature_->data[1] << std::endl;
    std::cout << "+ File Size  : " << header_->fileSize << " byte(s)" << std::endl;
    std::cout << "+ Reserved1  : " << header_->reserved1 << std::endl;
    std::cout << "+ Reserved2  : " << header_->reserved2 << std::endl;
    std::cout << "+ Data Offset: " << header_->dataOffset << " byte(s)" << std::endl;

    std::cout << "===== BMP INFO =====" << std::endl;
    std::cout << "+ Size       : " << info_->biSize << std::endl;
    std::cout << "+ Width      : " << info_->biWidth << std::endl;
    std::cout << "+ Height     : " << info_->biHeight << std::endl;
    
    std::cout << "+ Planes     : " << info_->biPlanes << std::endl;
    std::cout << "+ Bitcount   : " << info_->biBitCount << std::endl;   
}

void Bitmap::readFile() {
    if(!ifsBmp_)
        return;
   
    // Read header

    ifsBmp_.seekg(0, std::ios::beg);
    ifsBmp_.read((char*) signature_, sizeof(signature_));
    ifsBmp_.read((char*) header_, sizeof(header_));
    ifsBmp_.read((char*) info_, sizeof(info_));
    
    std::cout << "+ Size       : " << info_->biSize << std::endl;
    std::cout << "+ Width      : " << info_->biWidth << std::endl;
    // Read all of the rest bytes between the header and the pixels
    buffLength_ = header_->dataOffset - ifsBmp_.tellg();     

    buffer_ = new char[24];

    std::cout << "Helloooo!!";

    ifsBmp_.read(buffer_, buffLength_);

    // Read pixels
    // this->pix_ = new Pixel**[height_][width_];



    //allocate the array
    pix_ = new Pixel*[getHeight()];
    for(int i = 0; i < getHeight(); i++)
        pix_[i] = new Pixel[getWidth()];
    
    ifsBmp_.seekg(header_->dataOffset, std::ios::beg);
    ifsBmp_.read((char*) &pix_, sizeof(pix_));

    

}

void Bitmap::writeIcon(int x, int y, int iconWidth, int iconHeight, char* newFileName) {

    std::ofstream ofsBmp;
    ofsBmp.open(newFileName, std::ios::binary);
    if(!ofsBmp) std::cerr << "Error opening the file" << std::endl;

    std::cout << "Success!";    

    ofsBmp.write((char*) &signature_, sizeof(signature_));
    // ofsBmp.write((char*) &header_, sizeof(header_));

    // resize(iconWidth, iconHeight);

    // ofsBmp.write((char*) &info_, sizeof(info_));

    // ofsBmp.write((char*) &buffer_, buffLength_);

    // Write the selected pixels in the new file
    // for(int i = x; i < iconHeight ; i++) {
    //     for(int j = y; j < iconWidth; j++){
    //         ofsBmp.write((char*) &pix_[i][j], sizeof(Pixel));
    //     }
    // }

    ofsBmp.close();
}
