#include <iostream>
#include <vector>
#include <string>
#include <fstream>  
#include <ctime>
#include <cstdlib>
#include "Structs.h" 
using namespace std;

void loadWords(const string& filename, GameState& game) {
   ifstream file(filename); 

   if (!file.is_open()) {
       cerr << "Error: Could not open file '" << filename << "'!" << endl;
       return;
   }

   string word;
   while (file >> word) { 
       game.listOfWords.push_back(word);
   }

   file.close(); 
}



int main() {
   srand(static_cast<unsigned>(time(0))); 

   GameState game;

   
   loadWords("wordlist.txt", game);

    
   if (game.listOfWords.empty()) {
       cerr << "No words were loaded. Exiting program." << endl;
       return 1;
   }

    
   game.targetWord = game.listOfWords[rand() % game.listOfWords.size()];

    // Display the chosen word (for debugging; remove later)
   cout << "Target Word: " << game.targetWord << endl;

   return 0;
}
