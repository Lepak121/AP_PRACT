#include "pch.h"
#include "CppUnitTest.h"
#include "../pract_5_2/pract_5_2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = 1;
			double eps = 0.0000001;
			int n = 0;
			double s = 0;
			double expected = atan(x);

			double actual = S(x, eps, n, s);

			Assert::AreEqual(expected, actual, eps);
		}
	};
}
