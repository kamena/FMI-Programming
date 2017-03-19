#pragma once
#include "EngineType.h"

class Engine {
private:
	int hp_;
	int volume_;
	EngineType type_;
public:
	Engine();
	Engine(int hp, int volume, EngineType type);

	int getHp();
	int getVolume();
	int getEngineType();

	void setHp(int hp);
	void setVolume(int volume);
	void setEngineType(EngineType type);
};
