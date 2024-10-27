#include "pch.h"
#include "CppUnitTest.h"
#include <bitset>
#include "../PDS_2/PDS_2.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestLogicalOperations)
        {
            bool p, q;

            // ���������� ������� ��������
            p = true;
            q = false;

            // �������� ����������
            bool expectedAnd = p && q; // true && false = false
            bool expectedOr = p || q;  // true || false = true
            bool expectedXor = p ^ q;  // true ^ false = true
            bool expectedImplication = !p || q; // !true || false = false
            bool expectedEquivalence = (p && q) || (!p && !q); // (true && false) || (!true && !false) = false || true = true

            // �������� ����������
            Assert::AreEqual(expectedAnd, false);
            Assert::AreEqual(expectedOr, true);
            Assert::AreEqual(expectedXor, true);
            Assert::AreEqual(expectedImplication, false);
            Assert::AreEqual(expectedEquivalence, false); // ��� ��������� true
        }

        
    };
}