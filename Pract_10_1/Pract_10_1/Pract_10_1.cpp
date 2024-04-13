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
        content += line;
    }

    fin.close();
    return content;
}

bool hasQuadruple(const string& text) {
    for (size_t i = 0; i < text.length() - 3; ++i) {
        if (text[i] == text[i + 1] && text[i] == text[i + 2] && text[i] == text[i + 3]) {
            return true;
        }
    }
    return false;
}

int main() {
    string filename;
    cout << "Enter the path to the file: ";
    cin >> filename;

    string content = readTextFile(filename);
    if (content.empty()) {
        return 1;
    }

    bool hasQuadrupleResult = hasQuadruple(content);
    if (hasQuadrupleResult) {
        cout << "The file contains a quadruple of consecutive identical characters." << endl;
    }
    else {
        cout << "The file does not contain a quadruple of consecutive identical characters." << endl;
    }

    return 0;
}
