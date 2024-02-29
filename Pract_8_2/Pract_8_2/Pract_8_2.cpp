#include <iostream>
#include <string>
using namespace std;

size_t CountWordsStartingWithB(const string& s)
{
    size_t count = 0;
    size_t start = 0;

    while ((start = s.find_first_of("bB", start)) != string::npos) 
    {
        if (start == 0 || s[start - 1] == ' ') 
            count++;

        start++;
    }

    return count;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Number of words starting with 'b': " << CountWordsStartingWithB(str) << endl;
    return 0;
}
