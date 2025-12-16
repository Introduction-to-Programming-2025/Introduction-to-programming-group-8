#include <iostream>
#include <cstring>

char *copyWord(const char *start, size_t len)
{
  char *w = new char[len + 1];
  for (size_t i = 0; i < len; ++i)
  {
    w[i] = start[i];
  }

  w[len] = '\0';

  return w;
}

void splitWords(const char *text, char ***outWords, size_t **outLens, size_t *outCount)
{
  size_t cap = 16;
  size_t cnt = 0;

  char **words = new char *[cap];
  size_t *lens = new size_t[cap];

  size_t i = 0;
  while (text[i] != '\0')
  {
    while (text[i] == ' ')
    {
      ++i;
    }

    if (text[i] == '\0')
      break;

    size_t start = i;
    while (text[i] != '\0' && text[i] != ' ')
    {
      ++i;
    }

    size_t len = i - start;

    if (cnt == cap)
    {
      size_t newCap = cap * 2;

      char **nw = new char *[newCap];
      size_t *nl = new size_t[newCap];

      for (size_t k = 0; k < cnt; ++k)
      {
        nw[k] = words[k];
        nl[k] = lens[k];
      }

      delete[] words;
      delete[] lens;

      words = nw;
      lens = nl;
      cap = newCap;
    }

    words[cnt] = copyWord(text + start, len);
    lens[cnt] = len;
    ++cnt;
  }

  *outWords = words;
  *outLens = lens;
  *outCount = cnt;
}

void freeWords(char **words, size_t *lens, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete[] words[i];
  }

  delete[] words;
  delete[] lens;
}

size_t computeWordsLen(size_t *lens, size_t from, size_t to)
{
  size_t sum = 0;

  for (size_t i = from; i < to; ++i)
  {
    sum += lens[i];
  }

  return sum;
}

char *buildLine(char **words, size_t *lens,
                size_t from, size_t to,
                size_t maxWidth, bool isLastLine)
{
  size_t numWords = to - from;
  size_t wordsLen = computeWordsLen(lens, from, to);

  char *line = new char[maxWidth + 1];
  size_t w = 0;

  if (numWords == 1 || isLastLine)
  {
    for (size_t i = from; i < to; ++i)
    {
      for (size_t k = 0; k < lens[i]; ++k)
      {
        line[w++] = words[i][k];
      }

      if (i + 1 < to)
      {
        line[w++] = ' ';
      }
    }
    while (w < maxWidth)
    {
      line[w++] = ' ';
    }
  }
  else
  {
    size_t totalSpaces = maxWidth - wordsLen;
    size_t gaps = numWords - 1;
    size_t base = totalSpaces / gaps;
    size_t extra = totalSpaces % gaps;

    for (size_t i = from; i < to; ++i)
    {
      for (size_t k = 0; k < lens[i]; ++k)
      {
        line[w++] = words[i][k];
      }

      if (i + 1 < to)
      {
        size_t gapIndex = i - from;
        size_t spacesHere = base + (gapIndex < extra ? 1 : 0);

        for (size_t s = 0; s < spacesHere; ++s)
        {
          line[w++] = ' ';
        }
      }
    }
  }

  line[maxWidth] = '\0';

  return line;
}

void justifyText(const char *text, size_t maxWidth, char ***outLines, size_t *outLineCount)
{
  char **words = 0;
  size_t *lens = 0;
  size_t wordCount = 0;

  splitWords(text, &words, &lens, &wordCount);

  size_t cap = (wordCount == 0 ? 1 : wordCount);
  char **lines = new char *[cap];
  size_t lineCnt = 0;

  size_t i = 0;
  while (i < wordCount)
  {
    size_t j = i;
    size_t sumLen = 0;

    while (j < wordCount)
    {
      size_t newSum = sumLen + lens[j];
      size_t newNumWords = (j - i + 1);
      size_t minSpaces = (newNumWords > 0 ? (newNumWords - 1) : 0);

      if (newSum + minSpaces > maxWidth)
      {
        break;
      }

      sumLen = newSum;
      ++j;
    }

    bool isLastLine = (j == wordCount);
    lines[lineCnt++] = buildLine(words, lens, i, j, maxWidth, isLastLine);
    i = j;
  }

  freeWords(words, lens, wordCount);

  *outLines = lines;
  *outLineCount = lineCnt;
}

void freeLines(char **lines, size_t lineCount)
{
  for (size_t i = 0; i < lineCount; ++i)
  {
    delete[] lines[i];
  }

  delete[] lines;
}

int main()
{
  const char *text = "Това е пример за подравняване на текст";
  size_t maxWidth = 20;

  char **lines = 0;
  size_t lineCount = 0;

  justifyText(text, maxWidth, &lines, &lineCount);

  std::cout << "[" << std::endl;

  for (size_t i = 0; i < lineCount; ++i)
  {
    std::cout << "  \"";
    for (size_t k = 0; k < maxWidth; ++k)
    {
      std::cout << lines[i][k];
    }

    std::cout << "\"" << std::endl;
  }

  std::cout << "]" << std::endl;

  freeLines(lines, lineCount);

  return 0;
}
