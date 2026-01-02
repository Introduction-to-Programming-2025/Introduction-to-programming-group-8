#ifndef __STRING_EXTENTION__
#define __STRING_EXTENTION__
#include <cstring>

// символ за край на низа
const char STREND = '\0';


// strncpy
// копиране на низ
void nCopy(char* &str1, const char* str2, const size_t n) {
    delete[] str1;
    str1 = new char[n + 1];

    size_t i = 0;

    while (i < strlen(str2) && i < n) {
        str1[i] = str2[i];
        ++i;
    }

    str1[i] = STREND;
}

void addToList(const char* str, char** &list, size_t &size) {
    char **tmp = new char*[size + 1];

    for (size_t i = 0; i < size; ++i) {
        tmp[i] = new char[strlen(list[i]) + 1];
        strcpy(tmp[i], list[i]);
    }

    tmp[size] = new char[strlen(str) + 1];
    strcpy(tmp[size], str);

    for (size_t i = 0; i <size; ++i) {
        delete[] list[i];
    }
    delete[] list;

    list = tmp;
    ++size;
}

void addToSet(const char* str, char** &set, size_t &size) {
    for (size_t i = 0; i < size; ++i) {
        if (!strcmp(str, set[i])) {
            return;
        }
    }

    addToList(str, set, size);
}

void split(const char* str, char** &list, size_t &size, char delimiter = ' ') {
    for (size_t i = 0; i < size; ++i) {
        delete[] list[i];
    }
    delete[] list;
    size = 0;


    size_t partStart = 0;
    bool inPart = false;

    for (size_t i = 0; i < strlen(str); ++i) {
        if (str[i] == delimiter) {
            if (inPart) {
                inPart = false;
                const size_t n = i - partStart;
                char* tmp = nullptr;
                nCopy(tmp, str + partStart, n);
                addToList(tmp, list, size);

                delete[] tmp;
            }
        }
        else if (!inPart) {
            inPart = true;
            partStart = i; 
        }
    }

    if (inPart) {
        inPart = false;
        char* tmp = nullptr;
        const size_t n = strlen(str) - partStart;
        nCopy(tmp, str + partStart, n);
        addToList(tmp, list, size);

        delete[] tmp;
    }
}

void join(char* &str, char** list, const size_t size, char delimiter = ' ') {
    if (size == 0) {
        return;
    }

    strcpy(str, list[0]);

    for (size_t i = 1; i < size; ++i) {
        char d[2];
        d[0] = delimiter;
        d[1] = STREND;
        strcat(str, d);
        strcat(str, list[i]);
    }
}

#endif // __STRING_EXTENTION_