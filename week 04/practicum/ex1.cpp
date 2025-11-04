#include <iostream>
using namespace std;

const int MAX_SIZE = 128;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void removeAt(int arr[], int &n, int pos) {
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void removeAfterPrimes(int arr[], int &n) {
    int i = 0;
    while (i < n - 1) {
        if (isPrime(arr[i])) {
            removeAt(arr, n, i + 1);
        } else {
            i++;
        }
    }
}

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
    cout << "Масивът след обработка: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int n;

    readArray(arr, n);
    removeAfterPrimes(arr, n);
    printArray(arr, n);

    return 0;
}