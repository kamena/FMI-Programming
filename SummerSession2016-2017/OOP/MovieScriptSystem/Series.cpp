#include "Series.h"
#include "Character.h"
#include <cstring>

void Series::copySeries(const Series& other) {
	this->seriesName_ = new char[strlen(other.seriesName_) + 1];
	strcpy(this->seriesName_, other.seriesName_);

	this->charactersCount_ = other.charactersCount_;

    this->characters_ = new Character*[this->charactersCount_];
    for(int i = 0; i < this->charactersCount_; i++) {
        this->characters_[i] = other.characters_[i];
    }
}

void Series::resizeSeries() {
	capacity_ *= 2;
    Character** temp = new Character*[capacity_];

    for(int i = 0; i < charactersCount_; i++) {
        temp[i] = characters_[i];
    }
    delete [] characters_;
    
    characters_ = new Character*[capacity_];
    characters_ = temp;
}

Series::Series(){
	this->seriesName_ = NULL;
	this->charactersCount_ = 0;
    this->capacity_ = 10;
    this->characters_ = new Character*[capacity_];	
}

Series::Series(const char* name, Character** characters, int charactersCount) {
	this->seriesName_ = new char[strlen(name) + 1];
	strcpy(this->seriesName_, name);

	this->charactersCount_ = charactersCount;

    this->characters_ = new Character*[this->charactersCount_];
    for(int i = 0; i < this->charactersCount_; i++) {
        this->characters_[i] = characters[i];
    }
}

Series::Series(const Series& other){
	copySeries(other);
}
Series::~Series(){
	delete [] this->seriesName_;
	delete [] this->characters_;
}

Series& Series::operator=(const Series& other){
	if(this == &other) return *this;
	delete [] this->seriesName_;
	copySeries(other);

	return *this;
}

char* Series::getSeriesName() {
	return this->seriesName_;
}

int Series::getCharactersCount() {
	return this->charactersCount_;
}

void Series::setSeriesName(const char* name) {
	this->seriesName_ = new char[strlen(name) + 1];
	strcpy(this->seriesName_, name);
}

void Series::addCharacter(Character* newCharacter){
    if(this->capacity_ == this->charactersCount_) {
        resizeSeries();
    }

    this->characters_[this->charactersCount_++] = newCharacter;
}

void Series::printCharacters() {
	for(int i = 0; i < this->charactersCount_; i++) {
		cout << i << ". " << this->characters_[i]->getName() << endl;
	}
	cout << endl;
}

char* Series::printCharacterFromList(int i) {
	return characters_[i]->getName();
}