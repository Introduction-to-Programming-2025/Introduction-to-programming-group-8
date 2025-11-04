#include <iostream>

int main() {
    const size_t MAX_SIZE = 128;
    size_t n;
    char arr[MAX_SIZE];

    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    bool isPalindrome = true;

    for (size_t i = 0, j = n - 1;
        i < j && isPalindrome; ++i, --j){
        isPalindrome = (arr[i] == arr[j]);
    }
    
    std::cout << std::boolalpha << isPalindrome << std::endl;

    return 0;
}
