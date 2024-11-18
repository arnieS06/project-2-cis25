#include <iostream>
#include <vector>
#include <string>
#include <fstream>  
#include <ctime>
#include <cstdlib>
#include <cctype>
#include "Structs.h" 
using namespace std;

void greetUser() {
    cout << "Welcome to wordle, let's see how well you can guess" << endl;
    cout << "Choose your difficulty --> Easy, (6 guesses) \nMedium, (4 guesses) \nImpossible (2 guesses)" << endl;
    //pending
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
    vector<char> feedback(guess.size(), '-'); 
    
    for (size_t i = 0; i < guess.size(); ++i) {
        if (guess[i] == targetWord[i]) {
            feedback[i] = 'C'; 
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

void playWorlde(GameState& game) {
    int maxAttempts = 6;
    game.remainingAttempts = maxAttempts;
    string guess;

    // add difficulty systemm here

    cout << "You have " << maxAttempts << " attempts to guess the word." << endl;

    while (game.remainingAttempts > 0) {
        cout << "\nEnter your guess (5-letter word): ";
        cin >> guess;

        for (auto& c : guess) {
            c = tolower(c);
        }

        if (guess.size() != 5) {
            cout << "Invalid guess. Please enter a 5-letter word." << endl;
            continue;
        }

        if (find(game.listOfWords.begin(), game.listOfWords.end(), guess) == game.listOfWords.end()) {
            cout << "Word not in the list. Try again." << endl;
            continue;
        }

        game.guesses.push_back(guess);

        vector<char> feedback = provideFeedback(game.targetWord, guess);

        cout << "Feedback: ";
        for (char f : feedback) {
            cout << f << " ";
        }
        cout << endl;

        if (guess == game.targetWord) {
            cout << "Congratulations! You guessed the word. I didn't think you could do it. \nYour answer: " << game.targetWord << endl;
            return;
        }

        --game.remainingAttempts;
        cout << "Remaining attempts: " << game.remainingAttempts << endl;

    }

    cout << "Out of attempts! The word was: " << game.targetWord << endl;

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

   playWorlde(game);

   return 0;
}
