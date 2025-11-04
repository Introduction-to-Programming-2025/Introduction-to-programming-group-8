#include <iostream>
using namespace std;

const int MAX_SIZE = 128;
const int MAX_VALUE = 100;

int secondMostFrequent(const int arr[], int n, bool &exists) {
    int freq[MAX_VALUE + 1] = {0};

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] <= MAX_VALUE)
            freq[arr[i]]++;
    }

    int firstMax = 0, secondMax = 0;
    for (int i = 0; i <= MAX_VALUE; i++) {
        if (freq[i] > firstMax) {
            secondMax = firstMax;
            firstMax = freq[i];
        } else if (freq[i] > secondMax && freq[i] < firstMax) {
            secondMax = freq[i];
        }
    }

    if (secondMax == 0) {
        exists = false;
        return -1;
    }

    for (int i = 0; i <= MAX_VALUE; i++) {
        if (freq[i] == secondMax) {
            exists = true;
            return i;
        }
    }

    exists = false;
    return -1;
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

int main() {
    int arr[MAX_SIZE];
    int n;
    bool exists;

    readArray(arr, n);

    int result = secondMostFrequent(arr, n, exists);

    if (exists)
        cout << "Вторият най-често срещан елемент е: " << result << endl;
    else
        cout << "Няма втори най-често срещан елемент." << endl;

    return 0;
}
