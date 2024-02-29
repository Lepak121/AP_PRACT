#include <iostream>
#include <cstring>

using namespace std;

int Count(const char* s) {
    int k = 0;
    size_t pos = 0;
    while (s[pos] != '\0') {
        if (s[pos] == s[pos + 1] && s[pos] == s[pos + 2] && s[pos] == s[pos + 3])
            k++;
        pos++;
    }
    return k;
}

char* Change(char* s) {
    size_t len = strlen(s);
    char* t = new char[len * 2 + 1];
    t[0] = '\0';
    size_t pos1 = 0;
    while (s[pos1] != '\0') {
        if (s[pos1] == s[pos1 + 1] && s[pos1] == s[pos1 + 2] && s[pos1] == s[pos1 + 3]) {
            strcat_s(t, len * 2 + 1, "**");
            pos1 += 4;
        }
        else {
            strncat_s(t, len * 2 + 1, s + pos1, 1);
            pos1++;
        }
    }
    strcpy_s(s, len * 2 + 1, t);
    delete[] t;
    return s;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of quadruplets" << endl;
    cout << "Modified string (param) : " << Change(str) << endl;
    return 0;
}
