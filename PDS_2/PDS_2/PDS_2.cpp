#include <iostream>
using namespace std;

int main() {
    cout << "p q r | p -> (q <-> r)" << endl;
    cout << "----------------------------" << endl;

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                // Еквівалентність (q <-> r)
                bool equivalence = (q && r) || (!q && !r);

                // Імплікація (p -> (q <-> r))
                bool result = !p || equivalence;

                cout << p << " " << q << " " << r << " | " << result << endl;
            }
        }
    }

    return 0;
}
