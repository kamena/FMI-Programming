#pragma once

class Emotions : public Character {
private:
	Character emotionsTo_;
	int hate_;
	int like_;
	bool isGood_;

	void copyEmotions(const Emotions& other);
public:
	Emotions();
	Emotions(Character& emotionsFrom, Character& emotionsTo, int hate, int like, bool isGood);
	Emotions(const Emotions& other);
	~Emotions();

	Emotions& operator=(const Emotions& other);

	Character& getEmotionsTo();
	int getHate();
	int getLike();
	bool getIsGood();

	void setEmotionsTo(Character emotionsTo);
	void setHate(int hate);
	void setLike(int like);
	void setIsGood(bool isGood);
};
