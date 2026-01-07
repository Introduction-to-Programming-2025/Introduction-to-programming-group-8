#include <iostream>
#include <cstring>

size_t substr(const char str1[], const char str2[]) {
    size_t l1 = strlen(str1), l2 = strlen(str2);

    if (l1 < l2) {
        return l1;
    }

    for (size_t i = 0; i < l1 - l2 + 1; ++i) {
        if (str1[i] == str2[0]) {
            size_t j = 0;
            while(j < l2 && str1[i + j] == str2[j]) {
                ++j;
            }

            if (j == l2) {
                return i;
            }
        }
    }

    return l1;
}

int main() {
    char str[1025], word1[129], word2[129];

    std::cin.getline(str, 1025);
    std::cin >> word1 >> word2;


    std::cout << str << std::endl;
    std::cout << word1 << " " << word2 << std::endl;

    size_t index = substr(str, word1);

    while (index != strlen(str)) {
        char tmp[1025] = "";
        strcpy(tmp, str + index + strlen(word1));
        str[index] = '\0';
        strcat(str, word2);
        strcat(str, tmp);

        index = substr(str, word1);
    }

    std::cout << str << std::endl;


    return 0;
}
