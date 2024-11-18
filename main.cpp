#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Structs.h"
#include "wordList.h"
using namespace std;

vector<string> loadWords(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string word;

    while (file >> word) {
        words.push_back(word);
    }

    return words;
}


// these are the imports I think I will need for now
int main() {
    GameState game;

    game.listOfWords = loadWords("wordlist.txt");

    for (const auto& word : game.listOfWords) {
        cout << word << endl;
    }
}


