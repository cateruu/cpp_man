#include "WordList.h"
#include "Session.h"

#include <iostream>
#include <vector>

char getInput(const Session& s) {
	while (true) {
		std::cout << "Enter your next letter: ";
		char input{};
		std::cin >> input;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (input < 'a' || input > 'z') {
			std::cout << "That wasn't a valid input. Try again.\n";
			continue;
		}

		if (s.isLetterGuessed(input)) {
			std::cout << "You already guessed that. Try again.\n";
			continue;
		}

		return input;
	}
}

std::string_view getCorrectWordForm(const Session& s) {
	if (s.getLives() == 1) {
		return "try";
	}
	else {
		return "tries";
	}
}

int main() {
	std::cout << "Welcome to C++man (a variant of Hangman)\n";
	std::cout << "To win: guess the word.\t To lose: ron out of plusses.\n";
	std::cout << '\n';

	Session session{ WordList::pickRandomWord() };

	bool gameWon{ false };
	while (session.getLives()) {
		session.displayState();
		char input{ getInput(session) };
		session.addGuessedCharacter(input);

		if (!session.isCorrectLetter(input)) {
			session.reduceLives();
			session.addWrongGuesses(input);
		}

		std::cout << "You entered: " << input << '\n';
		std::cout << '\n';

		if (session.isGameWon()) {
			gameWon = true;
			break;
		}
	}

	session.displayState();
	std::cout << "\n";

	if (gameWon) {
		std::cout << "Congratulations! You win with " << session.getLives() << ' ' << getCorrectWordForm(session) << " left!\n";
	}
	else {
		std::cout << "Damn. That's tough. You got killed :(\n";
	}

	return 0;
}