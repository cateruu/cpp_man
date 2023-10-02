#pragma once

#include "Random.h"
#include <vector>

namespace WordList {
	extern std::vector<std::string> words;

	std::string pickRandomWord();
}