#include	<iostream>
#include	<cstdlib>
#include	<ctime>
#include	"kazuate.h"
using namespace std;

static void Random(int& number);
static void Show(int& number);
static JudgeMassage InputJudge(int& number,int& input);

void KazuateMove() {
	int number;

	Random(number);
	Show(number);
}

static void Random(int& number) {
	srand((unsigned int)time(NULL));

	number = rand() % 100 + 1;
}

static void Show(int& number) {
	int input;
	const char* massage[] = {
		"もっと大きいよ！もう一回！>",
		"惜しい！もうちょっと大きいよ！もう一回！>",
		"惜しい！もうちょっと小さいよ！もう一回！>",
		"もっと小さいよ！もう一回！>",
		"大～当た～～り～～！！！"
	};

	cout << "1～100までの数字を選んで、当ててみてね！>" << flush;

	do {
		cin >> input;
		cout << endl;

		cout << massage[InputJudge(number, input)];
	} while (InputJudge(number, input) != Draw2);
}

static JudgeMassage InputJudge(int& number,int& input) {
	return
		number - input > 10 ? High :
		number - input > 0 ? LittleHigh :
		number - input == 0 ? Draw2 :
		number - input > -10 ? LittleLow : Low;
}
