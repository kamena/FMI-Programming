#pragma once
#include "Question.h"

class OpenQuestion : public Question {
	char* question_;
	double points_;
	char* givenAnswer_;

	void copyOpenQuestion(const OpenQuestion& other);
public:
	OpenQuestion();
	OpenQuestion(const char* question, double points);
	~OpenQuestion();

	OpenQuestion& operator=(const OpenQuestion& other);

	void ask();
	double grade();
};