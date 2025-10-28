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
		cout << "選択してね！\n1 : じゃんけんゲーム、2 : 数当てゲーム、3 : 終了(それ以外を入力すると強制終了します。)>" << flush;
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