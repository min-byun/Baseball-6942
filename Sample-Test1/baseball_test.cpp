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

TEST_F(BaseballFixtrue, ReturnSolvedResultIfMatchedNumber3strikes) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixtrue, ReturnSolvedResultIfMatchedNumber2strikes0ball) {
	GuessResult result = game.guess("124");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixtrue, ReturnSolvedResultIfMatchedNumber1strike2ball) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}
