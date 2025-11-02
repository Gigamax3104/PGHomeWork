#include	<iostream>
using namespace std;

void swap_string(char* s1, char* s2);

int main() {
	char a[] = "abc";
	char b[] = "def";

	swap_string(a, b);

	cout << a << b << endl;
}

void swap_string(char* s1, char* s2) {
	int idx = 0;
	char* save = s2;
	char save2[3];

	while (*s1) {
		save2[idx] = *s1;
		*s1 = *s2;
		s1++;
		s2++;

		idx++;
	}

	s2 = save;

	for (int i = 0; i < idx; i++) {
		*s2 = save2[i];
		s2++;

	}
}