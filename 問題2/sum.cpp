#include	<iostream>
#include	"calc.h"
using namespace std;

int main() {
	int a = 0;
	int b = 0;

	cout << "2‚Â‚Ì”Žš‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B>" << flush;
	cin >> a >> b;

	cout << "‘«‚µŽZ‚µ‚½Œ‹‰Ê‚Í" << sum(a, b) << "‚Å‚·B" << endl;
}