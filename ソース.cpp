#include    <iostream>
#include    <cstring>
using namespace std;

const char* str_match(const char* s1, const char* s2) {
    if (!s1 || !s2 || *s2 == '\0') return nullptr;

    //unsigned int と intで結果が違ってくる
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    for (size_t i = 0; i <= len1 - len2; ++i) {
        if (strncmp(s1 + i, s2, len2) == 0) {
            return s1 + i;
        }
    }
    return nullptr;
}

int main() {
    const char* s1 = "abc";
    const char* s2 = "aaaaaa";

    const char* result = str_match(s1, s2);

    if (result) {
        cout << "一致した位置: " << result << endl;
        cout << "インデックス: " << result - s1 << endl;
    }
    else {
        cout << "一致する部分文字列は見つかりませんでした。" << endl;
    }

    return 0;
}