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
		cout << "“–‚Ä‚Í‚Ü‚Á‚½•¶Žš‚Í‚ ‚è‚Ü‚¹‚ñII" << endl;
	}
	else {
		cout << "Œ³‚Ì•¶Žš—ñ:" << s1 << endl;
		cout << "“–‚Ä‚Í‚Ü‚Á‚½•¶Žš—ñ:" << str_match(s1, s2) << endl;
	}
}

const char* str_match(const char* s1, const char* s2) {
	int idx = 0;
	size_t SL = strlen(s2);

	for (int i = 0; *(s1 + i) != '\0'; i++) {
		if(*(s1 + i) == *(s2 + idx)) {
			idx++;
		}

		if (idx == SL) {
			return s1 + ((i - SL) + 1);
		}

	}

	return nullptr;
}