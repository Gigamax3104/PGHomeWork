#include	<iostream>
#include	"janken.h"
#include	"kazuate.h"
using namespace std;

int main() {
	int choice;
	
	cout << "�I�����ĂˁI\n1 : ����񂯂�Q�[���A2 : �����ăQ�[���A3 : �I��(����ȊO����͂���Ƌ����I�����܂��B)>" << flush;
	cin >> choice;
	cout << endl;

	switch (choice) {
		case 1:
			LimitInput(); break;
		case 2:
			KazuateMove(); break;
		defalt:
			break;
	}
}