#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Структура, що представляє автомобіль
struct Car {
    string model;
    double price;
};

// Функція для додавання інформації про автомобіль до фірми
void addCarInfoToCompany(map<string, vector<Car>>& companies, const string& firm, const string& model, double price) {
    companies[firm].push_back({ model, price });
}

// Функція для знаходження максимальної ціни автомобіля для кожної фірми
map<string, double> calculateMaxPrices(const map<string, vector<Car>>& companies) {
    map<string, double> maxPrices;
    for (const auto& entry : companies) {
        double maxPrice = 0.0;
        for (const auto& car : entry.second) {
            if (car.price > maxPrice) {
                maxPrice = car.price;
            }
        }
        maxPrices[entry.first] = maxPrice;
    }
    return maxPrices;
}

// Функція для запису даних до файлу
void writeToFile(const map<string, vector<Car>>& companies, const map<string, double>& maxPrices, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& entry : companies) {
        fout << entry.first << ":\n";
        for (const auto& car : entry.second) {
            fout << "    " << car.model << " - " << car.price << endl;
        }
        fout << "Max price: " << maxPrices.at(entry.first) << endl << endl;
    }

    fout.close();
}

int main() {
    string filename;
    cout << "Enter the filename to save the data: ";
    getline(cin, filename);

    map<string, vector<Car>> companies;

    while (true) {
        string firm, model;
        double price;

        cout << "Enter firm name (or 'exit' to stop): ";
        getline(cin, firm);

        if (firm == "exit") {
            break;
        }

        cout << "Enter car model: ";
        getline(cin, model);

        cout << "Enter car price: ";
        cin >> price;
        cin.ignore(); // Очистка буфера вводу

        addCarInfoToCompany(companies, firm, model, price);
    }

    map<string, double> maxPrices = calculateMaxPrices(companies);

    writeToFile(companies, maxPrices, filename);

    cout << "Data has been written to " << filename << "." << endl;

    return 0;
}
