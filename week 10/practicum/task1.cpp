#include <iostream>
#include <cstring>

char *normalizeSpaces(const char *in)
{
  if (!in)
  {
    char *out = new char[1];
    out[0] = '\0';
    return out;
  }

  size_t n = std::strlen(in);
  char *out = new char[n + 1];

  size_t i = 0;
  while (in[i] == ' ')
  {
    ++i;
  }

  size_t w = 0;
  bool wroteSomething = false;
  bool lastWasSpace = false;

  for (; in[i] != '\0'; ++i)
  {
    if (in[i] == ' ')
    {
      if (wroteSomething && !lastWasSpace)
      {
        out[w++] = ' ';
        lastWasSpace = true;
      }
    }
    else
    {
      out[w++] = in[i];
      wroteSomething = true;
      lastWasSpace = false;
    }
  }

  if (w > 0 && out[w - 1] == ' ')
  {
    --w;
  }

  out[w] = '\0';

  return out;
}

int main()
{
  const char *s = "   Това   е   тест   текст.   ";

  const char *result = normalizeSpaces(s);

  std::cout << result << std::endl;

  delete[] result;

  return 0;
}
