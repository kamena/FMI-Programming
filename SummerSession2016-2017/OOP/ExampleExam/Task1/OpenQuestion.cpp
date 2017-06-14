#include "OpenQuestion.h"

void OpenQuestion::copyOpenQuestion(const OpenQuestion& other){
	this->question_ = new char[strlen(other.question_) + 1];
    strcpy(this->question_, other.question_);

    this->points_ = other.points_;
}

OpenQuestion::OpenQuestion(){
	question_ = NULL;
	points_ = 0;
}

OpenQuestion::OpenQuestion(const char* question, double points){
	this->question_ = new char[strlen(question) + 1];
    strcpy(this->question_, question);

    this->points_ = points;
}

OpenQuestion::~OpenQuestion(){
	delete [] question_;
	delete [] givenAnswer_;
}


OpenQuestion& OpenQuestion::operator=(const OpenQuestion& other){
	if(this == &other) return *this;

	copyOpenQuestion(other);
	return *this;
}

void OpenQuestion::ask(){

	cout << this->question_ << endl;

	cin.ignore();
	this->givenAnswer_ = new char[100];
    cin.getline(this->givenAnswer_, 100);
}

double OpenQuestion::grade(){
	cout << this->question_ << endl 
	<< "****************************" << endl
	<< "Given Answer: " << endl << this->givenAnswer_ << endl
	<< "****************************" << endl;

	double percentages;
	cout << "Input the grade in percentages: ";
	cin >> percentages;

	return points_ * percentages / 100;
}
