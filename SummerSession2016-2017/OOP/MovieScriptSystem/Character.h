#pragma once

class Character : public Episode {
private:
	string name_;
	int age_;
	string gander_;
	// Emotions emotions_;
public:
	Character();
	Character(string name, int age, string gander, Episode& episodes);

	string getName();
	int getAge();
	// Emotions& getEmotions(Character& emotionsTo);
	string getGander();


	void setName(string name);
	void setAge(int age);
	void setGander(string gander);
	// void setEmotion(Emotions& emotions);
};
