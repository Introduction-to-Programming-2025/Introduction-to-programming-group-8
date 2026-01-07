#include <iostream>
#include <cstring>

void deleteWords(char** &words, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        delete[] words[i];
    }

    delete[] words;
}

void resize(char** &words, size_t &size) {
    char** temp = new char*[size + 1];

    for (size_t i = 0; i < size; ++i) {
        temp[i] = new char[strlen(words[i]) + 1];
        temp[i][0] = '\0';
        strcpy(temp[i], words[i]);
    }

    deleteWords(words, size);
    words = temp;
    ++size;
}

void transform(char array[], char delimiter) {
    size_t len = strlen(array);

    // замяна на всеки знак, различен от буква, с разделител
    for (size_t i = 0; i < len; ++i) {
        if (!std::isalpha(array[i])) {
            array[i] = delimiter;
        }
    }

    // добавяне на разделител в края за по-лесно обхождане
    array[len] = delimiter;
    array[len + 1] = '\0';
} 

void toWords(char array[], char** &words, size_t &size) {
    char delimiter = '\n';
    transform(array, delimiter);

    size = 0;

    bool inWord = false;
    size_t wordStart = 0, l = strlen(array);

    for (size_t i = 0; i < l; ++i) {
        if (array[i] == delimiter) {
            if (inWord) {
                inWord = false;

                resize(words, size);

                size_t iSize = i - wordStart;
                words[size - 1] = new char[iSize + 1];
                for (size_t j = 0; j < iSize; ++j) {
                    words[size - 1][j] = array[wordStart + j];
                }
                words[size - 1][iSize] = '\0';
            }
        }
        else {
            if (!inWord) {
                inWord = true;
                wordStart = i;
            }
        }
    }

}

void toSet(char** &words, size_t &size) {
    char** tmp = new char*[1];
    size_t tmpSize = 1;
    tmp[0] = new char[strlen(words[0]) + 1];
    tmp[0][0] = '\0';
    strcpy(tmp[0], words[0]);

    for (size_t i = 1; i < size; ++i) {
        bool found = false;

        for (size_t j = 0; j < tmpSize && !found; ++j) {
            found = (strcmp(words[i], tmp[j]) == 0);
        }

        if (!found) {
            resize(tmp, tmpSize);
            tmp[tmpSize - 1] = new char[strlen(words[i]) + 1];
            tmp[tmpSize - 1][0] = '\0';
            strcpy(tmp[tmpSize - 1], words[i]);
        }
    }

    deleteWords(words, size);
    words = tmp;
    size = tmpSize;
}

int difference(char* str1, char* str2) {
    int diff = 0;

    size_t l1 = strlen(str1), l2 = strlen(str2);
    size_t size = l1 < l2 ? l1 : l2;

    for (size_t i = 0; i < size; ++i) {
        if (str1[i] != str2[i]) {
            ++diff;
        }
    }

    if (l1 != l2) {
        diff += l1 < l2 ? l2 - l1 : l1 - l2;
    }

    return diff;
}

int main() {
    const size_t STRSIZE = 128;

    char array[STRSIZE + 1];

    std::cin.getline(array, STRSIZE);

    char** words = nullptr;
    size_t n = 0;

    toWords(array, words, n);
    toSet(words, n);

    for (size_t i = 0; i < n; ++i) {
        std::cout << words[i] << std::endl;
    }

    size_t index1, index2;
    int minDiff = -1;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            int diff = difference(words[i], words[j]);
            if (minDiff == -1 || diff < minDiff) {
                minDiff = diff;
                index1 = i;
                index2 = j;
            }
        }
    }

    std::cout << words[index1] << " " << words[index2] << " " << minDiff << std::endl;

    deleteWords(words, n);

    return 0;
}