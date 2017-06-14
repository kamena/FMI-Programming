#pragma once

class Question {
public:
	Question();
	~Question();

	virtual void ask() = 0;
	virtual double grade() = 0;
};