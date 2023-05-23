#include "header.h"

int main()
{
    map<string, int> words;

    readFile(words);

    outputWords(words);

    outputTable(words);

    findLinks();
}
