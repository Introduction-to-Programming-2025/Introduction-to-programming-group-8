#include <iostream>
#include <cstring> // За C функции за работа с низове (strlen, strcat)

// Максимални ограничения според условията
#define MAX_WORD_LEN 128
#define MAX_WORDS 1024
// Максимална дължина на резултатното изречение (128 * 1024)
#define MAX_RESULT_LEN (MAX_WORD_LEN * MAX_WORDS)

/**
 * Приема списък от думи и връща изречението, получено от конкатенирането
 * на всички думи, започвайки отзад напред. Думите се разделят с интервал.
 */
char* concatenate_reverse(char** word_list, int size) {
    // nullptr
    // use MAX_WORDS
    if (word_list == NULL || size <= 2 || size >= 1024) { 
        std::cerr << "Невалиден брой думи (" << size << ") или невалиден списък." << std::endl;
        return NULL;
    }

    // 1. Изчисляване на необходимия размер за памет
    int total_length = 0;
    for (int i = 0; i < size; ++i) {
        if (word_list[i] != NULL) {
            total_length += std::strlen(word_list[i]);
        }
    }
   
    // Добавяне на място за (size - 1) интервала и завършващата нула ('\0')
    total_length += (size - 1) + 1;

    if (total_length > MAX_RESULT_LEN) {
        std::cerr << "Резултатното изречение е твърде дълго." << std::endl;
        return NULL;
    }

    // 2. Заделяне на памет за резултатното изречение
    char* result_sentence = new char[total_length];
    if (result_sentence == NULL) {
        std::cerr << "Грешка при заделяне на памет за резултатното изречение." << std::endl;
        return NULL;
    }
   
    // Инициализиране на резултата като празен низ
    result_sentence[0] = '\0';

    // 3. Конкатенация в обратен ред
    for (int i = size - 1; i >= 0; --i) {
        if (word_list[i] != NULL) {
            // Добавяне на думата
            std::strcat(result_sentence, word_list[i]);
           
            // Добавяне на интервал, освен ако това не е първата дума, която се конкатенира (последната в оригиналния масив)
            if (i > 0) {
                std::strcat(result_sentence, " ");
            }
        }
    }

    return result_sentence;
}

int main() {
    // Създаване на примерен списък от думи 
    // Трябва да са между 3 и 1023 думи.
    const int demo_size;
    std::cin >> demo_size;
    char* demo_words[demo_size];
   
    for (int i = 0; i < demo_size; i += 1) {
        std::cin >> demo_words[i];
    }

    // Извикване на функцията
    char* reversed_sentence = concatenate_reverse(demo_words, demo_size);

    if (reversed_sentence != NULL) {
        std::cout << reversed_sentence << std::endl;

    // Освобождаване на паметта, заделена за примерните думи
    for (int i = 0; i < demo_size; i++) {
        std::free(demo_words[i]);
    }
    // delete[] demo_words

    return 0;
}