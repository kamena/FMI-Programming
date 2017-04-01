#pragma once

class Emotions : public Character {
private:
	Character emotionsFrom_;
	Character emotionsTo_;
	int hate_;
	int like_;
	bool isGood_;
public:
	Emotions();
	Emotions(Character& emotionsFrom, Character& emotionsTo, int hate, int like, bool isGood);

	Character& getEmotionsFrom();
	Character& getEmotionsTo();
	int getHate();
	int getLike();
	bool getIsGood();

	void setEmotionsTo(Character emotionsTo);
	void setHate(int hate);
	void setLike(int like);
	void setIsGood(bool isGood);
};
