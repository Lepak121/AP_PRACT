#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_10_3/Pract_10_3.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestDisplayProducts)
		{

			std::ostringstream outputStream;
			std::streambuf* oldOutput = std::cout.rdbuf();
			std::cout.rdbuf(outputStream.rdbuf()); 

			std::vector<Product> products;
			products.push_back({ "Product1", "Shop1", 10.5, 20, "kg" });
			products.push_back({ "Product2", "Shop2", 15.7, 30, "units" });

			std::string expectedOutput = "Products:\n";
			expectedOutput += "Name: Product1, Shop: Shop1, Price: 10.5, Quantity: 20 kg\n";
			expectedOutput += "Name: Product2, Shop: Shop2, Price: 15.7, Quantity: 30 units\n";

		
			displayProducts(products);

		
			std::cout.rdbuf(oldOutput);

		
			Assert::AreEqual(expectedOutput, outputStream.str());
		}
	};
}
