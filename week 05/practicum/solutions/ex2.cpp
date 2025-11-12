#include <iostream>

int main() {
    const size_t MAX_SIZE = 1024;

    char text[MAX_SIZE + 1];
    char command;
    bool isTextLoaded = false;

    while (true) {
        std::cin >> command;

        if (command == '.') {
            size_t i = 0;

            while (i < MAX_SIZE && std::cin >> text[i]) {
                if (text[i] == '\n') {
                    break;
                }
                ++i;
            }

            text[i] = '\0';
            isTextLoaded = true;
        } 
        else if (command == '#') {
            if (isTextLoaded) {
                int wordCount = 0;
                bool inWord = false;

                for (size_t i = 0; text[i] != '\0'; ++i) {
                    if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
                        if (!inWord) {
                            wordCount++;
                            inWord = true;
                        }
                    } else {
                        inWord = false;
                    }
                }

                std::cout << wordCount << std::endl;
            }
        } 
        else if (command == '-') {
            if (isTextLoaded) {
                size_t i = 0, j = 0;
                bool inSpace = false;

                while (text[i] != '\0') {
                    if (text[i] == ' ') {
                        if (!inSpace) {
                            text[j] = ' ';
                            inSpace = true;
                            ++j;
                        }
                    } else {
                        text[j] = text[i];
                        inSpace = false;
                        ++j;
                    }
                    ++i;
                }

                text[j] = '\0';
            }
        } 
        else if (command == '+') {
            if (isTextLoaded) {
                std::cout << text << std::endl;
            }
        } 
        else if (command == 'q') {
            break;
        }
    }

    return 0;
}
