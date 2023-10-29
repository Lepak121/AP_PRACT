#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double P1, P2;
    int n, k;

    P1 = 1;
    k = 1;

    while (k <= 20)
    {
        P2 = 1;
        n = 1;

        while (n <= 25 - k)
        {
            P2 += (k - n) / (k + n) + 1;
            n++;
        }

        P1 *= P2;
        k++;
    }

    cout << P1 << endl;

    P1 = 1;
    k = 1;

    do {
        P2 = 1;
        n = 1;

        do {
            P2 += (k - n) / (k + n) + 1;
            n++;
        } while (n <= 25 - k);

        P1 *= P2;
        k++;
    } while (k <= 20);

    cout << P1 << endl;

    P1 = 1;

    for (k = 1; k <= 20; k++) {
        P2 = 1;

        for (n = 1; n <= 25 - k; n++) {
            P2 += (k - n) / (k + n) + 1;
        }

        P1 *= P2;
    }

    cout << P1 << endl;

    

    for (k = 20; k >= 1; k--)
    {
        double P2 = 1;

        for (n = 25 - k; n >= 1; n--)
        {
            P2 *= ((k - n) / (k + n) + 1);
        }

        P1 *= P2;
    }

    cout << P1 << endl;

    return 0;
}