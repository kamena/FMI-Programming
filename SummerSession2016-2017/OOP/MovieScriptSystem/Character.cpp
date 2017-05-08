#include "Character.h"

void Character::copyCharacter(const Character& other){
	this->name_ = new char[strlen(other.name_) + 1];
	strcpy(this->name_, other.name_);

	this->age_ = other.age_;

	this->gander_ = new char[strlen(other.gander_) + 1];
	strcpy(this->gander_, other.gander_);	
}

Character::Character() {
	name_ = NULL;
	age_ = 0;
	gander_ = NULL;
}

Character::Character(const char* name, int age, const char* gander, Episode& episode)
: age_(age), Episode(episode)
{
	this->name_ = new char[strlen(name) + 1];
	strcpy(this->name_, name);

	this->gander_ = new char[strlen(gander) + 1];
	strcpy(this->gander_, gander);
}

Character::Character(const Character& other) : Episode(other) {
	copyCharacter(other);
}
Character::~Character(){
	delete [] this->name_;
	delete [] this->gander_;
}

Character& Character::operator=(const Character& other){
	if(this == &other) return *this;
	delete [] this->name_;
	delete [] this->gander_;
	Episode::operator=(other);
	copyCharacter(other);

	return *this;
}

char* Character::getName(){
	return this->name_;
}
int Character::getAge(){
	return this->age_;
}
char* Character::getGander(){
	return this->gander_;
}
// Emotions& getEmotions(Character& emotionsTo) {
// 	return emotions_->emotionsTo_ == emotionsTo;
// }

void Character::setName(const char* name){
	this->name_ = new char[strlen(name) + 1];
	strcpy(this->name_, name);
}
void Character::setAge(int age){
	age_ = age;
}
void Character::setGander(const char* gander){
	this->gander_ = new char[strlen(gander) + 1];
	strcpy(this->gander_, gander);
}
// void setEmotion(Emotions& emotions){
// 	emotions_ = emotions;
// }
