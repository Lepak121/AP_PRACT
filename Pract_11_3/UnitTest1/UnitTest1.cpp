#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_11_3/Pract_11_3.cpp" // ������ ���� �� ������ ����� � �����

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestBinarySearch)
		{
			// Arrange
			vector<Student> students;
			Student student1;
			student1.lastName = "Smith";
			student1.specialty = "Computer Science";
			student1.averageGrade = 85.0;
			Student student2;
			student2.lastName = "Johnson";
			student2.specialty = "Informatics";
			student2.averageGrade = 75.5;
			students.push_back(student1);
			students.push_back(student2);

			// Act
			bool result1 = binarySearch(students, "Smith", "Computer Science", 85.0);
			bool result2 = binarySearch(students, "Johnson", "Informatics", 75.5);
			bool result3 = binarySearch(students, "Doe", "Computer Science", 90.0);

			// Assert
			Assert::IsTrue(result1); // ��������� ������� ����� ��� �������� Smith � Computer Science � ������� ����� 85.0
			Assert::IsTrue(result2); // ��������� ������� ����� ��� �������� Johnson � Informatics � ������� ����� 75.5
			Assert::IsFalse(result3); // ��������� ������� ����� ��� �������� Doe � Computer Science � ������� ����� 90.0
		}
	};
}
