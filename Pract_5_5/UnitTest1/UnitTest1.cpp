#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_5_5/Pract_5_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(BinomTest)
    {
    public:

        TEST_METHOD(PositiveBinomTest)
        {
            const int n = 5;
            const int k = 3;

            Assert::AreEqual(binom(n, k), 10);
        }

        TEST_METHOD(NegativeBinomTest)
        {
            const int n = 5;
            const int k = 6;

            Assert::AreEqual(binom(n, k), 0);
        }
      

        TEST_METHOD(NegativeBinomDepthTest)
        {
            const int n = 5;
            const int k = 6;

            Assert::AreEqual(binom_depth(n, k), 0);
        }
    };
}
