#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_8_1String/Pract_8_1String.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestChange)
		{
			// Arrange
			std::string str1 = "aaaabbbbccccdddd";
			std::string str2 = "aaaabbbb";
			std::string str3 = "aaaa";

			// Act
			Change(str1);
			Change(str2);
			Change(str3);

			// Assert
			Assert::AreEqual("********", str1.c_str());
			Assert::AreEqual("****", str2.c_str());
			Assert::AreEqual("**", str3.c_str());
		}
	};
}
