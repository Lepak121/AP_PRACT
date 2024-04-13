#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_10_1/Pract_10_1.cpp" // Замініть "YourProjectName" на назву вашого проекту та відповідний шлях до файлу main.cpp

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestHasQuadruple)
		{
			// Підготовка тестових даних
			string testString = "aaabbbbcccdddd"; // Стрічка, в якій є квадруплети "bbbb" і "dddd"

			// Виклик функції для перевірки
			bool result = hasQuadruple(testString);

			// Перевірка результату
			Assert::IsTrue(result, L"TThe file contains a quadruple of consecutive identical characters.");



			
		}
	};
}
