#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_7_2rec/Pract_7_2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMinOnDiagonal)
		{
			
			const int N = 3; 
			int** testMatrix = new int* [N]; 

			
			for (int i = 0; i < N; i++)
			{
				testMatrix[i] = new int[N]; 
			
				for (int j = 0; j < N; j++)
				{
					testMatrix[i][j] = (i * N) + j + 1; 
				}
			}

			int minExpected = 3; 

	
			int minOnDiagonal = INT_MAX; 
			SearchMinOnDiagonal(testMatrix, N, 0, minOnDiagonal);

		
			Assert::AreEqual(minExpected, minOnDiagonal);

			for (int i = 0; i < N; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}

		
	};
}
