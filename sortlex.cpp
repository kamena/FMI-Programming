#include <iostream>

using namespace std;

int getIntLength(int num) {
    if (num / 10 == 0) return 1;
    int i = 0;
    while (num > 0) {
        num /= 10;
        i++;
    }
    return i;
}

int getDec(int num) {
    int dec = 1;
    for (int i = 0; i < num; i++) {
        dec *= 10;
    } 
    return dec;
}

bool isIntBiggerLex(int a, int b) {
    int length_a = getIntLength(a);
    int length_b = getIntLength(b);

    int smaller = length_a < length_b ? length_a : length_b;
    int areDifferent = false;

    for (int i = 0; i <= smaller; i++) {
        int dec_a = getDec(length_a - i);
        int dec_b = getDec(length_b - i);
        if (a / dec_a < b / dec_b) return false;
        if (!areDifferent && a / dec_a != b / dec_b) areDifferent = true;
    }
    
    return !areDifferent ? a > b : true;
}

void sortlex(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isIntBiggerLex(arr[i], arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {105, 68, 190, 1000, 58, 11};
    int arr2[] = {17,29,3019,208,32,2190,56};
    int arr3[] = {5, 190, 1000, 5, 11, 22};
    int arr4[] = {17,29,301,208,32,3019,2190,56};
    int arr5[] = {17,29,301,208,209,32,2190,56, 564,2092,3019,201954, 563};
    sortlex(6, arr);
    sortlex(7, arr2);
    sortlex(6, arr3);
    sortlex(8, arr4);
    sortlex(13, arr5);
    return 0;
}
