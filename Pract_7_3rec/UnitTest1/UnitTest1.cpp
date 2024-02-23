#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_7_3rec/Pract_7_3rec.cpp" // Шлях до файлу з функціями

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSumBelowMainDiagonal)
		{
			const int size = 3;
			int** matrix = new int* [size];
			for (int i = 0; i < size; ++i) {
				matrix[i] = new int[size];
			}


			matrix[0][0] = 1; matrix[0][1] = -9; matrix[0][2] = -7;
			matrix[1][0] = 6; matrix[1][1] = -5; matrix[1][2] = -4;
			matrix[2][0] = -6; matrix[2][1] = 6; matrix[2][2] = -8;


			int expectedSum = 18; 


			int actualSum = SumBelowMainDiagonal(matrix, size);

			Assert::AreEqual(expectedSum, actualSum);


			for (int i = 0; i < size; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}
