#include	<iostream>
using namespace std;

static int Total(int* student,int size);
static float Average(int total,int size);

int main() {
	int size;
	int total = 0;

	cout << "���l���̃e�X�g�̓_������͂��܂���\?>" << flush;
	cin >> size;

	int* Student = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> Student[i];
		total = Total(&Student[i], size);
	}

	cout << "���v�l��" << total << "�_�A" << "���ϒl��" << Average(total, size) << "�_�ł��B";

	delete[] Student;
}

static int Total(int* student,int size) {
	static int total = 0;

	total += *student;
	//for (int i = 0; i < size; i++) {
	//	cout << i + 1 << "�l��:" << flush;
	//	cin >> student[i];
	//	total += student[i];
	//}

	return total;
}

static float Average(int total,int size) {
	return total / size;
}