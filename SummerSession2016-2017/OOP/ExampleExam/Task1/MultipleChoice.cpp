#include "MultipleChoice.h"

void MultipleChoice::copyMultipleChoice(const MultipleChoice& other) {
	this->question_ = new char[strlen(other.question_) + 1];
    strcpy(this->question_, other.question_);
	
	this->answersCount_ = other.answersCount_;
	
	this->answers_ = new char* [answersCount_];
    for(int i = 0; i < answersCount_; i++) {
    	this->answers_[i] = new char[strlen(other.answers_[i]) + 1];
   		strcpy(this->answers_[i], other.answers_[i]);
    } 

	this->correctAnswer_ = other.correctAnswer_;
	this->points_ = other.points_;
}

MultipleChoice::MultipleChoice() {
	question_ = NULL;
	answers_ = NULL;
	answersCount_ = 0;
	correctAnswer_ = 0;
	points_ = 0;
}

MultipleChoice::MultipleChoice(const char* question, char** answers, int answersCount, int correctAnswer, double points) {
    this->question_ = new char[strlen(question) + 1];
    strcpy(this->question_, question);

	this->answersCount_ = answersCount;
	this->answers_ = new char* [answersCount_];
    for(int i = 0; i < answersCount_; i++) {
    	this->answers_[i] = new char[strlen(answers[i]) + 1];
   		strcpy(this->answers_[i], answers[i]);
    } 

	this->correctAnswer_ = correctAnswer;
	this->points_ = points;
}

MultipleChoice::~MultipleChoice() {
	delete [] question_;
	delete [] answers_;
}

MultipleChoice& MultipleChoice::operator=(const MultipleChoice& other) {
	if(this == &other) return *this;
	copyMultipleChoice(other);
	return *this;
}

void MultipleChoice::ask() {
	cout << this->question_ << endl;

	for(int i = 0; i < answersCount_; i++) {
		cout << i + 1 << ") " << this->answers_[i] << endl;
	}

	cin >> this->answeredNum_;
}

double MultipleChoice::grade() {
	if(this->answeredNum_ == this->correctAnswer_) {
		return this->points_;
	}
	return 0;
}
