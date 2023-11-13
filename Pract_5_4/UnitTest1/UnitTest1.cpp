#include "pch.h"
#include "CppUnitTest.h"
#include "../pract_5_4/pract_5_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
          
            int K = 4;
            int N = 6;
            double expected = 0.0;
            for (int i = K; i <= N; i++) {
                expected += pow(i, 2) / (pow(N, 2) + pow(K, 2));
            }

       
            Assert::AreEqual(S0(K, N), expected);

            int i = K;
            Assert::AreEqual(S1(K, N, i), expected);

            i = N;
            Assert::AreEqual(S2(K, N, i), expected);

            i = K;
            double t = 0.0;
            Assert::AreEqual(S3(K, N, i, t), expected);

            i = N;
            t = 0.0;
            Assert::AreEqual(S4(K, N, i, t), expected);
        }
    };
}
