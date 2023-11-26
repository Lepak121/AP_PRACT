#include "pch.h"
#include "CppUnitTest.h"
#include "../pract_6_3rec/pract_6_3rec.cpp" 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pract_6_3recTests
{
    TEST_CLASS(RecursiveTests)
    {
    public:

        TEST_METHOD(TestSortDescendingRecursive)
        {

            const int arraySize = 5;
            int testArray1[arraySize] = { 3, 1, 4, 2, 5 };
            int testArray2[arraySize] = { 5, 4, 3, 2, 1 };

            sortDescendingRecursive(testArray1, 0, arraySize - 1);
            sortDescendingRecursive(testArray2, 0, arraySize - 1);

    
            for (int i = 0; i < arraySize - 1; ++i) {
                Assert::IsTrue(testArray1[i] >= testArray1[i + 1]); 
                Assert::IsTrue(testArray2[i] >= testArray2[i + 1]); 
            }
        }
    };
}