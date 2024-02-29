#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_8_2/Pract_8_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountWordsStartingWithB)
		{
			
			string str1 = "bottle book banana apple";
			string str2 = "Bat ball boy";

			size_t count1 = CountWordsStartingWithB(str1);
			size_t count2 = CountWordsStartingWithB(str2);

		
			Assert::AreEqual(size_t(3), count1); 
			Assert::AreEqual(size_t(3), count2); 
		}
	};
}
