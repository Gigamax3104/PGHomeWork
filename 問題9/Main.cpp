#include	<iostream>
#include	"janken.h"
#include	"kazuate.h"
using namespace std;

enum Choice {
	Janken = 1,
	Kazuate = 2,
	End = 3
};

int main() {
	int choice;
	do {
		cout << "�I�����ĂˁI\n1 : ����񂯂�Q�[���A2 : �����ăQ�[���A3 : �I��(����ȊO����͂���Ƌ����I�����܂��B)>" << flush;
		cin >> choice;
		cout << endl;

		switch (choice) {
		case Janken:
			LimitInput(); break;
		case Kazuate:
			KazuateMove(); break;
		case End:
			break;
		}

	} while (choice < Janken || choice > End);
}