/******************************************************
Скрити подсказки за парола в библиотека от книги.
Редове книги <= 20
Книги на ред <= 30
Заглавие на книга <= 100 символа

Паролата се определя от средната книга на ред подреден по азбучен ред.

{
        {"Алгебра", "Аналитична геометрия", "Математически анализ"},
        {"Увод в програмирането, Обектрно-приентирано програмиране", "Структури от данни и програмиране"},
        {"Бази от данни", "Изкуствен интелект", "Функционално програмиране"}
}

Първи и втори ред са подредени по азбучен ред => паролата се определя от броя на цифрите на думите в тези заглавия.
Тоест:
Аналитична геометрия - 10 9
Изкуствен интелект - 9 8

=> паролата е 10 9 9 8
*******************************************************/

#include <iostream>

using namespace std;

int getLength(char* str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

bool isAlphabaticOrder(char a[100], char b[100]) {
    int length_a = getLength(a);
    int length_b = getLength(b);
    
    int smaller = length_a < length_b ? length_a : length_b;

    for (int i = 0; i < smaller; i++) {
        if (a[i] > b[i]) return false;
        if (a[i] < b[i]) return true;
    }
    
    return true;
}

void resize(int* arr, int& size) {
   int* resize_arr = new int[size + 1];
   for(int i = 0; i < size; i++)
        resize_arr[i] = arr[i];

   size++;
   arr = resize_arr;
   delete[] resize_arr;
}

void revealPassword(char a[20][30][100], int m, int n) {
    int size = 2;
    int* password = new int[size];
    int index = 0;
    
    bool isAlphabetic = true;
    for (int i = 0; i < m; i++) {
        isAlphabetic = true;
        for (int j = 0; j < n - 1; j++) {
            if (!isAlphabaticOrder(a[i][j], a[i][j+1])) {
                isAlphabetic = false;
                break;
            }
        }

        if (isAlphabetic) {
            int middle = n % 2 == 0 ? n / 2 - 1 : n / 2;
            char* title = a[i][middle];
            int count = 0;
            for (int titleIndex = 0; titleIndex <= getLength(title); titleIndex++) {
                count++;
                if (title[titleIndex] == ' ' || title[titleIndex] == '\0') {
                    password[index++] = count - 1;
                    if (index >= size) resize(password, size);
                    count = 0;
                }
            }
        }
    }

    for (int i = 0; i < size - 1; i++) {
        cout << password[i] << " ";
    } 
    cout << "\n";
}

int main() {
    // char* library[20][30] = {
    //     {"Алгебра", "Аналитична геометрия", "Математически анализ"},
    //     {"Увод в програмирането, Обектрно-приентирано програмиране", "Структури от данни и програмиране"},
    //     {"Бази от данни", "Изкуствен интелект", "Функционално програмиране"}
    // };
    
    char library2[20][30][100] = {
        {"AHello", "BWorld me", "CThis is me!!!", "Def"},
        {"Not", "Progressibe", "ARow", "qq"},
        {"Asd", "Cqwerty a", "Gasd qwerty", "qq"},
        {"Bah", "EShit", "f", "qq"}
    };
    
    revealPassword(library2, 4, 4);
    return 0;
}
