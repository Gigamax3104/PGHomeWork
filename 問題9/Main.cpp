#include	<iostream>
#include	"janken.h"
#include	"kazuate.h"
using namespace std;

int main() {
	int choice;
	
	cout << "選択してね！\n1 : じゃんけんゲーム、2 : 数当てゲーム、3 : 終了(それ以外を入力すると強制終了します。)>" << flush;
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