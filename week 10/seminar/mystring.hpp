#ifndef __MY_STRING__
#define __MY_STRING__

// символ за край на низа
const char STREND = '\0';

// дължина на низ
size_t length(const char* str) {
    size_t l = 0;

    while(str[l] != STREND) {
        ++l;
    }

    return l;
}

// лексикографско сравнение на два низа
// връща индексът на първа разлика + 1 при различни низове; 0 - при равни
// връща отрицателна стойност, ако str1 < str2, положителна при str2 < str1
int compare(const char* str1, const char* str2) {
    size_t l1 = length(str1), l2 = length(str2);
    size_t size = l1 < l2 ? l1 : l2;

    for (size_t i = 0; i < size; ++i) {
        // при намерена първа разлика
        if (str1[i] != str2[i]) {
            size_t index = i + 1;
            return str1[i] < str2[2] ? -1 * index : index;
        }
    }

    // при еднаква дължина
    if (l1 == l2) {
        return 0;
    }

    // при различна дължина
    return l1 < l2 ? -1 * (l1 + 1) : (l2 + 1); 
}

// конкатенация
// резултатът се записва в str1
void concat(char* &str1, const char* str2) {
    size_t l1 = length(str1), l2 = length(str2);
    
    char* temp = new char[l1 + l2 + 1];

    for (size_t i = 0; i < l1; ++i) {
        temp[i] = str1[i];
    }

    for (size_t i = 0; i < l2; ++i) {
        temp[l1 + i] = str2[i];
    }

    // отбелязване на край на низа
    temp[l1 + l2] = STREND;

    delete[] str1;
    str1 = temp;
}

// копиране на низ
void copy(char* &str1, const char* str2) {
    // зануляване на първия низ
    str1[0] = STREND;

    concat(str1, str2);
}

// лексисографско сортиране на редица от низове
void sort(char** &array, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (compare(array[i], array[j]) > 0) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

#endif 