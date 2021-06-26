#include <iostream>

using namespace std;

int string_size(char* str) {
    int count = 0;
    while(str[count] != '\0') {
        count++;
    }
    return count;
};

int* double_pos(char* str) {
    int size = string_size(str);
    int* double_points = new int(2);
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (i >= size / 2 && found) break;
        for (int j = size - 1; j > i; j--) {
            if (double_points[1] - double_points[0] > j - i) {
                break;
            }
            if (str[i] == str[j]) {
                found = true;
                double_points[0] = i;
                double_points[1] = j;
            }
        }
    }

    return double_points;
};

int main() {
    char* str = (char*)"this is just a simple example";
    cout << str << endl;

    int* positions = double_pos(str);
    cout << positions[0] << " " << positions[1] << endl;
    return 0;
}
