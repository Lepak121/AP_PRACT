#include <iostream>
#include <cmath>
using namespace std;

double g(const double a, const double b, const double c);

int main() {
    double x, y;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    double d = (g(x * y, x * x, y * y) - g(1, x, y) * g(1, x, y)) / (1 + g(sqrt(x), y * y, 1));

    cout << "d = " << d << endl;

    return 0;
}

double g(const double a, const double b, const double c) {
    return (a * a + b * b - c * c);
}
