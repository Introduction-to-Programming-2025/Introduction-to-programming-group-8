#include <iostream>

size_t wordLength(const char *w)
{
    int len = 0;
    while (w[len] != '\0')
    {
        ++len;
    }
    return len;
}

bool areEqual(const char *a, const char *b)
{
    size_t i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
        {
            return false;
        }
        ++i;
    }
    return a[i] == '\0' && b[i] == '\0';
}

int lexCompare(const char *a, const char *b)
{
    size_t i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] < b[i])
            return -1;
        if (a[i] > b[i])
            return 1;
        ++i;
    }
    if (a[i] == '\0' && b[i] == '\0')
        return 0;
    if (a[i] == '\0')
        return -1;
    return 1;
}

int main()
{
    size_t n;
    std::cout << "Enter length of sentence: ";
    std::cin >> n;

    char *sentence = new char[n + 1];

    std::cout << "Enter sentence: ";
    std::cin.getline(sentence, n + 1);

    size_t maxWords = n / 2 + 1;
    char **words = new char *[maxWords];
    size_t wordCount = 0;

    size_t i = 0;
    while (sentence[i] != '\0')
    {
        while (sentence[i] == ' ')
        {
            ++i;
        }

        if (sentence[i] == '\0')
        {
            break;
        }

        char *start = &sentence[i];

        while (sentence[i] != ' ' && sentence[i] != '\0')
        {
            ++i;
        }

        if (sentence[i] == ' ')
        {
            sentence[i] = '\0';
            ++i;
        }

        words[wordCount++] = start;
    }

    char **uniqueWords = new char *[wordCount];
    size_t uniqueCount = 0;

    for (size_t k = 0; k < wordCount; ++k)
    {
        bool isDuplicate = false;
        for (size_t j = 0; j < uniqueCount; ++j)
        {
            if (areEqual(words[k], uniqueWords[j]))
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            uniqueWords[uniqueCount++] = words[k];
        }
    }

    if (uniqueCount > 1)
    {
        for (size_t a = 0; a < uniqueCount - 1; ++a)
        {
            size_t minIndex = a;
            for (size_t b = a + 1; b < uniqueCount; ++b)
            {
                size_t lenB = wordLength(uniqueWords[b]);
                size_t lenMin = wordLength(uniqueWords[minIndex]);

                if (lenB < lenMin ||
                    (lenB == lenMin && lexCompare(uniqueWords[b], uniqueWords[minIndex]) < 0))
                {
                    minIndex = b;
                }
            }
            if (minIndex != a)
            {
                char *tmp = uniqueWords[a];
                uniqueWords[a] = uniqueWords[minIndex];
                uniqueWords[minIndex] = tmp;
            }
        }
    }

    std::cout << "Words sorted by length (unique): ";
    for (size_t k = 0; k < uniqueCount; ++k)
    {
        std::cout << uniqueWords[k];
        if (k + 1 < uniqueCount)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    delete[] sentence;
    delete[] words;
    delete[] uniqueWords;

    return 0;
}
