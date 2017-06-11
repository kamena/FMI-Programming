#pragma once
#include "Episode.h"

class Character : public Episode {
private:
	char* name_;
	int age_;
	char* gander_;
	// Emotions emotions_;

	void copyCharacter(const Character& other);
public:
	Character();
	Character(const char* name, int age, const char* gander, Episode* episodes);
	Character(const Character& other);
	~Character();

	Character& operator=(const Character& other);

	char* getName();
	int getAge();
	// Emotions& getEmotions(Character& emotionsTo);
	char* getGander();

	void setName(const char* name);
	void setAge(int age);
	void setGander(const char* gander);
	// void setEmotion(Emotions& emotions);

	void printCharacter();
};
