#include "Team.h"

const int DEFAULT_CAP = 2;

Team::Team() {
	this->players_ = new Player[DEFAULT_CAP];
	this->playersCount_ = 0;
	this->capacity_ = DEFAULT_CAP;
	this->budget_ = 0;
}

Team::Team(string teamName, Player* players, int playersCount, int budget) {
	teamName_ = teamName;
	if(playersCount >= DEFAULT_CAP) {
		this->capacity_ = playersCount * 2;
	} else {
		this->capacity_ = DEFAULT_CAP;
	}
	players_ = new Player[capacity_];
	for (int i = 0; i < playersCount; ++i) {
		players_[i].copyPlayer(players[i]);
	}
	playersCount_ = playersCount;	

	budget_ = budget;
}

Team::~Team() {
	delete[] players_;
}

string Team::getTeamName() {
	return teamName_;
}

int Team::getPlayersCount() {
	return playersCount_;
}

int Team::getCapacity() {
	return capacity_;
}

int Team::getBudget() {
	return budget_;
}

void Team::setTeamName(string teamName) {
	teamName_ = teamName;
}

void Team::setPlayers(Player* players, int playersCount) {
	if(this->playersCount_ != playersCount) {
		delete[] players_;
		this->players_ = new Player[capacity_];
	}

	for (int i = 0; i < playersCount; ++i) {
		this->players_[i].copyPlayer(players[i]);
	}
	this->playersCount_ = playersCount;
}

void Team::setPlayersCount(int playersCount) {
	playersCount_ = playersCount;
} 

void Team::setBudget(int budget) {
	budget_ = budget;
}

void Team::isBudgetEnough() {
	int count = 0;
	for (int i = 0; i < playersCount_; i++) {
		count += players_[i].getSalary();
	}
	if (count <= budget_) {
		cout << "The budget is enough!" << endl; 
		return ;
	} 

	cout << "The budget is not enough" << endl;
}

void Team::teamResize(int capacity) {

	Player* temp = new Player[capacity];
    for (int i = 0; i < this->playersCount_; ++i) {
       temp[i] = this->players_[i];
    }

    delete[] this->players_;
    this->players_ = temp;
	this->capacity_ = capacity;
}

void Team::addPlayer(Player& player) {
	if(this->playersCount_ >= this->capacity_) {
		this->teamResize(this->capacity_ * 2);
	}
	players_[playersCount_].copyPlayer(player);
	playersCount_++;
}

void Team::printTeamInfo() {
	cout << this->getTeamName() << endl;
	for (int i = 0; i < playersCount_; i++) {
		cout << players_[i].getName() << endl;
	}
}