#include "WordList.h"

namespace WordList {
	std::vector<std::string> words{ "mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };

	std::string pickRandomWord() {
		return words[Random::get<std::size_t>(0, words.size() - 1)];
	}
}