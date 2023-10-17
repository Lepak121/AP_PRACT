#include <iostream>

#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	double x, y, R, xp, xk, dx;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "R = "; cin >> R;
	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(7) << "y" << " |" << endl;
	cout << "---------------------------" << endl;

	x = xp;

	while (x <= xk)
	{

		if (x <= -8) {
			y = -R;
		}
		else if (x > -8 && x <= -R) {
			y = ((R * (x + 8)) / (-R) + 8) - R;
		}
		else if (x > -R && x <= R) {
			y = sqrt(pow(R, 2) - pow(x, 2)) * (-1);
		}
		else if (x > R && x <= 5) {
			y = (2 * x - 2 * R) / (5 - R);
		}
		else {
			y = 3;
		}

		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;

		x += dx;
	}
	cout << "---------------------------" << endl;
	return 0;
}