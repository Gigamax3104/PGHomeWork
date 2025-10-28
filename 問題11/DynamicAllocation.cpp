#include	<iostream>
using namespace std;

static int Total(int* student,int size);
static float Average(int total,int size);

int main() {
	int size;
	int total = 0;

	cout << "何人分のテストの点数を入力しますか\?>" << flush;
	cin >> size;

	int* Student = new int[size];

	total = Total(Student, size);

	cout << "合計値は" << total << "点、" << "平均値は" << Average(total, size) << "点です。";

	delete[] Student;
}

static int Total(int* student,int size) {
	int total = 0;

	for (int i = 0; i < size; i++) {
		cout << i + 1 << "人目:" << flush;
		cin >> student[i];
		total += student[i];
	}

	return total;
}

static float Average(int total,int size) {
	return total / size;
}