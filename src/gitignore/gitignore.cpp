#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include "../util/util.h"

using namespace std;

bool special_useless_line(string line)
{
  return line.rfind("#", 0) == 0 || line.empty();
}

vector<string> read_dir(string path)
{
  vector<string> files;

  for (const auto &entry : filesystem::directory_iterator(path))
  {
    files.push_back(entry.path().string());
  }

  return files;
}

vector<string> read_lines(string path)
{
  vector<string> lines;
  string line;

  ifstream file(path);

  while (getline(file, line))
  {
    lines.push_back(line);
  }

  file.close();

  return lines;
}

vector<string> add_useless_lines(vector<string> lines, bool nokeep)
{
  vector<string> uselessLines;

  for (string line : lines)
  {
    if (!filesystem::exists(line))
    {
      if (nokeep)
      {
        uselessLines.push_back(line);
      }
      else
      {
        if (!special_useless_line(line))
        {
          uselessLines.push_back(line);
        }
      }

      continue;
    }
  }

  return uselessLines;
}

vector<string> add_clean_lines(vector<string> lines, vector<string> uselessLines)
{

  for (string line : uselessLines)
  {
    int index = find(lines, line);

    if (index == -1)
    {
      continue;
    }

    lines.erase(lines.begin() + index);
  }

  if (lines.size() > 0 && lines[0].size() == 0)
  {
    lines.erase(lines.begin());
  }

  return lines;
}
