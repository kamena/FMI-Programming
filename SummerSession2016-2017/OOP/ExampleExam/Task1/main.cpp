#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "Question.cpp"
#include "YesNoQuestion.cpp"
#include "MultipleChoice.cpp"
#include "OpenQuestion.cpp"
#include "Test.cpp"

int main() {
	Test* test = new Test();
	test->addQuestion("Do I speak German?", "no", 1);
	test->addQuestion("Is my name Kamena?", "yes", 1);
	test->addQuestion("Am I 30 years old?", "no", 1);
	test->addQuestion("Am I from Bulgaria?", "yes", 3);

	char* arr[4];
	arr[0] = (char*)"Ivana";
	arr[1] = (char*)"Hristina";
	arr[2] = (char*)"Mariq";
	arr[3] = (char*)"Gergana";

	test->addQuestion("What's my mother's name?", arr, 4, 2, 2.5);

	test->addQuestion("Tell me more about yourself.", 10.0);

	test->doTest();
	cout << "Total points: " << test->gradeTest();

	cout << endl;
	return 0;
}