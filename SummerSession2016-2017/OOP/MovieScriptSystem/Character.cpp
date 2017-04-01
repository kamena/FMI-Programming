#include "Character.h"

Character::Character() {
	name_ = "Kamena";
	age_ = 18;
	gander_ = "female";
}

Character::Character(string name, int age, string gander, Episode& episode)
: name_(name), age_(age), gander_(gander), Episode(episode)
{}

string Character::getName(){
	return this->name_;
}
int Character::getAge(){
	return this->age_;
}
string Character::getGander(){
	return this->gander_;
}
// Emotions& getEmotions(Character& emotionsTo) {
// 	return emotions_->emotionsTo_ == emotionsTo;
// }

void Character::setName(string name){
	name_ = name;
}
void Character::setAge(int age){
	age_ = age;
}
void Character::setGander(string gander){
	gander_ = gander;
}
// void setEmotion(Emotions& emotions){
// 	emotions_ = emotions;
// }
