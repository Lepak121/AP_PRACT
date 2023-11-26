#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_6_4it/Pract_6_4it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestFindMaxIndex)
		{
			const int size = 5;
			int array[size] = { 3, 8, 1, 5, 6 };

			int maxIndex = findMaxIndex(array, size);

			Assert::AreEqual(1, maxIndex);
		}

		TEST_METHOD(TestFindProductBetweenZeros)
		{
			const int size = 8;
			int array[size] = { 2, 4, 0, 7, 1, 0, 3, 6 };

			int product = findProductBetweenZeros(array, size);

			Assert::AreEqual(7, product); 
		}
	};
}
