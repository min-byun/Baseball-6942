#include "pch.h"
#include "../BaseballProj/baseball.cpp"
#include <stdexcept>

using namespace std;

class BaseballFixtrue : public testing::Test
{
public:
	Baseball  game;
	void assertllegalArgument(string guessNumber) {
		//game.guess  수햏ㅇ 후 Exception이 발생해야 PASS
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixtrue, ThrowExceptionWhenInvalidCase) {
	assertllegalArgument("12");
	assertllegalArgument("12s");
}

