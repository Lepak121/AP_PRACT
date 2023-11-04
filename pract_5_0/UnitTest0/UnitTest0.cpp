#include "pch.h"
#include "CppUnitTest.h"
#include "../pract_5_0/pract_5_0.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0
{
	TEST_CLASS(UnitTest0)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = sum(2, 3);
			Assert::AreEqual(t, 5);
		}
	};
}
