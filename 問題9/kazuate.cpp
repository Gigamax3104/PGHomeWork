#include	<iostream>
#include	<cstdlib>
#include	<ctime>
#include	"kazuate.h"
using namespace std;

static void Random(int& number);
static void Show(int& number);
static JudgeMassage InputJudge(int& number,int& input);

//��ɓ��삷��֐�
void KazuateMove() {
	int number;

	Random(number);
	Show(number);
}

//�����_���ɐ��������߂�֐�
static void Random(int& number) {
	srand((unsigned int)time(NULL));

	number = rand() % 100 + 1;
}

//�\������֐�
static void Show(int& number) {
	int input;
	const char* massage[] = {
		"�����Ƒ傫����I�������I>",
		"�ɂ����I����������Ƒ傫����I�������I>",
		"�ɂ����I����������Ə�������I�������I>",
		"�����Ə�������I�������I>",
		"��`�����`�`��`�`�I�I�I"
	};

	cout << "1�`100�܂ł̐�����I��ŁA���ĂĂ݂ĂˁI>" << flush;

	do {
		cin >> input;
		cout << endl;

		cout << massage[InputJudge(number, input)];
	} while (InputJudge(number, input) != Draw2);
}

//���͂������ƁA�ړI�̐����r����֐�
static JudgeMassage InputJudge(int& number,int& input) {
	return
		number - input > 10 ? High :
		number - input > 0 ? LittleHigh :
		number - input == 0 ? Draw2 :
		number - input > -10 ? LittleLow : Low;
}
