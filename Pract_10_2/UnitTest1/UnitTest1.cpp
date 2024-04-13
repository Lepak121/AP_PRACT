#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_10_2/Pract_10_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCountWordsStartingWithB)
		{
			string text = "banana ball cat bat elephant";
			int expected = 3;
			int actual = countWordsStartingWithB(text);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCountWordsStartingWithB_NoWords)
		{
			string text = "apple orange grape"; 
			int expected = 0;
			int actual = countWordsStartingWithB(text);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCountWordsStartingWithB_EmptyText)
		{
			string text = ""; 
			int expected = 0;
			int actual = countWordsStartingWithB(text);
			Assert::AreEqual(expected, actual);
		}
	};
}
