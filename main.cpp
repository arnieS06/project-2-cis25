#include <iostream>
#include <vector>
#include <string>
#include <fstream>  
#include <ctime>
#include <cstdlib>
#include "Structs.h" 
using namespace std;

void greetUser() {
    cout << "Welcome to wordle, let's see how well you can guess" << endl;
    cout << "Choose your difficulty --> Easy, (6 guesses) \nMedium, (4 guesses) \nImpossible (2 guesses)";

}

void loadWords(const string& filename, GameState& game) {
   ifstream file(filename); 

   if (!file.is_open()) {
       cerr << "Error: Could not open file '" << filename << "'. \nPlease try again." << endl;
       return;
   }

   string word;
   while (file >> word) { 
       game.listOfWords.push_back(word);
   }

   file.close(); 
}

vector<char> provideFeedback(const string& targetWord, const string& guess) {
    vector<char> feedback(guess.size(), '-'); // Initialize feedback with '-'

    // Check for correct letters in correct positions
    for (size_t i = 0; i < guess.size(); ++i) {
        if (guess[i] == targetWord[i]) {
            feedback[i] = 'C'; // 'C' for Correct
        }
    }

    for (size_t i = 0; i < guess.size(); ++i) {
        if (feedback[i] == 'C') continue; 
        if (targetWord.find(guess[i]) != string::npos) {
            feedback[i] = 'M'; // 
        }
    }

    return feedback;
}

int main() {
   srand(static_cast<unsigned>(time(0))); 

   GameState game;

   loadWords("wordlist.txt", game);
 
   if (game.listOfWords.empty()) {
       cerr << "Words failed to load, please re-compile the program" << endl;
       return 1;
   }

    
   game.targetWord = game.listOfWords[rand() % game.listOfWords.size()];

    // Display the chosen word (for debugging; remove later)
   cout << "Target Word: " << game.targetWord << endl;

   greetUser();

   return 0;
}
