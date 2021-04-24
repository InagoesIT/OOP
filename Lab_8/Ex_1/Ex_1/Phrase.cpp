#include "Phrase.h"

Phrase::Phrase(string filename)
{
    ifstream fileIn;
    fileIn.open(filename, ios::in);
    if (fileIn.is_open())
    {
        getline(fileIn, this->text);
        fileIn.close();
    }
    else
        perror("The file couldn't be opened!");
}

void Phrase::txtSplitToLower()
{
    int i = 0;
    string space = " ";

	while (i < text.size())
	{
        if (text[i] == ' ' && text[++i] == ' ')
        {
            while (text.at(i) == ' ')
                text.erase(text.begin() + i++);
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ',')
            text.erase(text.begin() + i);

        text[i] = tolower(text[i]);
        ++i;
	}
}

void Phrase::count()
{
    int wordEnd = 0;
    string space = " ";
    string word;

    while (((wordEnd = text.find(space)) != string::npos) || (wordEnd = text.size()))
    {       
        word = text.substr(0, wordEnd);
        if (map.end() != map.find(word))
            map[word]++;
        else
            map.insert({ word, 1 });
        text.erase(0, wordEnd + 1);
    }
}

void Phrase::sort()
{
    for (auto itr = map.begin(); itr != map.end(); ++itr) 
    {
        pQueue.push(make_pair(itr->second, itr->first));
    }
}

void Phrase::showWordOcc()
{
    this->txtSplitToLower();
    this->count();
    this->sort();

    while (!pQueue.empty()) 
    {
        cout << pQueue.top().second << "=>" << pQueue.top().first << endl;
        pQueue.pop();
    }
}