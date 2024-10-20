#include <iostream>
#include <string>

using namespace std;

// Функції для логічних операцій
bool logicalAnd(bool p, bool q) {
    return p && q;
}

bool logicalOr(bool p, bool q) {
    return p || q;
}

bool logicalXor(bool p, bool q) {
    return p ^ q;
}

bool implication(bool p, bool q) {
    return !p || q;
}

bool equivalence(bool p, bool q) {
    return p == q;
}

// Функції для побітових операцій
string bitwiseOr(const string& a, const string& b) {
    string result;
    for (size_t i = 0; i < a.length(); ++i) {
        result += (a[i] == '1' || b[i] == '1') ? '1' : '0';
    }
    return result;
}

string bitwiseAnd(const string& a, const string& b) {
    string result;
    for (size_t i = 0; i < a.length(); ++i) {
        result += (a[i] == '1' && b[i] == '1') ? '1' : '0';
    }
    return result;
}

string bitwiseXor(const string& a, const string& b) {
    string result;
    for (size_t i = 0; i < a.length(); ++i) {
        result += (a[i] != b[i]) ? '1' : '0';
    }
    return result;
}

// Функція для введення булевих значень
void inputBooleanValues(bool& p, bool& q) {
    cout << "Vvedit znachenya p (0 abo 1): ";
    cin >> p;

    cout << "Vvedit znachenya q (0 abo 1): ";
    cin >> q;
}

// Функція для введення бітових рядків
void inputBitStrings(string& a, string& b) {
    cout << "Vvedit bit znach a: ";
    cin >> a;

    cout << "Vvedit bit ryadok b: ";
    cin >> b;
}

// Функція для виведення результатів логічних операцій
void outputLogicalResults(bool p, bool q) {
    cout << "Konkukcia (p AND q): " << logicalAnd(p, q) << endl;
    cout << "Dizyunkcia (p OR q): " << logicalOr(p, q) << endl;
    cout << "Alternativne 'abo' (p XOR q): " << logicalXor(p, q) << endl;
    cout << "Implikacia (p -> q): " << implication(p, q) << endl;
    cout << "Ekvivalentnist (p <-> q): " << equivalence(p, q) << endl;
}

// Функція для виведення результатів побітових операцій
void outputBitwiseResults(const string& x, const string& y, const string& z) {
    cout << "Rez bit operacii OR:  " << x << endl;
    cout << "Rez bit operacii AND: " << y << endl;
    cout << "Rez bit operacii XOR: " << z << endl;
}

// Основна функція
int main() {
    // Частина 1: Логічні операції
    bool p, q;
    inputBooleanValues(p, q);
    outputLogicalResults(p, q);

    // Частина 2: Побітові операції
    string a, b; // Два бітові рядки
    inputBitStrings(a, b);

    // Перевірка, чи рядки мають однакову довжину
    if (a.length() != b.length()) {
        cout << "Ryadku mayut bytu odniyeyi dovzyny!" << endl;
        return 1; // Завершуємо програму, якщо рядки різної довжини
    }

    // Виконання побітових операцій
    string x = bitwiseOr(a, b);
    string y = bitwiseAnd(a, b);
    string z = bitwiseXor(a, b);

    // Виведення результатів побітових операцій
    outputBitwiseResults(x, y, z);

    return 0;
}
