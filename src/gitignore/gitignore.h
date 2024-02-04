#pragma once
#include <vector>
#include <string>
#include <filesystem>

using namespace std;

vector<string> read_dir(string path);

vector<string> read_lines(string path);

vector<string> add_useless_lines(vector<string> lines, bool nokeep);

vector<string> add_clean_lines(vector<string> lines, vector<string> useless_lines);