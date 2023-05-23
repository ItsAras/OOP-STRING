#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <fcntl.h>  
#include <io.h> 
#include <vector>
#include <regex>

using std::string;
using std::map;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::remove_if;
using std::wcout;
using std::wstring;
using std::wostream;
using std::pair;
using std::vector;
using std::getline;
using std::regex;
using std::smatch;

void readFile(map<string, int> &);
void outputWords(map<string, int> &);
void outputTable(map<string, int> &words);
void findLinks();