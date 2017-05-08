#include "Character.h"
#include "Emotions.h"

void Emotions::copyEmotions(const Emotions& other){
	this->emotionsTo_ = other.emotionsTo_;
	this->hate_ = other.hate_;
	this->like_ = other.like_;
	this->isGood_ = other.isGood_;
}

Emotions::Emotions() {
	hate_ = 0;
	like_ = 0;
	isGood_ = true;
}

Emotions::Emotions(Character& emotionsFrom, Character& emotionsTo, int hate, int like, bool isGood)
: Character(emotionsFrom), emotionsTo_(emotionsTo), hate_(hate), like_(like), isGood_(isGood) 
{}

Emotions::Emotions(const Emotions& other) : Character(other){
	copyEmotions(other);
}
Emotions::~Emotions(){}

Emotions& Emotions::operator=(const Emotions& other){
	if(this == &other) return *this;
	Character::operator=(other);
	copyEmotions(other);

	return *this;
}

Character& Emotions::getEmotionsTo(){
	return emotionsTo_;
}
int Emotions::getHate(){
	return hate_;
}
int Emotions::getLike(){
	return like_;
}
bool Emotions::getIsGood(){
	return isGood_;
}

void Emotions::setEmotionsTo(Character emotionsTo){
	emotionsTo_ = emotionsTo;
}
void Emotions::setHate(int hate){
	hate_ = hate;
}
void Emotions::setLike(int like){
	like_ = like;
}
void Emotions::setIsGood(bool isGood){
	isGood_ = isGood;
}
