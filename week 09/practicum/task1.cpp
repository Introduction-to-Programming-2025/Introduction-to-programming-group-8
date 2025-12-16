#include <iostream>
#include <cstring>

bool readRows(int &R)
{
  std::cout << "Enter number of rows: ";
  if (!(std::cin >> R) || R <= 0)
  {
    std::cout << "Invalid number of rows." << std::endl;
    return false;
  }
  return true;
}

bool initHall(int R, size_t *&seatsCount, char **&hall)
{
  seatsCount = new size_t[R];
  hall = new char *[R];

  for (size_t i = 0; i < R; ++i)
  {
    std::cout << "Enter seats for row " << (i + 1) << ": ";
    int s;
    if (!(std::cin >> s) || s <= 0)
    {
      std::cout << "Invalid seat count." << std::endl;

      for (size_t k = 0; k < i; ++k)
      {
        delete[] hall[k];
      }
      delete[] hall;
      delete[] seatsCount;

      seatsCount = 0;
      hall = 0;
      return false;
    }

    seatsCount[i] = s;
    hall[i] = new char[s];
    for (size_t j = 0; j < s; ++j)
    {
      hall[i][j] = '.';
    }
  }

  return true;
}

void printHall(int R, size_t *seatsCount, char **hall)
{
  for (size_t i = 0; i < R; ++i)
  {
    for (size_t j = 0; j < seatsCount[i]; ++j)
    {
      std::cout << hall[i][j];
    }
    std::cout << std::endl;
  }
}

void handleReserve(int R, size_t *seatsCount, char **hall)
{
  int row, seat;
  if (!(std::cin >> row >> seat))
  {
    std::cout << "Invalid input for reserve." << std::endl;
    return;
  }

  size_t r = row - 1;
  size_t s = seat - 1;

  if (r >= R)
  {
    std::cout << "Invalid row." << std::endl;
    return;
  }
  if (s >= seatsCount[r])
  {
    std::cout << "Invalid seat." << std::endl;
    return;
  }
  if (hall[r][s] == 'X')
  {
    std::cout << "Seat already reserved." << std::endl;
    return;
  }

  hall[r][s] = 'X';
  std::cout << "Reserved row " << row << ", seat " << seat << "." << std::endl;
}

void handleFree(int R, size_t *seatsCount, char **hall)
{
  int row, seat;
  if (!(std::cin >> row >> seat))
  {
    std::cout << "Invalid input for free." << std::endl;
    return;
  }

  size_t r = row - 1;
  size_t s = seat - 1;

  if (r >= R)
  {
    std::cout << "Invalid row." << std::endl;
    return;
  }
  if (s >= seatsCount[r])
  {
    std::cout << "Invalid seat." << std::endl;
    return;
  }
  if (hall[r][s] == '.')
  {
    std::cout << "Seat is already free." << std::endl;
    return;
  }

  hall[r][s] = '.';
  std::cout << "Freed row " << row << ", seat " << seat << "." << std::endl;
}

void cleanupHall(int R, size_t *&seatsCount, char **&hall)
{
  if (hall)
  {
    for (size_t i = 0; i < R; ++i)
    {
      delete[] hall[i];
    }
    delete[] hall;
    hall = 0;
  }

  delete[] seatsCount;
  seatsCount = 0;
}

int main()
{
  int R;
  if (!readRows(R))
    return 0;

  size_t *seatsCount = 0;
  char **hall = 0;

  if (!initHall(R, seatsCount, hall))
    return 0;

  char cmd[32];

  while (true)
  {
    std::cin >> cmd;

    if (std::strcmp(cmd, "q") == 0)
    {
      break;
    }
    else if (std::strcmp(cmd, "print") == 0)
    {
      printHall(R, seatsCount, hall);
    }
    else if (std::strcmp(cmd, "reserve") == 0)
    {
      handleReserve(R, seatsCount, hall);
    }
    else if (std::strcmp(cmd, "free") == 0)
    {
      handleFree(R, seatsCount, hall);
    }
    else
    {
      std::cout << "Unknown command. Use: reserve/free/print/q" << std::endl;
    }
  }

  cleanupHall(R, seatsCount, hall);

  return 0;
}
