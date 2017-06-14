#include "Test.h"
#include "Question.h"

void Test::resizeTest() {
	capacity_ *= 2;
    Question** temp = new Question*[capacity_];

    for(int i = 0; i < questionsCount_; i++) {
        temp[i] = questions_[i];
    }
    delete [] questions_;
    
    questions_ = new Question*[capacity_];
    questions_ = temp;
}

void Test::copyTest(const Test& other) {
	this->questionsCount_ = other.questionsCount_;

    this->questions_ = new Question*[this->questionsCount_];
    for(int i = 0; i < this->questionsCount_; i++) {
        this->questions_[i] = other.questions_[i];
    }
}

void Test::destroyTest() {
	delete [] questions_;
}

Test::Test() {
	this->questionsCount_ = 0;
    this->capacity_ = 10;
    this->questions_ = new Question*[capacity_];
    this->totalPoints_ = 0;
}

Test::Test(const Test& other) {
	copyTest(other);
}

Test::~Test() {
	destroyTest();
}

Test& Test::operator=(const Test& other) {
	if(this == &other) return *this;

	copyTest(other);

	return *this;
}


int Test::getQuestionsCount() {
	return this->questionsCount_;
}


void Test::addQuestion(const char* question, const char* answer, double points) {
	if (questionsCount_ >= capacity_) {
		resizeTest();
	}
	questions_[questionsCount_] = new YesNoQuestion(question, answer, points);
	questionsCount_++;
}

void Test::addQuestion(const char* question, char** answers, int answersCount, int answer, double points) {
	if (questionsCount_ >= capacity_) {
		resizeTest();
	}
	questions_[questionsCount_] = new MultipleChoice(question, answers, answersCount, answer, points);
	questionsCount_++;
}

void Test::addQuestion(const char* question, double points) {
	if (questionsCount_ >= capacity_) {
		resizeTest();
	}
	questions_[questionsCount_] = new OpenQuestion(question, points);
	questionsCount_++;
}

void Test::doTest() {
	cout << "The test is with " << this->questionsCount_ << " questions." << endl;
	for(int i = 0; i < this->questionsCount_; i++) {
		cout << i + 1 << ". ";
		questions_[i]->ask();
	}
	cout << endl;
}

double Test::gradeTest() {
	this->totalPoints_ = 0;
	for(int i = 0; i < this->questionsCount_; i++) {
		this->totalPoints_ += questions_[i]->grade();
	}

	return this->totalPoints_;
}
