#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_6_1IM/Pract_6_1IM.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestApplyCriteria)
		{
			const int arraySize = 10;
			int array[arraySize];
			int sum = 0;
			int count = 0;

			int* result = applyCriteria(array, arraySize, sum, count);

	
			for (int i = 0; i < arraySize; i++) {
				if (array[i] > 0 && array[i] % 3 != 0) {
					Assert::AreEqual(result[i], 0);
				}
			}

	
			Assert::AreEqual(sum, 0);
			Assert::AreEqual(count, 0);
		}

	
	};
}
