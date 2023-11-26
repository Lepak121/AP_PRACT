#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_6_3it/Pract_6_3it.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Pract_6_3itTests
{
    TEST_CLASS(IterativeTests)
    {
    public:

        TEST_METHOD(TestSortDescending)
        {
         
            const int arraySize = 5;
            int testArray1[arraySize] = { 3, 1, 4, 2, 5 };
            int testArray2[arraySize] = { 5, 4, 3, 2, 1 };

   
            sortDescending(testArray1, arraySize);
            sortDescending(testArray2, arraySize);

            for (int i = 0; i < arraySize - 1; ++i) {
                Assert::IsTrue(testArray1[i] >= testArray1[i + 1]); 
                Assert::IsTrue(testArray2[i] >= testArray2[i + 1]); 
            }
        }
    };
}
