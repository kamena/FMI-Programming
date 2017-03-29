/*
 * ./a.out "String 1" "String 2"
 */

#include <iostream>
#include <cstring>

using namespace std;

class String {
     int capacity_, size_;
     char* buffer_;
public:
     String(int capacity): capacity_(capacity), 
     size_(0), buffer_(new char[capacity]) {}
     String(const char* str): capacity_(0), size_(0), buffer_(0) {
          size_ = strlen(str);
          capacity_ = size_ + 1;
          buffer_ = new char[capacity_];
          strcpy(buffer_, str);
     }
     String(const String& other):capacity_(other.capacity_), 
     size_(other.size_), buffer_(new char[capacity_]) {
          for (int i = 0; i < size_; ++i) buffer_[i] = other.buffer_[i];
     }
     int size() const {return this->size_;}
     int length() const {return strlen(this->buffer_);}
     int capacity() const {return this->capacity_;}
     bool empty() const {
          return (strlen(this->buffer_) == 0) ? true : false;
     }
     void clear() {this->size_ = 0; }
     char& operator[](int index) const {
          return this->buffer_[index];
     }
     char& at(int index) {
          if (index <= this->length()) return this->buffer_[index];
          else throw "The index is not valid!";
     }
     bool operator==(const String& other) {
           return strcmp(this->buffer_, other.buffer_) == 0;
          // return this->buffer_ == other.buffer_;
     }
     bool operator!=(const String& other) {
          return strcmp(this->buffer_, other.buffer_) != 0;
           // return this->buffer_ != other.buffer_;
     }
     bool operator<(const String& other) {
          return this->capacity_ < other.capacity_; 
     }
     bool operator>(const String& other) {
          return this->capacity_ > other.capacity_; 
     }
     bool operator<=(const String& other) {
          return this->capacity_ <= other.capacity_; 
     }
     bool operator>=(const String& other) {
          return this->capacity_ >= other.capacity_; 
     }
String& operator=(const String& other) {
          capacity_ = other.capacity_;
          size_ = other.size_;
          buffer_ = new char[capacity_];
          strcat(buffer_,other.buffer_);
          return *this;
     }
     ~String() {
          delete [] buffer_;
     }
     class iterator {
          char* iterator_;
     public:
          iterator(char* iterator):iterator_(iterator) {}
          iterator operator++() {
               ++iterator_;
               return *this;
          }
          iterator operator++(int) {
               iterator res = *this;
               operator++();
               return res;
          }
          bool operator==(const iterator& other) const {
               return iterator_ == other.iterator_;
          }
          bool operator!=(const iterator& other) const {
               return iterator_ != other.iterator_;
          }
          char& operator*() {
               return *iterator_;
          }
     };
     iterator begin() const { return iterator(buffer_);}
     iterator end() const {return iterator(buffer_ + size_);}
     String& append(const String& other) {
          capacity_ += other.capacity_;
          size_ += other.size_;
          strcat(buffer_,other.buffer_);
          return *this;
     }
     String& operator+=(const String& other) {
           return append(other);
     }
     void push_back(char ch) {
          capacity_ += 1;
          buffer_[size_++] = ch;
     }
     String operator+(const String& other) {
          return append(other);
     }
     int spaces() {
          int string_spaces = 0;
          for (iterator it = begin(); it != end(); ++it) if (*it == ' ') string_spaces++;
          return string_spaces;
     }
};
ostream& operator<<(ostream& out, const String& str) {
     for (int i = 0; i < str.size(); ++i) out << str[i];
     return out;
}

int main(int argc, char* argv[]) {
     String str1(argv[1]), str2(argv[2]);

     cout << "string 1: <" << str1 << ">" << endl;
     cout << "string 2: <" << str2 << ">" << endl;

     cout << "string 1 length: " << str1.length() << endl;
     cout << "string 2 length: " << str2.length() << endl;

     cout << "string 1 spaces: " << str1.spaces() << endl;
     cout << "string 2 spaces: " << str2.spaces() << endl;
     
     if (str1 == str2) cout << "<" << str1 << "> == <" << str2 << ">" << endl;
     if (str1 != str2) cout << "<" << str1 << "> != <" << str2 << ">" << endl;

     if (str1 <= str2) cout << "<" << str1 << "> <= <" << str2 << ">" << endl;
     if (str1 >= str2) cout << "<" << str1 << "> >= <" << str2 << ">" << endl;

     if (str1 > str2) cout << "<" << str1 << "> > <" << str2 << ">" << endl;
     else cout << "<" << str2 << "> < <" << str1 << ">" << endl;
     
     str1.push_back('!');
     str2.push_back('!');
     cout << "string 1: <" << str1 << ">" << endl;
     cout << "string 2: <" << str2 << ">" << endl;

     cout << "concatenation: <" << str1.append(str2) << ">" << endl;
     cout << "concatenation length: " << str1.length() << endl;
     cout << "concatenation spaces: " << str1.spaces() << endl;
     
    return 0;
}


