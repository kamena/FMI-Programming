#include "Character.h"
#include "Emotions.h"

Emotions::Emotions() {
	hate_ = 0;
	like_ = 0;
	isGood_ = true;
}

Emotions::Emotions(Character& emotionsFrom, Character& emotionsTo, int hate, int like, bool isGood)
: Character(emotionsFrom), emotionsTo_(emotionsTo), hate_(hate), like_(like), isGood_(isGood) 
{
	emotionsFrom_ = emotionsFrom;
}

Character& Emotions::getEmotionsFrom(){
	return emotionsFrom_;
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
