#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


struct Product {
    string name;
    string shop;
    double price;
    int quantity;
    string unit;
};


vector<Product> readProductsFromFile(const string& filename) {
    vector<Product> products;
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return products;
    }

    Product product;
    while (fin >> product.name >> product.shop >> product.price >> product.quantity >> product.unit) {
        products.push_back(product);
    }

    fin.close();
    return products;
}


void writeProductsToFile(const string& filename, const vector<Product>& products) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& product : products) {
        fout << product.name << " " << product.shop << " " << product.price << " " << product.quantity << " " << product.unit << endl;
    }

    fout.close();
}


void addProduct(vector<Product>& products) {
    Product newProduct;
    cout << "Enter product name: ";
    cin >> newProduct.name;
    cout << "Enter shop name: ";
    cin >> newProduct.shop;
    cout << "Enter price: ";
    cin >> newProduct.price;
    cout << "Enter quantity: ";
    cin >> newProduct.quantity;
    cout << "Enter unit: ";
    cin >> newProduct.unit;

    products.push_back(newProduct);
}


void displayProducts(const vector<Product>& products) {
    if (products.empty()) {
        cout << "No products found." << endl;
        return;
    }

    cout << "Products:" << endl;
    for (const auto& product : products) {
        cout << "Name: " << product.name << ", Shop: " << product.shop << ", Price: " << product.price
            << ", Quantity: " << product.quantity << " " << product.unit << endl;
    }
}


void displayProductsByShop(const vector<Product>& products, const string& shopName) {
    cout << "Products in shop '" << shopName << "':" << endl;
    bool found = false;
    for (const auto& product : products) {
        if (product.shop == shopName) {
            cout << "Name: " << product.name << ", Price: " << product.price
                << ", Quantity: " << product.quantity << " " << product.unit << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No products found in shop '" << shopName << "'." << endl;
    }
}


void displayProductsByPriceRange(const vector<Product>& products, double minPrice, double maxPrice) {
    cout << "Products within the price range $" << minPrice << " - $" << maxPrice << ":" << endl;
    bool found = false;
    for (const auto& product : products) {
        if (product.price >= minPrice && product.price <= maxPrice) {
            cout << "Name: " << product.name << ", Shop: " << product.shop
                << ", Quantity: " << product.quantity << " " << product.unit << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No products found within the specified price range." << endl;
    }
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    vector<Product> products = readProductsFromFile(filename);

    int choice;
    string shopName; 
    double minPrice, maxPrice; 
    do {
        cout << "\nMenu:\n"
            << "1. Add product\n"
            << "2. Display all products\n"
            << "3. Display products by shop\n"
            << "4. Display products by price range\n"
            << "5. Save and Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct(products);
            break;
        case 2:
            displayProducts(products);
            break;
        case 3:
            cout << "Enter shop name: ";
            cin >> shopName;
            displayProductsByShop(products, shopName);
            break;
        case 4:
            cout << "Enter minimum price: $";
            cin >> minPrice;
            cout << "Enter maximum price: $";
            cin >> maxPrice;
            displayProductsByPriceRange(products, minPrice, maxPrice);
            break;
        case 5:
            writeProductsToFile(filename, products);
            cout << "Products saved to file. Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}

