#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Product {
    string name;
    string shop;
    double price;
    int quantity;
    string unit;
};

// Функція для зчитування списку товарів з файлу
void readProductsFromFile(const string& filename, vector<Product>& products) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Помилка при вiдкриттi файлу!" << endl;
        return;
    }

    products.clear();
    Product product;
    while (file >> product.name >> product.shop >> product.price >> product.quantity >> product.unit) {
        products.push_back(product);
    }

    file.close();
}

// Функція для запису списку товарів у файл
void writeProductsToFile(const string& filename, const vector<Product>& products) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Помилка при вiдкриттi файлу!" << endl;
        return;
    }

    for (const auto& product : products) {
        file << product.name << " " << product.shop << " " << product.price << " " << product.quantity << " " << product.unit << endl;
    }

    file.close();
}

// Функція для додавання нового товару до списку
void addProduct(vector<Product>& products) {
    Product newProduct;
    cout << "Введiть назву товару: ";
    cin >> newProduct.name;
    cout << "Введiть назву магазину: ";
    cin >> newProduct.shop;
    cout << "Введiть цiну товару: ";
    cin >> newProduct.price;
    cout << "Введiть кiлькiсть товару: ";
    cin >> newProduct.quantity;
    cout << "Введiть одиницю вимiрювання: ";
    cin >> newProduct.unit;

    products.push_back(newProduct);
}

// Функція для вилучення товару зі списку за індексом
void deleteProduct(vector<Product>& products, int index) {
    if (index >= 0 && index < products.size()) {
        products.erase(products.begin() + index);
    }
    else {
        cout << "Iндекс недiйсний!" << endl;
    }
}

// Функція для редагування інформації про товар за індексом
void editProduct(vector<Product>& products, int index) {
    if (index >= 0 && index < products.size()) {
        Product& product = products[index];
        cout << "Введiть нову назву товару: ";
        cin >> product.name;
        cout << "Введiть нову назву магазину: ";
        cin >> product.shop;
        cout << "Введiть нову цiну товару: ";
        cin >> product.price;
        cout << "Введіть нову кiлькiсть товару: ";
        cin >> product.quantity;
        cout << "Введiть нову одиницю вимiрювання: ";
        cin >> product.unit;
    }
    else {
        cout << "Iндекс недйсний!" << endl;
    }
}

// Функція для сортування товарів за назвою магазину
void sortByShop(vector<Product>& products) {
    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return a.shop < b.shop;
        });
}

// Функція для сортування товарів за загальною вартістю
void sortByTotalPrice(vector<Product>& products) {
    sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
        return (a.price * a.quantity) < (b.price * b.quantity);
        });
}

// Функція для виведення інформації про товари, що продаються в певному магазині
void displayProductsByShop(const vector<Product>& products, const string& shopName) {
    for (const auto& product : products) {
        if (product.shop == shopName) {
            cout << "Назва: " << product.name << ", Магазин: " << product.shop << ", Цiна: " << product.price << ", Кiлькiсть: " << product.quantity << " " << product.unit << endl;
        }
    }
}

// Функція для виведення інформації про товари з заданого діапазону вартості
void displayProductsByPriceRange(const vector<Product>& products, double minPrice, double maxPrice) {
    for (const auto& product : products) {
        double totalPrice = product.price * product.quantity;
        if (totalPrice >= minPrice && totalPrice <= maxPrice) {
            cout << "Назва: " << product.name << ", Магазин: " << product.shop << ", Цiна: " << product.price << ", Кiлькiсть: " << product.quantity << " " << product.unit << endl;
        }
    }
}
    int main() {
        setlocale(LC_CTYPE, "ukr");
        vector<Product> products;
        string filename;

        cout << "Enter the file name: ";
        cin >> filename;

        readProductsFromFile(filename, products);

        int choice;
        do {
            cout << "\nChoose an option:\n";
            cout << "1. Add a product\n";
            cout << "2. Delete a product\n";
            cout << "3. Edit product information\n";
            cout << "4. Sort by shop name\n";
            cout << "5. Sort by total price\n";
            cout << "6. Show products in a shop\n";
            cout << "7. Show products in a specified price range\n";
            cout << "8. Exit\n";
            cout << "Your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addProduct(products);
                break;
            case 2: {
                int index;
                cout << "Enter the index of the product you want to delete: ";
                cin >> index;
                deleteProduct(products, index);
                break;
            }
            case 3: {
                int index;
                cout << "Enter the index of the product you want to edit: ";
                cin >> index;
                editProduct(products, index);
                break;
            }
            case 4:
                sortByShop(products);
                break;
            case 5:
                sortByTotalPrice(products);
                break;
            case 6: {
                string shopName;
                cout << "Enter the shop name: ";
                cin >> shopName;
                displayProductsByShop(products, shopName);
                break;
            }
            case 7: {
                double minPrice, maxPrice;
                cout << "Enter the minimum price: ";
                cin >> minPrice;
                cout << "Enter the maximum price: ";
                cin >> maxPrice;
                displayProductsByPriceRange(products, minPrice, maxPrice);
                break;
            }
            case 8:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }

        } while (choice != 8);

        writeProductsToFile(filename, products);

        return 0;
    }


