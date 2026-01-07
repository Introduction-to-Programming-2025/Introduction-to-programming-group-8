#include <iostream>
#include <cstring>

const size_t STRLEN = 1024;

int transform() {
    return 'A' - 'a';
}

bool isUpper(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

bool isLower(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

bool isAlpha(char symbol) {
    return isLower(symbol) || isUpper(symbol);
}

bool isWhitespace(char symbol) {
    return symbol == ' ' || symbol == '\n';
}

bool isPunctuation(char symbol) {
    return !isAlpha(symbol) && !isWhitespace(symbol);
}

void toLower(char &symbol) {
    if (!isUpper(symbol)) {
        return;
    }

    symbol -= transform();
}

void toUpper(char &symbol) {
    if (!isLower(symbol)) {
        return;
    }

    symbol += transform();
} 

void textToLower(char text[]) {
    for (size_t i = 0; i < strlen(text); ++i) {
        toLower(text[i]);
    }
}

void remove(char text[], size_t index) {
    char tmp[STRLEN] = "";
    strcpy(tmp, text + index + 1);
    text[index] = '\0';
    strcat(text, tmp);
}

void insert(char text[], size_t index, char symbol) {
    char tmp[STRLEN] = "";
    strcpy(tmp, text + index);
    text[index] = symbol;
    text[index + 1] = '\0';
    strcat(text, tmp);
}

void trim(char text[]) {
    size_t i = 0;
    while(isWhitespace(text[0])) {
        remove(text, 0);
    }

    while(i < strlen(text)) {
        while (isWhitespace(text[i]) && isWhitespace(text[i + 1])) {
            if (text[i] == text[i + 1] || text[i] == ' ') {
                remove(text, i);
            } else {
                remove(text, i + 1);
            }
        }
        if (isWhitespace(text[i]) && isPunctuation(text[i + 1])) {
            remove(text, i);
        }
        if (isPunctuation(text[i]) && !isWhitespace(text[i + 1])) {
            insert(text, i + 1, ' ');
        }

        ++i;
    }

    i = strlen(text) - 1;
    if (isWhitespace(text[i])) {
        remove(text, i);
    }
}

void deleteChunks(char** &chunks, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        delete[] chunks[i];
    }

    delete[] chunks;
}

void resize(char** &chunks, size_t &size) {
    char** temp = new char*[size + 1];

    for (size_t i = 0; i < size; ++i) {
        temp[i] = new char[strlen(chunks[i]) + 1];
        temp[i][0] = '\0';
        strcpy(temp[i], chunks[i]);
    }

    deleteChunks(chunks, size);
    chunks = temp;
    ++size;
}

bool contains(char delimiters[], char symbol) {
    for (size_t i = 0; i < strlen(delimiters); ++i) {
        if (delimiters[i] == symbol) {
            return true;
        }
    }

    return false;
}

void toChunks(char array[], char** &chunks, size_t &size, char delimiters[]) {
    size = 0;

    bool inChunk = false;
    size_t chunkStart = 0, l = strlen(array);

    for (size_t i = 0; i < l; ++i) {
        if (contains(delimiters, array[i])) {
            if (inChunk) {
                inChunk = false;

                resize(chunks, size);

                size_t iSize = i - chunkStart + 1;
                chunks[size - 1] = new char[iSize + 1];
                for (size_t j = 0; j < iSize; ++j) {
                    chunks[size - 1][j] = array[chunkStart + j];
                }
                chunks[size - 1][iSize] = '\0';
            }
        }
        else {
            if (!inChunk) {
                inChunk = true;
                chunkStart = i;
            }
        }
    }

    if (inChunk) {
        inChunk = false;

        resize(chunks, size);

        size_t iSize = strlen(array) - chunkStart + 1;
        chunks[size - 1] = new char[iSize + 1];
        for (size_t j = 0; j < iSize; ++j) {
            chunks[size - 1][j] = array[chunkStart + j];
        }
        chunks[size - 1][iSize] = '\0';
    }
}

void sentenceCase(char text[]) {
    char** paragraphs = nullptr;
    size_t pSize = 0;

    toChunks(text, paragraphs, pSize, "\n");

    text[0] = '\0';

    for (size_t i = 0; i < pSize; ++i) {
        char** sentences = nullptr;
        size_t sSize = 0;

        toChunks(paragraphs[i], sentences, sSize, ".!?");

        char tmp[STRLEN] = ""; 

        for (size_t j = 0; j < sSize; ++j) {
            size_t k = 0;
            while (isWhitespace(sentences[j][k]) && k < strlen(sentences[j])) {
                ++k;
            }

            toUpper(sentences[j][k]);
            strcat(tmp, sentences[j]);
        }

        strcat(text, tmp);

        deleteChunks(sentences, sSize);
    }

    deleteChunks(paragraphs, pSize);
}

int main() {
    // char example[STRLEN] = "testtest";
    // remove(example, 4);
    // std::cout << example << std::endl;

    const char DELIMITER = '~';

    char text[STRLEN];
    std::cin.getline(text, STRLEN, DELIMITER);

    textToLower(text);
    trim(text);

    sentenceCase(text);

    std::cout << text << '`' << std::endl;

    return 0;
}

/*
  CheSS gAme

ChESS iS oNE of the OLDEST thoughT GAMES and among THE FIRST displays OF THE uSe oF MatheMATicS FOR enTERtainmENT . due to THE algorithmic NATURE of the gAmE ,itS proPer DEVelopMent REQuiRes ESSENTIAL SKILLs iN PrograMMing , strucTURING ALGORIthmS ,goOd CoMpUtEr MeMorY mAnAgEmEnT anD MaNY otHeR skIlLs tHaT aRe EssEnTiAl fOr a GooD prograMMer .

The GOAL of this projeCT is    ~
*/