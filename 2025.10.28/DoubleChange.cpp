#include	<iostream>
using namespace std;

double str2double(const char* s);

int main() {
	const char* s = "12.5";

	double a = str2double(s);

	if (a == 0.0) {
		cout << "”Žš‚Å‚Í‚ ‚è‚Ü‚¹‚ñB" << endl;
	}
	else {
		cout << a << endl;
	}
}

double str2double(const char* s) {
	int idx = 0;
	int idx2 = 0;
	double total = 0;
	bool Stop = false;
	const char* save = s;

	while (*s) {
		if (*s >= '0' && *s <= '9') {
			if (!Stop) {
				idx2++;
			}

			idx++;
		}
		else if (*s == '.') {
			Stop = true;
		}
		else {
			return 0.0;
		}

		s++;
	}

	double* number = new double[idx];
	double Pow = pow(10, idx2 - 1);

	if (Pow == 0) {
		Pow = 1;
	}

	idx = 0;
	number[0] = 0;
	s = save;

	while (*s) {
		if (*s != '.') {
			number[idx] = *s - '0';
		}
		idx++;
		s++;
	}

	for (int i = 0; i < ; i++) {
		total += Pow * number[i];
		Pow /= 10;
	}

	delete[] number;
	return total;
}