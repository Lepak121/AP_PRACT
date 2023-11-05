#include <iostream>
#include <cmath>
using namespace std;

double s(const double x);

int main()
{
    double tp, tk, z;
    int n;
    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;

    double tg = (tk - tp) / n;
    double t = tp;

    while (t <= tk)
    {
        z = s(2 * t + 1) + 2 * s(t * t)+sqrt(s(1));
        cout << t << " " << z << endl;
        t += tg;
    }

    return 0;
}

double s(const double x)
{
    if (x != 0 && abs(x) >= 1)
    {
        return (pow(cos(x), 2) + 1) / exp(x) * exp(x);
    }
    else
    {
        double S = 0;
        int k = 0;
        double a = 1;
        S = a;

        do
        {
            k++;
            double R = (pow(2, 2 * k + 1) * pow(x, 2 * k + 1)) / ((2 * k) * (3 * k + 1) * 2 * k);
            a *= R;
            S += a;
        } while (k < 4);

        return S;
    }
}
