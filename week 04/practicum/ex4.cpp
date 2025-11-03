#include <iostream>
using namespace std;

const int MAX_SIZE = 128;

void readArray(int arr[], int &n) {
    cout << "Въведете броя елементи (<= 128): ";
    cin >> n;
    if (n > MAX_SIZE) {
      n = MAX_SIZE;
    } 

    cout << "Въведете елементите: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shanoInsert(int arr[], int n, int index, int value) {
    if (index < 0 || index >= n) {
        cout << "Невалиден индекс!" << endl;
        return;
    }

    if (arr[index] == 0) {
        arr[index] = value;
        return;
    }

    int freeIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            freeIndex = i;
            break;
        }
    }

    if (freeIndex == -1) {
        cout << "Няма свободно място в масива." << endl;
        return;
    }

    int last = arr[n - 1];

    for (int i = n - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;

    if (last != arr[n - 1]) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                arr[i] = last;
                break;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, index, value;

    readArray(arr, n);

    cout << "Въведете индекс за вмъкване: ";
    cin >> index;

    cout << "Въведете стойност за вмъкване: ";
    cin >> value;

    cout << "Масив преди вмъкването:\n";
    printArray(arr, n);

    shanoInsert(arr, n, index, value);

    cout << "Масив след вмъкването:\n";
    printArray(arr, n);

    return 0;
}
