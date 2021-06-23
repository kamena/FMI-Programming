#include <iostream>

using namespace std;

/*A)*/
bool is_sub (const char* employee, const char* manager, const char* leaders[][2], size_t n) {
    if (n == -1) return false;
    if (leaders[n][1] == manager && leaders[n][0] == employee) return true;
    if (leaders[n][1] == manager) {
        return is_sub(employee, leaders[n+1][0], leaders, n-1);
    }
    return is_sub(employee, manager, leaders, n-1);
};

/*B)*/
const char* the_big_boss(const char* leaders[][2], size_t n) {
    bool not_found = true;
    int i;
    while (not_found) {
        not_found = false;
        
        for (i = 0; i < n; i++) {
            if (leaders[i][0] == leaders[n][1]) {
                not_found = true;
                break;
            }
        }
        n--;
    }

    return leaders[i][1];
}

int main() {
    const char* leaders[3][2] = {
        { "Ivan", "Mariya" },
        { "Boris", "Kamena" },
        { "Mariya", "Boris" }
    };
    
    cout << is_sub("Kamena", "Ivan", leaders, 2) << endl;
    
    cout << the_big_boss(leaders, 2) << endl;

    return 0;
}
