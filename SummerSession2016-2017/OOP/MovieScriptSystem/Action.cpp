#include "Action.h"

Action::Action(){
	this->type_ = RELATIONSHIP;
}

Action::Action(Character& between1, Character& between2, ActionType type, Episode& episode)
: between1_(between1), between2_(between2), type_(type), Episode(episode) {}

ActionType Action::getActionType(){
	return this->type_;
}
Character& Action::getBetween1(){
	return this->between1_;
}
Character& Action::getBetween2(){
	return this->between2_;
}

void Action::setActionType(ActionType type){
	this->type_ = type;
}
void Action::setBetween1(Character& between1){
	this->between1_ = between1;
}

void Action::setBetween2(Character& between2){
	this->between2_ = between2;
}