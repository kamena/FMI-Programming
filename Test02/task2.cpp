// Сашето и Ванката са тайни агенти на ФБР. След дълго служене им остава една последна
// задача - да открият и заличат най-опасните престъпници в света. Началниците им са им
// дали списък с детайлно описани местоположенията на всеки един от нарушители на
// закона. Тъй като всеки един от престъпниците е завършил специалност "Информационни
// системи" някъде из най-елитните университети по света, има способностите да
// проследява и извлича съобщения от какъвто и да е вид, списъкът е пратен на нашите
// спасители в кодиран вариант.
// Помогнете на Сашето и Ванката да декодират съобщението като напишете функция,
// която изтрива даден подниз в друг низ и връща указател към първата позиция, от която е
// изтривано (или NULL/nullptr, ако поднизът не се съдържа).
// Пример:
// Низ: James BoAskdianan Nlsloeurchier 5
// Подниз: Askdianan Nlsloe
// Низ след премахването на подниза: James Bourchier 5
// Върнатият указател трябва да сочи буквата “u”

#include <iostream>
#include <cstring>

using namespace std;

int deleteArr(char *str, char *strToDelete) {
	int sizeStr = strlen(str);
	int sizeStrToDelete = strlen(strToDelete);
	int position = 0;
	for(int i = 0; i < sizeStr; i++) {
		if(str[i] == strToDelete[position]) {
			position++;
		} else if(position == sizeStrToDelete) {
			int pos = i-1;
			for(int l = i-position; l < sizeStr-sizeStrToDelete; l++) {
				str[l] = str[pos+1];
				pos++;
			}

			return i-position;
		} else {position = 0;}
	}
	cout << position;
	return -1;
}

int main() {
	char str[1024] =  "James BoAskdianan Nlsloeurchier 5";
	char strToDelete[1024] = "Askdianan Nlsloe";

	cout << "Position where first deleted: " << deleteArr(str, strToDelete) << endl;
	int sizeStr = strlen(str);
	int sizeStrToDelete = strlen(strToDelete);
	for (int i = 0; i < sizeStr-sizeStrToDelete; i++) {
		cout << str[i];
	}

	return 0;
}