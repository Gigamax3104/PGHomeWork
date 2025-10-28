#include    <iostream>
#include    <cstring>
using namespace std;

const char* str_match(const char* s1, const char* s2) {
    if (!s1 || !s2 || *s2 == '\0') return nullptr;

    //unsigned int �� int�Ō��ʂ�����Ă���
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
        cout << "��v�����ʒu: " << result << endl;
        cout << "�C���f�b�N�X: " << result - s1 << endl;
    }
    else {
        cout << "��v���镔��������͌�����܂���ł����B" << endl;
    }

    return 0;
}