#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_11_4/Pract_11_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSortByTotalPrice)
        {
            // Створюємо об'єкт класу, який буде містити тести
            vector<Product> products;
            products.push_back({ "Laptop", "Electronics Store", 1500.0, 10, "pcs" });
            products.push_back({ "Smartphone", "Electronics Store", 800.0, 20, "pcs" });
          

            // Сортуємо товари за загальною вартістю
            sortByTotalPrice(products);

            // Перевіряємо, чи товари відсортовані вірно
            Assert::AreEqual("Laptop", products[0].name.c_str());
            Assert::AreEqual("Smartphone", products[1].name.c_str());
          
        }
    };
}
