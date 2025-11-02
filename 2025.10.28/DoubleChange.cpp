#include	<iostream>
using namespace std;

double str2double(const char* s);

int main() {
	const char* s = "32.54";

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
	bool PlusChange = false;
	const char* save = s;

	while (*s) {
		if (!PlusChange && *s >= '0' && *s <= '9') {
			idx++;
		}
		else if (PlusChange && *s >= '0' && *s <= '9') {
			idx2++;
		}
		else if (*s == '.') {
			PlusChange = true;
		}
		else {
			return 0.0;
		}

		s++;
	}

	double* number = new double[idx];
	double* number2 = new double[idx2];
	double Pow = pow(10, idx - 1);
	double Pow2 = 0.1;
	number[0] = 0;
	number2[0] = 0;
	s = save;

	for (int i = 0; i < idx; i++) {
		switch (*s) {
		case '0':
			number[i] = 0; break;
		case '1':
			number[i] = 1; break;
		case '2':
			number[i] = 2; break;
		case '3':
			number[i] = 3; break;
		case '4':
			number[i] = 4; break;
		case '5':
			number[i] = 5; break;
		case '6':
			number[i] = 6; break;
		case '7':
			number[i] = 7; break;
		case '8':
			number[i] = 8; break;
		case '9':
			number[i] = 9; break;
		}

		s++;
	}

	s++;

	for (int i = 0; i < idx2; i++) {
		switch (*s) {
		case '0':
			number2[i] = 0; break;
		case '1':
			number2[i] = 1; break;
		case '2':
			number2[i] = 2; break;
		case '3':
			number2[i] = 3; break;
		case '4':
			number2[i] = 4; break;
		case '5':
			number2[i] = 5; break;
		case '6':
			number2[i] = 6; break;
		case '7':
			number2[i] = 7; break;
		case '8':
			number2[i] = 8; break;
		case '9':
			number2[i] = 9; break;
		}

		s++;
	}

	for (int i = 0; i < idx; i++) {
		total += Pow * number[i];
		Pow /= 10;
	}

	for (int i = 0; i < idx2; i++) {
		total += Pow2 * number2[i];
		Pow2 /= 10;
	}

	delete[] number;
	delete[] number2;
	return total;
}