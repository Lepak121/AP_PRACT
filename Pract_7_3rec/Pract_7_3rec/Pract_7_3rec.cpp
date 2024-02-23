#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void PrintMatrix(int** matrix, const int size, int i = 0, int j = 0) {
    if (i == size) {
        cout << endl;
        return;
    }

    cout << setw(4) << matrix[i][j];

    if (j == size - 1) {
        cout << endl;
        PrintMatrix(matrix, size, i + 1, 0);
    }
    else {
        PrintMatrix(matrix, size, i, j + 1);
    }
}

void InputMatrix(int** matrix, const int size, int i = 0, int j = 0) {
    if (i == size) {
        return;
    }

    matrix[i][j] = rand() % 21 - 10;

    if (j == size - 1) {
        InputMatrix(matrix, size, i + 1, 0);
    }
    else {
        InputMatrix(matrix, size, i, j + 1);
    }
}

void SmoothMatrix(int** matrix, int** smoothedMatrix, const int size, int i = 0, int j = 0) {
    if (i == size) {
        return;
    }

    int sum = 0;
    int count = 0;

    
    int k = max(0, i - 1);
    while (k <= min(size - 1, i + 1)) {
        int l = max(0, j - 1);
        while (l <= min(size - 1, j + 1)) {
            sum += matrix[k][l];
            ++count;
            ++l;
        }
        ++k;
    }

    
    smoothedMatrix[i][j] = sum / count;

    
    if (j == size - 1) {
        SmoothMatrix(matrix, smoothedMatrix, size, i + 1, 0);
    }
    else {
        SmoothMatrix(matrix, smoothedMatrix, size, i, j + 1);
    }
}

int SumBelowMainDiagonal(int** matrix, const int size, int i = 1, int j = 0, int sum = 0) {
    if (i == size) {
        return sum;
    }

    if (j < i) {
        sum += abs(matrix[i][j]);
    }

    if (j == size - 1) {
        return SumBelowMainDiagonal(matrix, size, i + 1, 0, sum);
    }
    else {
        return SumBelowMainDiagonal(matrix, size, i, j + 1, sum);
    }
}

int main() {
    int size;
    cout << "Vedit rozmir masuvy: ";
    cin >> size;

    int** matrix = new int* [size];
    int** smoothedMatrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
        smoothedMatrix[i] = new int[size];
    }

    srand(time(NULL));

    InputMatrix(matrix, size);

    cout << "Original Matrix:" << endl;
    PrintMatrix(matrix, size);

    SmoothMatrix(matrix, smoothedMatrix, size);

    cout << "Smoothed Matrix:" << endl;
    PrintMatrix(smoothedMatrix, size);

    int sumBelowDiagonal = SumBelowMainDiagonal(smoothedMatrix, size);
    cout << "Sum of absolute values below the main diagonal: " << sumBelowDiagonal << endl;

    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
        delete[] smoothedMatrix[i];
    }
    delete[] matrix;
    delete[] smoothedMatrix;

    return 0;
}
