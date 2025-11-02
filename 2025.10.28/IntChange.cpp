#include	<iostream>
#include	<cmath>
using namespace std;

int str2int(const char* s);

int main() {
	const char* s = "";

	int a = str2int(s);

	if (a == 0) {
		cout << "”š‚Å‚Í‚ ‚è‚Ü‚¹‚ñB" << endl;
	}
	else {
		cout << a << endl;
	}
}

int str2int(const char* s) {
	int idx = 0;
	int total = 0;
	const char* save = s;

	while (*s) {
		if (*s >= '0' && *s <= '9') {
			idx++;
		}
		else {
			return 0;
		}

		s++;
	}

	int* number = new int[idx];
	double Pow = pow(10, idx - 1);
	idx = 0;
	number[idx] = 0;
	s = save;

	while (*s) {
		switch (*s) {
			case '0':
				number[idx] = 0; break;
			case '1':
				number[idx] = 1; break;
			case '2':
				number[idx] = 2; break;
			case '3':
				number[idx] = 3; break;
			case '4':
				number[idx] = 4; break;
			case '5':
				number[idx] = 5; break;
			case '6':
				number[idx] = 6; break;
			case '7':
				number[idx] = 7; break;
			case '8':
				number[idx] = 8; break;
			case '9':
				number[idx] = 9; break;
		}

		idx++;
		s++;
	}

	for (int i = 0; i < idx; i++) {
		total += (int)(Pow * number[i]);
		Pow /= 10;
	}

	delete[] number;
	return total;
}