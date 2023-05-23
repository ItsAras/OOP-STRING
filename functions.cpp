#include "header.h"

void readFile(map<string, int> &words)
{   
    string fileName;
    string outputFile = "words.txt";
    string word;
    string line;
    string separator{" \t\r\n,.!?;:1234567890[](){}/|-~_°`"};

    cout << "Name of file to read from: ";
    cin >> fileName;

    ifstream file;
    ofstream output;
    file.open(fileName);
    output.open(outputFile);
 
    while(getline (file, line)){  // read line by line 
        size_t e,s=0;            // s = offset of next word, e = end of next word 
        do {
            s = line.find_first_not_of(separator,s);  // skip leading separators
            if (s==string::npos)                  // stop if no word left
                break;
            e=line.find_first_of(separator, s);   // find next separator 
            string word(line.substr(s,e-s));
            if (word.length() > 1)
            {
                if (words.find(word) == words.end())
                {
                    words.insert(pair<string, int>(word, 0));
                } else {
                    words[word]++;
                }
            }  // construct the word
            s=e+1;                                // position after the separator
        } while (e!=string::npos);                // loop if end of line not reached
    }

    file.close();
}

void outputWords(map<string, int> &words)
{
    ofstream fr("words.txt");

    for (auto &it : words)
    {
        if (it.second > 0) fr << it.first << " (" << ++it.second << ")" << endl;
    }

    fr.close();

    cout << "All words can be found in words.txt file." << endl;
}

vector<int> findWordPositions(string word)
{
    ifstream fd("text.txt");
    std::string line;
    std::vector<int> lines;
    int lineNumber = 1;

    while (getline(fd, line))
    {
        if (line.find(word) != std::string::npos)
        {
            lines.push_back(lineNumber);
        }
        lineNumber++;
    }

    fd.close();
    return lines;
}

void outputTable(map<string, int> &words)
{
    ofstream fr("table.txt");

    for (auto &it : words)
    {
        if (it.second > 0)
        {
            vector<int> positions = findWordPositions(it.first);
            fr << it.first << " ";
            for (size_t i = 0; i < positions.size(); i++) fr << "[" << positions[i] << "]";
            fr << endl;
        }
    }

    cout << "Cross-reference table can be found in table.txt file." << endl;
}

void findLinks()
{
    ifstream fd("text.txt");
    ofstream fr("links.txt");
    string text;

    text.assign((std::istreambuf_iterator<char>(fd)), std::istreambuf_iterator<char>());
    regex linkRegex(R"((https?):\/\/[^\s/$.?#].[^\s]*)");
    smatch match;
    vector<string> links;

    std::string::const_iterator searchStart(text.cbegin());
    while (std::regex_search(searchStart, text.cend(), match, linkRegex))
    {
        links.push_back(match.str(0));
        searchStart = match.suffix().first;
    }

    for (auto& link : links)
    {
        fr << link << endl;
    }

    cout << "All links can be found in links.txt file." << endl;
}