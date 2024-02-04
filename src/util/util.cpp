#include "util.h"
#include <string>
#include <vector>

using namespace std;

int find(vector<string> array, string value)
{
  for (int i = 0; i <= array.size(); i++)
  {
    if (array[i] == value)
    {
      return i;
    }
  }

  return -1;
}