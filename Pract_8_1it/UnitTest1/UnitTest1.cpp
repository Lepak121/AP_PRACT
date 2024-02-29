#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>
#include "../Pract_8_1it/Pract_8_1it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


extern int CountQuadruplets(char* str);
extern char* ReplaceQuadruplets(char* str);

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountQuadruplets)
        {
            
            char str1[] = "aaaabbbb";
            char str2[] = "aabbccdd";
            char str3[] = "aaabbbb";
            char str4[] = "aabbbbbc";

            
            int count1 = CountQuadruplets(str1);
            int count2 = CountQuadruplets(str2);
            int count3 = CountQuadruplets(str3);
            int count4 = CountQuadruplets(str4);

           
            Assert::AreEqual(2, count1);
            Assert::AreEqual(0, count2);
            Assert::AreEqual(1, count3);
            Assert::AreEqual(2, count4);
        }

        TEST_METHOD(TestReplaceQuadruplets)
        {
            
            char str1[] = "aaaabbbb";
            char str2[] = "aabbccdd";
            char str3[] = "aaabbbb";
            char str4[] = "aabbbbbc";

          
            char* modifiedStr1 = ReplaceQuadruplets(str1);
            char* modifiedStr2 = ReplaceQuadruplets(str2);
            char* modifiedStr3 = ReplaceQuadruplets(str3);
            char* modifiedStr4 = ReplaceQuadruplets(str4);

            
            Assert::AreEqual(std::string("****"), std::string(modifiedStr1));
            Assert::AreEqual(std::string("aabbccdd"), std::string(modifiedStr2));
            Assert::AreEqual(std::string("aaa**"), std::string(modifiedStr3));
            Assert::AreEqual(std::string("aa**bc"), std::string(modifiedStr4));

            delete[] modifiedStr1;
            delete[] modifiedStr2;
            delete[] modifiedStr3;
            delete[] modifiedStr4;
        }
    };
}
