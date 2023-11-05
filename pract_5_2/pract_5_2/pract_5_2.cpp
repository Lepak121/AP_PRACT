#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(12) << "arctan(x)" << " |"
        << setw(7) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(12) << setprecision(5) << atan(x) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |"
            << endl;
        x += dx;
    }

    cout << "-------------------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = x;
    s = a;

    do
    {
        n++;
        a = A(x, n);
        s += a;
    } while (abs(a) >= eps);

    return s;
}

double A(const double x, const int n)
{
    double R = pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1);
    return R;
}
