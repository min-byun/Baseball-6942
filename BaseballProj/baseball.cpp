#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};
class Baseball {
public:
	explicit Baseball(const string& question)
		:question(question) {

	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		int strikes = checkStrikes(guessNumber);
		bool solved = (strikes == 3)? true:false;
		int balls = checkBalls(guessNumber);
		return { solved,strikes,balls };
	}
private:
	string question;
	bool isDuplicatedNumber(const string& guessNumber) {
		return (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]);
	}
	void assertIllegalArgument(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	int checkStrikes(const string& guessNumber) {
		int strikes_num = 0;
		for (int i=0;i<3;i++){
			if (guessNumber[i] == question[i])
				strikes_num++;
		}
		return strikes_num;
	}
	int checkBalls(const string& guessNumber) {
		int balls_num = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (guessNumber[i] == question[j])
					balls_num++;
			}
		}
		return balls_num;
	}
};