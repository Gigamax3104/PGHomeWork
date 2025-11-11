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
	double total = 0;
	bool Change = false;
	const char* save = s;

	while (*s) {
		if (*s >= '0' && *s <= '9') {
			idx++;
		}
		else if (*s == '.') {
			Change = true;
		}
		else {
			return 0.0;
		}

		s++;
	}

	double* number = new double[idx];
	double Pow = pow(10, idx - 1);
	double Pow2 = 0.1;
	number[0] = 0;
	s = save;

	for (int i = 0; i < idx; i++) {
		if (!Change) {
			total += Pow * number[i];
			Pow /= 10;
		}
	}

	delete[] number;
	return total;
}