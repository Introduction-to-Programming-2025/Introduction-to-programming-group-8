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

void findTriplets(int arr[], int n) {
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
              continue;
            }

            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                  continue;
                }

                if (arr[i] + arr[j] == arr[k]) {
                    cout << "arr[" << i << "] + arr[" << j << "] = arr[" << k << "]  -->  "
                        << arr[i] << " + " << arr[j] << " = " << arr[k] << endl;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << "Няма такива тройки индекси." << endl;
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    readArray(arr, n);

    findTriplets(arr, n);

    return 0;
}
