#pragma once

#include <string>
#include <vector>

class Session {
public:
	Session(const std::string& word);

	std::vector<char> getGuessedCharacters() const { return m_guessedCharacters; };

	void displayState();
	void addGuessedCharacter(char guess);
	void addWrongGuesses(char guess);
	bool isLetterGuessed(char guess) const;
	bool isCorrectLetter(char guess) const;
	bool isGameWon() const;

	void reduceLives() { m_lives--; };

	int getLives() const { return m_lives; };

private:
	std::string m_word{};
	std::vector<char> m_guessedCharacters{};
	std::vector<char> m_wrongGuesses{};
	int m_lives{ 6 };
};