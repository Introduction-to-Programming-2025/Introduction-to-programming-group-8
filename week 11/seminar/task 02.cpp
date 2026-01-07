#include <iostream>
#include "stringExtention.hpp"

int main() {
    const size_t STRSIZE = 128;
    size_t n;

    std::cin >> n;
    std::cin.ignore();

    char **words = new char*[n];

    for (int i = n - 1; i >= 0 ; --i) {
        words[i] = new char[STRSIZE + 1];

        std::cin.getline(words[i], STRSIZE);
    } 

    char *sentence = new char[(STRSIZE + 1) * 1024];

    // for (int i = 0; i < n / 2; ++i) {
    //     std::swap(words[i], words[n - 1 - i]);
    // }

    join(sentence, words, n);

    std::cout << sentence << std::endl;

    for(size_t i = 0; i < n; ++i) {
        delete[] words[i];
    }
    delete[] words;

    return 0;
}
