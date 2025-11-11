#include	<iostream>
using namespace std;

static void swap_ptr(char** pStr1,char** pStr2); //ポインタを交換する際にポインタ参照を扱う。

int main() {
	char str1[] = "abcd";
	char str2[] = "ABCD";

	char* pStr1 = str1;
	char* pStr2 = str2;

	cout << pStr1 << endl; // abcdと表示される
	cout << pStr2 << endl; // ABCDと表示される

	swap_ptr(&pStr1, &pStr2);

	cout << pStr1 << endl; // ABCDと表示される
	cout << pStr2 << endl; // abcdと表示される
}

static void swap_ptr(char** pStr1,char** pStr2) { //*&より、**の方が良い。
	cout << "mainのpStr1:" << (size_t)*pStr1 << endl;
	cout << "mainのpStr2:" << (size_t)*pStr2 << endl;

	char* p = *pStr1;
	*pStr1 = *pStr2;
	*pStr2 = p;

	cout << "mainのpStr1:" << (size_t)*pStr1 << endl;
	cout << "mainのpStr2:" << (size_t)*pStr2 << endl;
}
