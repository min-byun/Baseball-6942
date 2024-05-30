#include "pch.h"
#include "../BaseballProj/baseball.cpp"
#include <stdexcept>

using namespace std;

TEST(BaseballGame, ThrowExceptionWheenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

