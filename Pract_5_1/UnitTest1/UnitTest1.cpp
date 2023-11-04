#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_5_1/Pract_5_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a = 2;
			double b = 4;
			double c = 1;
			double result = (a * a + b * b - c * c);
			double one = g(a, b, c);
			Assert::AreEqual(result, one);
		}
	};
}

