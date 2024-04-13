#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

bool isLogArgument(double x) {
    return x > 0;
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    string inputFilePath;
    cout << "Enter the file path: ";
    getline(cin, inputFilePath);

    ofstream initialFile(inputFilePath);
    if (!initialFile) {
        cerr << "Error: Unable to open the file for writing\n";
        return 1;
    }

    for (double x = -10.0; x <= 10.0; x += 0.5) {
        initialFile << x << endl;
    }
    initialFile.close();

    string outputFilePath;
    cout << "Enter the output file path: ";
    getline(cin, outputFilePath);

    ifstream inputFile(inputFilePath);
    ofstream resultFile(outputFilePath);

    if (!inputFile || !resultFile) {
        cerr << "Error: Unable to open files for reading/writing\n";
        return 1;
    }

    double number;
    while (inputFile >> number) {
        if (isLogArgument(number)) {
            resultFile << number << endl;
        }
    }

    inputFile.close();
    resultFile.close();

    ifstream resultFileForOutput(outputFilePath);
    if (!resultFileForOutput) {
        cerr << "Error: Unable to open the file for outputting to the screen\n";
        return 1;
    }

    cout << "Components that can be arguments of the function lg x:" << endl;
    while (resultFileForOutput >> number) {
        cout << number << endl;
    }
    resultFileForOutput.close();

    return 0;
}
