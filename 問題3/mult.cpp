#include	<iostream>
using namespace std;

static int mult(int a, int b);

int main() {
	int a = 0;
	int b = 0;

	cout << "2�̐�������͂��Ă��������B>" << flush;
	cin >> a >> b;

	cout << "�|���Z�������ʂ�" << mult(a, b) << "�ł��B" << endl;
}

static int mult(int a, int b) {
	return a * b;
}