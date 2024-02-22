#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


void Create(int** a, const int n, const int Low, const int High);


void Print(int** a, const int n);


bool SearchMinOnSecondaryDiagonal(int** a, const int n, int& minElement);

int main() {
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;
    int n;

    cout << "Enter the size of the matrix: ";
    cin >> n;


    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];


    Create(a, n, Low, High);


    cout << "Matrix:" << endl;
    Print(a, n);


    int minElement;


    if (SearchMinOnSecondaryDiagonal(a, n, minElement))
        cout << "minimalne znachenya na pobichniy diagonali: " << minElement << endl;
    else
        cout << "minimalne znachenya ne znaideno" << endl;


    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}


void Create(int** a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}


void Print(int** a, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}


bool SearchMinOnSecondaryDiagonal(int** a, const int n, int& minElement) {
    minElement = INT_MAX;


    for (int i = 0; i < n; i++) {
        int j = n - 1 - i;


        if (a[i][j] < minElement)
            minElement = a[i][j];
    }


    return minElement != INT_MAX;
}
