#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_8_1rec/Pract_8_1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCount)
		{
		
			std::string str1 = "aabbccdd";
			std::string str2 = "abcdabcd";
			std::string str3 = "aaaabbbb";

		
			int count1 = Count(str1, 0);
			int count2 = Count(str2, 0);
			int count3 = Count(str3, 0);

			Assert::AreEqual(0, count1); 
			Assert::AreEqual(0, count2); 
			Assert::AreEqual(2, count3); 
		}

		TEST_METHOD(TestChange)
		{
		
			std::string str1 = "aabbccdd";
			std::string str2 = "abcdabcd";
			std::string str3 = "aaaabbbb";

		
			std::string modifiedStr1 = Change(str1, 0);
			std::string modifiedStr2 = Change(str2, 0);
			std::string modifiedStr3 = Change(str3, 0);

	
			Assert::AreEqual(std::string("aabbccdd"), modifiedStr1);
			Assert::AreEqual(std::string("abcdabcd"), modifiedStr2);
			Assert::AreEqual(std::string("****"), modifiedStr3);
		}
	};
}
