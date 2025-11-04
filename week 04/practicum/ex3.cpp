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

bool hasContiguousSubsequence(int arr[], int n, int target) {
    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int end = start; end < n; end++) {
            sum += arr[end];
            if (sum == target) {
                cout << "Подредица от индекс " << start << " до " << end << ": ";
                for (int k = start; k <= end; k++) cout << arr[k] << " ";
                cout << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, target;
    int arr[MAX_SIZE];

    readArray(arr, n);

    cout << "Въведете целевата сума: ";
    cin >> target;

    if (hasContiguousSubsequence(arr, n, target))
        cout << "Съществува непрекъсната подредица с тази сума." << endl;
    else
        cout << "Не съществува непрекъсната подредица с тази сума." << endl;

    return 0;
}
