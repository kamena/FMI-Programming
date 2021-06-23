#include <iostream>

using namespace std;

bool find(int value, int* arr, size_t size) {
    if (size == 0) return false;
    
    size_t mid = size / 2;
    if (value == arr[mid]) return true;

    if (value < arr[mid]) {
        return find(value, arr, mid);
    } else {
        return find(value, arr + mid, mid);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 15, 19, 24, 53, 68, 69, 75};
    cout << sizeof(arr)/sizeof(arr[0]) << endl << endl;
    cout << find(75, arr, 16);
    return 0;
}
