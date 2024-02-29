#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_8_1Char/Pract_8_1Char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCount)
        {
           
            char str1[] = "aaaabbbbccccdddd";
            char str2[] = "abcdabcdabcdabcd";
          

      
            int count1 = Count(str1);
            int count2 = Count(str2);
            

          
            Assert::AreEqual(4, count1); 
            Assert::AreEqual(0, count2); 
           
        }

   
    };
}
