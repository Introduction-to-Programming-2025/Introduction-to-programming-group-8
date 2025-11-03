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
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void moveNegativesFirst(int arr[], int n) {
    int temp[MAX_SIZE];
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
          temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
          temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    readArray(arr, n);

    cout << "Масив преди преобразуване:\n";
    printArray(arr, n);

    moveNegativesFirst(arr, n);

    cout << "Масив след преобразуване:\n";
    printArray(arr, n);

    return 0;
}
