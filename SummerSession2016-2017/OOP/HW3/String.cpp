#include "String.h"

void String::destroy() {
    delete [] this->data_;
}

void String::copy(const String& other) {
	this->data_ = new char[strlen(other.data_) +1];
    strcpy(this->data_, other.data_);
}

String::String(){
	this->data_ = NULL;
}

String::String(char* data){
	this->data_ = new char[strlen(data) + 1];
	strcpy(this->data_, data);
}

String& String::operator=(const String& other){
	if(this == &other) return *this;
	
	copy(other);

	return *this;
}

String::~String(){
	destroy();
}

char String::at(size_t idx) const {
	if ( idx >= 0 && idx <= this->size() ) {
		return this->data_[idx];
	} else throw invalid_argument( "The index is not valid!" );
}

size_t String::size() const{
	return strlen(this->data_);
}


char& String::operator[](size_t idx) {
	if ( idx >= 0 && idx <= this->size() ) {
		return this->data_[idx];
	} else throw invalid_argument( "The index is not valid!" );
}

const char String::operator[](size_t idx) const {
	if ( idx >= 0 && idx <= this->size() ) {
		return this->data_[idx];
	} else throw invalid_argument( "The index is not valid!" );
}

String& String::operator+=(const String& rhs) {
	int size = this->size() + rhs.size();

	int j = 0;
	for(int k = this->size(), j = 0; k < size ; k++, j++) {
		this->data_[k] = rhs.data_[j];
    }

    if(this->data_[size] != '\0') {
	 	this->data_[size] = '\0';
	}

	return *this;
}

bool String::operator<(const String& rhs) {
	return this->size() < rhs.size();
}
bool String::operator>(const String& rhs) {
	return this->size() > rhs.size();
}
bool String::operator<=(const String& rhs) {
	return this->size() <= rhs.size();
}
bool String::operator>=(const String& rhs) {
	return this->size() >= rhs.size();
}

bool String::operator==(const String& rhs) {
	return this->data_ == rhs.data_;
}
bool String::operator!=(const String& rhs) {
	return this->data_ != rhs.data_;
}

String operator+(const String& lhs, const String& rhs) {
	String str = lhs.data_;

	str += rhs;

	return str;
}
ostream& operator<<(ostream& os, const String& obj) {
	for (int i = 0; i < obj.size(); ++i) {
		os << obj.data_[i];
	}
    return os;
}
istream& operator>>(istream& is, String& obj) {
	cout << "Size: " << obj.size() << endl;
    for (int i = 0; i < obj.size(); ++i) {
        cout << "string[" << i << "] = ";
        is >> obj.data_[i];
    }
	return is;
}