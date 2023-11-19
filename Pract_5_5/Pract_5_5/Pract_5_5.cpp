#include <iostream>
using namespace std;
int c(int n, int k) {
    if (k > n ) {
        return 0;
    }
    else if (k == 0 || k == n) {
        return 1;
    }
    else {
        return c(n - 1, k - 1) +c(n - 1, k);
    }
}

int D(int n, int k) {
    if (k > n) {
        return 0;
    }
    else if (k == 0 || k == n) {
        return 1;
    }
    else {
        return 1 + D(n - 1, k - 1) + D(n - 1, k);
    }
}

int main() {
    int n, k;
    cout << "n= ";
    cin >> n;
    cout << "k= ";
    cin >> k;

    int C = c(n, k);
    cout << "C(" << n << ", " << k << ") = " << C << std::endl;
    cout << "Glybyna rekursiyi = " << D(n, k) << std::endl;

    return 0;
}
