#pragma once
#include "Question.h"

class YesNoQuestion : public Question {
	char* question_;
	char* answer_;
	char* givenAnswer_;
	double points_;

	void copyYesNoQuestion(const YesNoQuestion& other);
public:
	YesNoQuestion();
	YesNoQuestion(const char* question, const char* answer, double points);
	~YesNoQuestion();

	YesNoQuestion& operator=(const YesNoQuestion& other);

	void ask();
	double grade();
};