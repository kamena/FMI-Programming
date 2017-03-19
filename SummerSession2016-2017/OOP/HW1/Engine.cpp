#include "Engine.h"

Engine::Engine() {
	hp_ = 0;
	volume_ = 0;
	this->type_ = DIESEL;
}

Engine::Engine(int hp, int volume, EngineType type) {
	hp_ = hp;
	volume_ = volume;
	this->type_ = type;
}

int Engine::getHp(){
	return hp_;
}
int Engine::getVolume(){
	return volume_;
}
int Engine::getEngineType(){
	return this->type_;
}

void Engine::setHp(int hp){
	hp_ = hp;
}
void Engine::setVolume(int volume){
	volume_ = volume;
}
void Engine::setEngineType(EngineType type){
	this->type_ = type;
}