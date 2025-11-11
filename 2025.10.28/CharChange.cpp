#include	<iostream>
using namespace std;

void swap_string(char* s1, char* s2);

int main() {
	char a[] = "abcdef";
	char b[] = "xyz";

	swap_string(a, b);

	cout << a << b << endl;
}

void swap_string(char* s1, char* s2) {
	int idx = 0;
	int size = 0;
	int size2 = 0;
	char* save = s1;
	char* save2 = s2;

	while (*s1) {
		size++;
		s1++;
	}

	while (*s2) {
		size2++;
		s2++;
	}

	char* save3;
	size >= size2 ? save3 = new char[size] : save3 = new char[size2];

	s1 = save;
	s2 = save2;

	if (size >= size2) {
		while (*s1) {
			save3[idx] = *s1;
			s1++;
			idx++;
		}

		s1 = save;

		while (*s1) {
			*s1 = *s2;
			s1++;
			s2++;
		}

		s2 = save2;

		for (int i = 0; i < size; i++) {
			*s2 = save3[i];
			s2++;
		}
	}
	else {
		while (*s2) {
			save3[idx] = *s2;
			s2++;
			idx++;
		}

		s2 = save2;

		while (*s2) {
			*s2 = *s1;
			s1++;
			s2++;
		}

		s1 = save;

		for (int i = 0; i < size2; i++) {
			*s1 = save3[i];
		}
	}

	delete[] save3;
}