#include <iostream>
#include "../include/CLI11.hpp"
#include "util/util.h"
#include "gitignore/gitignore.h"

using namespace std;

const float ALLYIGNORE_VERSION = 0.1;

int start(bool nokeep)
{
  vector<string> files = read_dir(".");

  int gitignore_index = find(files, "./.gitignore");

  if (gitignore_index == -1)
  {
    cout << "No .gitignore file found." << endl;
    return 1;
  }

  string gitignore_file = files[gitignore_index];

  vector<string> lines = read_lines(gitignore_file);
  vector<string> useless_lines = add_useless_lines(lines, nokeep);

  lines = add_clean_lines(lines, useless_lines);

  if (useless_lines.size() == 0)
  {
    cout << "No useless lines found." << endl;
    return 0;
  }

  ofstream file;

  file.open(gitignore_file);

  for (string line : lines)
  {
    file << line << endl;
  }

  file.close();

  cout << "Deleted these files from .gitignore:" << endl;

  for (string line : useless_lines)
  {
    cout << line << endl;
  }

  return 0;
}

int main(int argc, char **argv)
{
  CLI::App app{"Allyignore rewritten in C++"};

  bool nokeep = false;

  app.add_flag("--nokeep", nokeep, "Run Allyignore but don't keep comments and empty lines.");
  app.set_version_flag("--version", to_string(ALLYIGNORE_VERSION));

  CLI11_PARSE(app, argc, argv);

  start(nokeep);
}