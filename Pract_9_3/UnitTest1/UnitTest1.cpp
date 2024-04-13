#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_9_3/Pract_9_3.cpp" 
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestAddProduct)
		{
			vector<Product> productList;

			istringstream testInput("TestProduct TestShop 25.5 10 pcs");
			cin.rdbuf(testInput.rdbuf()); 

			addProduct(productList);

			Assert::AreEqual(static_cast<size_t>(1), productList.size());
			Assert::AreEqual(string("TestProduct"), productList[0].name);
			Assert::AreEqual(string("TestShop"), productList[0].shop);
			Assert::AreEqual(25.5f, productList[0].price);
			Assert::AreEqual(10, productList[0].quantity);
			Assert::AreEqual(string("pcs"), productList[0].unit);
		}
	};
}
