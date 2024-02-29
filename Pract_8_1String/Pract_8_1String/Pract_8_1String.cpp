#include <iostream>
#include <string>
using namespace std;

int Count(const string s)
{
    int k = 0;
    size_t pos = 0;
    while ((pos = s.find(s[pos], pos)) != string::npos)
    {
        pos++;
        if (pos + 3 < s.length() && s[pos] == s[pos + 1] && s[pos] == s[pos + 2] && s[pos] == s[pos + 3])
            k++;
    }
    return k;
}

string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find(s[pos], pos)) != string::npos)
    {
        if (pos + 3 < s.length() && s[pos] == s[pos + 1] && s[pos] == s[pos + 2] && s[pos] == s[pos + 3])
        {
            s.replace(pos, 4, "**");
            pos += 2;
        }
        else
            pos++;
    }
    return s;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "String contained " << Count(str) << " groups of quadruplets" << endl;
    string dest = Change(str);
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
