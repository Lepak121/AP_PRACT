#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string readTextFile(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return "";
    }

    string content;
    string line;
    while (getline(fin, line)) {
        content += line + " ";
    }

    fin.close();
    return content;
}

int countWordsStartingWithB(const string& text) {
    int count = 0;
    bool inWord = false;

    for (char ch : text) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            inWord = false;
        }
        else {
            if (!inWord && tolower(ch) == 'b') { // Using tolower to make the comparison case-insensitive
                count++;
            }
            inWord = true;
        }
    }

    return count;
}

int main() {
    string filename;
    cout << "Enter the path to the file: ";
    getline(cin, filename); // Allowing spaces in the file path

    string content = readTextFile(filename);
    if (content.empty()) {
        return 1;
    }

    int wordCount = countWordsStartingWithB(content);
    cout << "Number of words starting with 'b': " << wordCount << endl;

    return 0;
}
