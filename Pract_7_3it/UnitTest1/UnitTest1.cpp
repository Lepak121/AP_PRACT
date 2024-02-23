#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_7_3it/Pract_7_3it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSumBelowMainDiagonal)
        {
           
            const int rowCount = 3;
            const int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i) {
                matrix[i] = new int[colCount];
            }

           
            matrix[0][0] = -4; matrix[0][1] = 1; matrix[0][2] = 4;
            matrix[1][0] = -6; matrix[1][1] = 2; matrix[1][2] = 4;
            matrix[2][0] = 5; matrix[2][1] = -3; matrix[2][2] = 4;

          
            int result = SumBelowMainDiagonal(matrix, rowCount, colCount);

     
            Assert::AreEqual(9, result);

          
            for (int i = 0; i < rowCount; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };
}
