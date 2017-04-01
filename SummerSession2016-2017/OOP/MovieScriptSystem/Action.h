#pragma once

#include "ActionType.h"

class Action : public Episode {
private:
	Character between1_;
	Character between2_;
	ActionType type_;
public:
	Action();
	Action(Character& between1, Character& between2, ActionType type, Episode& episode);

	ActionType getActionType();
	Character& getBetween1();
	Character& getBetween2();
	
	void setActionType(ActionType type);
	void setBetween1(Character& between1);
	void setBetween2(Character& between2);

};
