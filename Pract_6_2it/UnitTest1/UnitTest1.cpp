#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_6_2it/Pract_6_2it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(YourTests)
    {
    public:

        TEST_METHOD(TestFindIndexOfMinOdd)
        {
            
            vector<int> testVector1 = { 2, 7, 1, 9, 4, 6, 5 };
            vector<int> testVector2 = { 2, 4, 6, 8, 10 };

           
            int resultIndex1 = findIndexOfMinOdd(testVector1);
            int resultIndex2 = findIndexOfMinOdd(testVector2);

           
            Assert::AreEqual(2, resultIndex1); 
            Assert::AreEqual(-1, resultIndex2); 
        }
    };
}
