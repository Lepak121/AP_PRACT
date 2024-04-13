#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_11_2/Pract_11_2.cpp" // Шлях до файлу з функціями, який потрібно протестувати

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountExcellentGrades)
		{
			vector<Student> studentsData;
			Student student1 = { "Smith", 2, COMPUTER_SCIENCE, 5, 5, {5} };
			Student student2 = { "Johnson", 3, INFORMATICS, 5, 5, {5} };
			Student student3 = { "Williams", 1, MATH_ECONOMICS, 3, 3, {3} };
			studentsData.push_back(student1);
			studentsData.push_back(student2);
			studentsData.push_back(student3);

			// Перевірка кількості відмінних оцінок з фізики (оцінка 90)
			Assert::AreEqual(0, countExcellentGrades(studentsData, 90));

			// Перевірка кількості відмінних оцінок з математики (оцінка 85)
			Assert::AreEqual(0, countExcellentGrades(studentsData, 85));

			// Перевірка кількості відмінних оцінок з фізики та математики (оцінки 95 та 90)
			Assert::AreEqual(0, countExcellentGrades(studentsData, 95));
		}
	};
}
