#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_6_1rec/Pract_6_1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestInitializeArray)
        {
            const int arraySize = 22;
            int array[arraySize];
            initializeArray(array, 0, arraySize);

            for (int i = 0; i < arraySize; i++) {
                Assert::IsTrue(array[i] >= -10 && array[i] <= (35 + 10));
            }
        }

        TEST_METHOD(TestApplyCriteria)
        {
            const int size = 22;
            int array[size];
            int sum = 0;
            int count = 0;
            initializeArray(array, 0, size);
            applyCriteria(array, 0, size, count, sum);

            for (int i = 0; i < size; i++) {
                if (array[i] > 0 && array[i] % 3 != 0) {
                    Assert::AreEqual(array[i], 0);
                }
            }
        }
    };
}
