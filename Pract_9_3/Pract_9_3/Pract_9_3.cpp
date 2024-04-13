#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Структура для зберігання інформації про товар
struct Product {
    string name;
    string shop;
    float price;
    int quantity;
    string unit;
};

// Глобальна змінна для зберігання шляху до файлу
string filename;

// Функція для додавання товару до списку
void addProduct(vector<Product>& productList) {
    Product newProduct;
    cout << "Enter product name: ";
    cin >> newProduct.name;
    cout << "Enter shop name: ";
    cin >> newProduct.shop;
    cout << "Enter price per unit: ";
    cin >> newProduct.price;
    cout << "Enter quantity: ";
    cin >> newProduct.quantity;
    cout << "Enter unit: ";
    cin >> newProduct.unit;

    productList.push_back(newProduct);
}

// Функція для виведення списку товарів на екран
void printProductList(const vector<Product>& productList) {
    if (productList.empty()) {
        cout << "The product list is empty." << endl;
        return;
    }

    cout << "Product list:" << endl;
    for (const auto& product : productList) {
        cout << "Name: " << product.name << ", Shop: " << product.shop << ", Price: " << product.price << ", Quantity: " << product.quantity << ", Unit: " << product.unit << endl;
    }
}

// Функція для виведення всього масиву у файл
void saveProductListToFile(const vector<Product>& productList) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& product : productList) {
        fout << product.name << " " << product.shop << " " << product.price << " " << product.quantity << " " << product.unit << endl;
    }

    cout << "Product list has been saved to file: " << filename << endl;
    fout.close();
}

// Функція для зчитування всіх даних із файлу
void readProductListFromFile(vector<Product>& productList) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    productList.clear(); // Очистимо попередні дані, якщо вони були

    Product product;
    while (fin >> product.name >> product.shop >> product.price >> product.quantity >> product.unit) {
        productList.push_back(product);
    }

    cout << "Product list has been read from file: " << filename << endl;
    fin.close();
}

int main() {
    vector<Product> productList;

    cout << "Enter filename: ";
    cin >> filename;

    // Завантаження даних з файлу
    readProductListFromFile(productList);

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add product" << endl;
        cout << "2. Print product list" << endl;
        cout << "3. Save product list to file" << endl;
        cout << "4. Read product list from file" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct(productList);
            break;
        case 2:
            printProductList(productList);
            break;
        case 3:
            saveProductListToFile(productList);
            break;
        case 4:
            readProductListFromFile(productList);
            break;
        case 5:
            cout << "Exiting program." << endl;
            // Збереження даних у файл перед виходом
            saveProductListToFile(productList);
            return 0;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}
