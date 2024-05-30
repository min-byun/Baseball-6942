#include "pch.h"
#include "../BaseballProj/baseball.cpp"
#include <stdexcept>

using namespace std;

class BaseballFixtrue : public testing::Test
{
public:
	Baseball  game{"123"};
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
	assertllegalArgument("121");
}

TEST_F(BaseballFixtrue, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}
