#include <iostream>
#include <iomanip>
#include <vector>
#include <Windows.h>
using namespace std;
unsigned long long arrangements(int n, int r) {
    unsigned long long P1 = 1;
    for (int i = 1; i <= n; ++i) {
        P1 *= i;
    }

    unsigned long long P2 = 1;
    for (int i = 1; i <= n - r; ++i) {
        P2 *= i;
    }

    return P1 / P2;
}

vector<vector<unsigned long long>> generate_stirling_table(int n) {
    vector<vector<unsigned long long>> F(n + 1, vector<unsigned long long>(n + 1, 0));

    for (int j = 1; j <= n; ++j) {
        F[j][1] = 1; 
        F[j][j] = 1; 
    }

    for (int j = 3; j <= n; ++j) {
        for (int k = 3; k <= j; ++k) {
            F[j][k] = F[j - 1][k - 1] + k * F[j - 1][k];
        }
    }

    return F;
}

vector<unsigned long long> bell_numbers(int n, const vector<vector<unsigned long long>>& F) {
    vector<unsigned long long> B(n + 1, 0);

    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= j; ++k) {
            B[j] += F[j][k];
        }
    }

    return B;
}

int main() {
 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Завдання 1: Обчислення розміщень без повторень\n";
    int variants[15][2] = {
        {6, 5}, {5, 3}, {8, 1}, {8, 5},
        {8, 8}, {10, 9}, {9, 4}, {7, 3},
        {12, 6}, {10, 8}, {5, 4}, {9, 6},
        {10, 8}, {8, 2}, {9, 4}
    };

    for (int i = 0; i < 15; ++i) {
        int n = variants[i][0];
        int r = variants[i][1];
        cout << "Варіант " << (i + 1) << ": n = " << n << ", r = " << r
            << ", A(" << n << ", " << r << ") = " << arrangements(n, r) << endl;
    }

    int i = 15;
    int n = i + 5;
    vector<vector<unsigned long long>> stirling = generate_stirling_table(n);

    cout << "\nТаблиця чисел Стірлінга другого роду для n = " << n << ":\n";
    cout << setw(5) << "n\\k";
    for (int k = 1; k <= n; ++k) {
        cout << setw(10) << k;
    }
    cout << endl;

    cout << string(5 + 10 * (n + 1), '-') << endl; 

    for (int j = 1; j <= n; ++j) {
        cout << setw(5) << j << "|";
        for (int k = 1; k <= j; ++k) {
            cout << setw(10) << stirling[j][k];
        }
        cout << endl;
    }

    vector<unsigned long long> bell = bell_numbers(n, stirling);
    cout << "\nЧисла Белла для n = " << n << ":\n";
    cout << setw(5) << "n" << setw(15) << "B(n)" << endl;
    cout << string(20, '-') << endl;

    for (int j = 0; j <= n; ++j) {
        cout << setw(5) << j << setw(15) << bell[j] << endl; 
    }

    return 0;
}
