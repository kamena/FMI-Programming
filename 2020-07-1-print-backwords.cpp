#include <iostream>
// #include <string>
#include <cstring>

using namespace std;


void print_backwords(const char* begin, const char* end) {
    // string word = (char*)"";
    const char* originalEnd = end;
    do {
        end--;
        // word.insert(word.begin(), *(end--));
    } while (*end > 32 && end != begin);
    // cout << word << " ";
    const char* newEnd = end;
    do {
        if (*end != 32) cout << *(end);
        end++;
    } while (end != originalEnd);
    cout << " ";
    if (newEnd + 1 == begin) return;
    return print_backwords(begin, newEnd);
}

void print_backwords(const char* string) {
    print_backwords(string, string + strlen(string));
}

int main() {
    print_backwords("I need a break!");
    return 0;
}
