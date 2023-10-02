#include "Session.h"

#include <iostream>


Session::Session(const std::string& word) : m_word{ word } {}

void Session::displayState() {
	std::cout << "The word: ";
	for ([[maybe_unused]] const auto& i : m_word) {

		bool found{ false };
		for (const auto& c : m_guessedCharacters) {
			if (i == c) {
				found = true;
			}
		}

		if (found) {
			std::cout << i;
		}
		else {
			std::cout << '_';
		}
	}

	std::cout << '\t';

	std::cout << "Wrong guesses ";
	//display remaining lives
	for (int j{ 0 }; j < m_lives; j++) {
		std::cout << '+';
	}

	// display wrong guessed letters
	std::reverse(m_wrongGuesses.begin(), m_wrongGuesses.end());
	for (const auto& c : m_wrongGuesses) {
		std::cout << c;
	}

	std::cout << "\n";
}

void Session::addGuessedCharacter(char guess) {
	m_guessedCharacters.emplace_back(guess);
}

void Session::addWrongGuesses(char guess) {
	m_wrongGuesses.emplace_back(guess);
}

bool Session::isLetterGuessed(char guess) const {
	for (const auto& c : m_guessedCharacters) {
		if (c == guess) {
			return true;
		}
	}

	return false;
}

bool Session::isCorrectLetter(char guess) const {
	for (const auto& c : m_word) {
		if (c == guess) {
			return true;
		}
	}

	return false;
}

bool Session::isGameWon() const {
	int count{ 0 };
	for (const auto& c : m_word) {

		for (const auto& i : m_guessedCharacters) {
			if (c == i) count++;
		}
	}

	return count >= m_word.length();
}