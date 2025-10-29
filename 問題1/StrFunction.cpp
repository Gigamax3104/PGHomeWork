#include	<iostream>
#include	<cstring>
using namespace std;

const int MAX = 18;

const char* str_match(const char* s1, const char* s2);

int main() {
	char s1[MAX];
	char s2[MAX];

	cout << "1”Ô–Ú:" << flush;
	cin >> s1;

	cout << "2”Ô–Ú:" << flush;
	cin >> s2;

	if (str_match(s1, s2) == nullptr) {
		cout << "“–‚Ä‚Í‚Ü‚Á‚½•¶Žš—ñ‚Í‚ ‚è‚Ü‚¹‚ñII" << endl;
	}
	else {
		cout << "Œ³‚Ì•¶Žš—ñ:" << s1 << endl;
		cout << "“–‚Ä‚Í‚Ü‚Á‚½•¶Žš—ñ:" << str_match(s1, s2) << endl;
	}
}

const char* str_match(const char* s1, const char* s2) {
	int idx = 0;
	bool next = false;
	const char* str2 = s2;

	while (*s1) {
		if (*s1 == *s2) {
			next = false;
			idx++;
			s1++;
			s2++;
		}
		else{
			if (next) {
				s1++;
			}

			next = true;
			idx = 0;
			s2 = str2;
		}

		if (*s2 == '\0') {
			return s1 - idx;
		}
	}

	return nullptr;
}