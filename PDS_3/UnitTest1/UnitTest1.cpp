#include "pch.h" // ��� ��� �����, � ��������� �� �����������
#include "../PDS_3/PDS_3.cpp" // ������������ ����, �� ������ ���������� �������
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyProjectTests
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestArrangements) {
            Assert::AreEqual(arrangements(6, 5), 720ull);
            // �������� �����...
        }

        TEST_METHOD(TestBellNumbers) {
            int n = 5;
            vector<vector<unsigned long long>> F = generate_stirling_table(n);
            vector<unsigned long long> B = bell_numbers(n, F);
            Assert::AreEqual(B[n], 18ull);
        }
    };
}
