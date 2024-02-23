#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void SmoothMatrix(int** a, const int rowCount, const int colCount);
int SumBelowMainDiagonal(int** a, const int rowCount, const int colCount);

int main() {
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    SmoothMatrix(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int sum = SumBelowMainDiagonal(a, rowCount, colCount);
    cout << "Suma moduliv chysel pid diagonalyu:" << sum << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SmoothMatrix(int** a, const int rowCount, const int colCount) {
    int** temp = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        temp[i] = new int[colCount];

    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            int sum = 0;
            int count = 0;
            for (int ni = i - 1; ni <= i + 1; ni++) {
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if (ni >= 0 && ni < rowCount && nj >= 0 && nj < colCount) {
                        if (!(ni == i && nj == j)) {  
                            sum += a[ni][nj];
                            count++;
                        }
                    }
                }
            }
            temp[i][j] = sum / count;
        }
    }

    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = temp[i][j];

    for (int i = 0; i < rowCount; i++)
        delete[] temp[i];
    delete[] temp;
}


int SumBelowMainDiagonal(int** a, const int rowCount, const int colCount) {
    int sum = 0;
    for (int i = 1; i < rowCount; i++) {
        for (int j = 0; j < i; j++) { 
            sum += abs(a[i][j]);
        }
    }
    return sum;
}

