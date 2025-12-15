#include <iostream>

bool isDigit(char c)
{
  return c >= '0' && c <= '9';
}

char *readLineDynamic()
{
  size_t cap = 64;
  size_t len = 0;

  char *buf = new char[cap];

  char ch;
  while (std::cin.get(ch))
  {
    if (ch == '\n')
    {
      break;
    }

    if (len + 1 >= cap)
    {
      size_t newCap = cap * 2;

      char *nb = new char[newCap];

      for (size_t i = 0; i < len; ++i)
      {
        nb[i] = buf[i];
      }

      delete[] buf;

      buf = nb;
      cap = newCap;
    }

    buf[len++] = ch;
  }

  buf[len] = '\0';

  return buf;
}

size_t computeExpandedLength(const char *in)
{
  size_t outLen = 0;

  for (size_t i = 0; in[i] != '\0';)
  {
    if (in[i] != '[')
    {
      ++outLen;
      ++i;

      continue;
    }

    ++i;

    size_t num = 0;
    while (isDigit(in[i]))
    {
      num = num * 10 + (in[i] - '0');
      ++i;
    }

    size_t lettersStart = i;
    while (in[i] != '\0' && in[i] != ']')
      ++i;

    size_t lettersLen = i - lettersStart;

    if (in[i] == ']')
      ++i;

    outLen += num * lettersLen;
  }

  return outLen;
}

static char *expand(const char *in)
{
  size_t outLen = computeExpandedLength(in);
  char *out = new char[outLen + 1];

  size_t w = 0;

  for (size_t i = 0; in[i] != '\0';)
  {
    if (in[i] != '[')
    {
      out[w++] = in[i++];
      continue;
    }

    ++i;

    size_t num = 0;
    while (isDigit(in[i]))
    {
      num = num * 10 + (in[i] - '0');
      ++i;
    }

    size_t lettersStart = i;

    while (in[i] != '\0' && in[i] != ']')
    {
      ++i;
    }

    size_t lettersLen = i - lettersStart;

    if (in[i] == ']')
    {
      ++i;
    }

    for (size_t rep = 0; rep < num; ++rep)
    {
      for (size_t k = 0; k < lettersLen; ++k)
      {
        out[w++] = in[lettersStart + k];
      }
    }
  }

  out[w] = '\0';

  return out;
}

int main()
{
  char *input = readLineDynamic();
  char *result = expand(input);

  std::cout << result << std::endl;

  delete[] result;
  delete[] input;

  return 0;
}
