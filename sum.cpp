#include	<iostream>
#include	"calc.h"
using namespace std;

int main() {
	int a = 0;
	int b = 0;

	cout << "2�̐�������͂��Ă��������B>" << flush;
	cin >> a >> b;

	cout << "�����Z�������ʂ�" << sum(a, b) << "�ł��B" << endl;
}