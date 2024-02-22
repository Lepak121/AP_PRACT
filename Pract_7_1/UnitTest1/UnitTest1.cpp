#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/ConsoleApplication1.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSortDescending)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                a[i] = new int[colCount];
            }

   
            a[0][0] = 3; a[0][1] = 2; a[0][2] = 1;
            a[1][0] = 6; a[1][1] = 5; a[1][2] = 4;
            a[2][0] = 9; a[2][1] = 8; a[2][2] = 7;

           
            int expected[3][3] = {
                {9, 8, 7},
                {6, 5, 4},
                {3, 2, 1}
            };

          
            Sort(a, rowCount, colCount);

           
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::AreEqual(a[i][j], expected[i][j]);
                }
            }

         
            for (int i = 0; i < rowCount; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}
