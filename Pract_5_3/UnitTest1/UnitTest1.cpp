#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_5_3/Pract_5_3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = 2.0;
			double expected = (pow(cos(x), 2) + 1) / exp(x) * exp(x);

			double actual = s(x);


			Assert::AreEqual(expected, actual, 0.001);
		}
	};
}
