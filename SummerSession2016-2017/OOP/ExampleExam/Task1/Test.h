#pragma once
#include "Question.h"

class Test {
	Question** questions_;
	int capacity_;	
	int questionsCount_;
	double totalPoints_;

	void resizeTest();
	void copyTest(const Test& other);
	void destroyTest();
public:
	Test();
	Test(const Test& other);
	~Test();

	Test& operator=(const Test& other);

	int getQuestionsCount();

	void addQuestion(const char* question, const char* answer, double points);
	void addQuestion(const char*, char**, int, int, double);
	void addQuestion(const char* question, double points);
	void doTest();
	double gradeTest();
};