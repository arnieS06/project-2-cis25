#pragma once

#include <string>
#include <vector>

struct GameState {
	std::vector<std::string> listOfWords;
	std::string targetWord;
	int remainingAttempts = 0;
	std::vector<std::string> guesses;
};

enum Feedback { Correct, Misplacyed, Incorrect };

struct WordUtils {

};
