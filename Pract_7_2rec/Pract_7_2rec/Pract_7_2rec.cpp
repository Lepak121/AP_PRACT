#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low,
    const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

void SearchMinOnDiagonal(int** a, const int N, int i, int& minDiagonal)
{
    if (a[i][N - 1 - i] < minDiagonal)
        minDiagonal = a[i][N - 1 - i];
    if (i < N - 1)
        SearchMinOnDiagonal(a, N, i + 1, minDiagonal);
}

int main()
{
    srand((unsigned)time(NULL));

    int N;
    cout << "N = ";
    cin >> N;
    cout << endl;

    int** a = new int* [N];

    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    int Low = 5, High = 40;
    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    int minDiagonal = a[0][N - 1];
    SearchMinOnDiagonal(a, N, 0, minDiagonal);

    cout << "minOnDiagonal = " << minDiagonal << endl;

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
