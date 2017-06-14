#include "YesNoQuestion.h"

void YesNoQuestion::copyYesNoQuestion(const YesNoQuestion& other) {
    this->question_ = new char[strlen(other.question_) + 1];
    strcpy(this->question_, other.question_);

    this->answer_ = new char[strlen(other.answer_) + 1];
    strcpy(this->answer_, other.answer_);
	
	this->points_ = other.points_;
}

YesNoQuestion::YesNoQuestion(){
	this->question_ = NULL;
	this->answer_ = NULL;
	this->points_ = 0;
}

YesNoQuestion::YesNoQuestion(const char* question, const char* answer, double points){
	this->question_ = new char[strlen(question) + 1];
    strcpy(this->question_, question);

    this->answer_ = new char[strlen(answer)  + 1];
    strcpy(this->answer_, answer);

	this->points_ = points;
}

YesNoQuestion::~YesNoQuestion() {
	delete [] question_;
	delete [] answer_;
}

YesNoQuestion& YesNoQuestion::operator=(const YesNoQuestion& other) {
	if(this == &other) return *this;

	copyYesNoQuestion(other);

	return *this;
}

void YesNoQuestion::ask(){
	cout << this->question_ << " ";
	cout << "Type: 'yes' or 'no'? " << endl;

	this->givenAnswer_ = new char[10];
    cin.getline(this->givenAnswer_, 10);
}

double YesNoQuestion::grade() {
	if(!strcmp(this->answer_, this->givenAnswer_)) {
		return this->points_;
	} 
	return 0;
}
