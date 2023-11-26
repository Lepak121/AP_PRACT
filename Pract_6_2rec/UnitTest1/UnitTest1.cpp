#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_6_2rec/Pract_6_2rec.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Pract_6_2recTests
{
    TEST_CLASS(RecursiveTests)
    {
    public:

        TEST_METHOD(TestFindIndexOfMinOddRecursive)
        {
         
        vector<int> testVector1 = { 2, 7, 1, 9, 4, 6, 5 };
        vector<int> testVector2 = { 2, 4, 6, 8, 10 };

     
            int resultIndex1 = findIndexOfMinOddRecursive(testVector1, 0, -1);
            int resultIndex2 = findIndexOfMinOddRecursive(testVector2, 0, -1);

   
            Assert::AreEqual(2, resultIndex1);
            Assert::AreEqual(-1, resultIndex2); 
        }
    };
}
