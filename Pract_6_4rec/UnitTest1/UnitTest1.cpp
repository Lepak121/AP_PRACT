#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_6_4rec/Pract_6_4rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestFindMaxIndexRecursive)
		{
			const int size = 5;
			int array[size] = { 3, 8, 1, 5, 6 };

			int maxIndex = findMaxIndexRecursive(array, size);

			Assert::AreEqual(1, maxIndex);
		}

		TEST_METHOD(TestFindProductBetweenZerosRecursive)
		{
			const int size = 8;
			int array[size] = { 2, 4, 0, 7, 1, 0, 3, 6 };

			int product = findProductBetweenZerosRecursive(array, size);

			Assert::AreEqual(7, product);
		}

		// Додайте інші тести за потреби

	};
}
