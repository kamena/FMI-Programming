#pragma once
#include "Question.h"

class MultipleChoice : public Question {
	char* question_;
	char** answers_;
	int answersCount_;
	int correctAnswer_;
	double points_;
	int answeredNum_;

	void copyMultipleChoice(const MultipleChoice& other);
public:
	MultipleChoice();
	MultipleChoice(const char* question, char** answers, int answersCount, int correctAnswer, double points);
	~MultipleChoice();

	MultipleChoice& operator=(const MultipleChoice& other);

	void ask();
	double grade();
};