#include	<iostream>
using namespace std;

static int mult(int a, int b);

int main() {
	int a = 0;
	int b = 0;

	cout << "2‚Â‚Ì”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B>" << flush;
	cin >> a >> b;

	cout << "Š|‚¯Z‚µ‚½Œ‹‰Ê‚Í" << mult(a, b) << "‚Å‚·B" << endl;
}

static int mult(int a, int b) {
	return a * b;
}