#include	<iostream>
#include	<cmath>
using namespace std;

int str2int(const char* s);

int main() {
	const char* s = "128";

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
		number[idx] = *s - '0';

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