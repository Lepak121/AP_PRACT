#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_10_1/Pract_10_1.cpp" // ������ "YourProjectName" �� ����� ������ ������� �� ��������� ���� �� ����� main.cpp

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestHasQuadruple)
		{
			// ϳ�������� �������� �����
			string testString = "aaabbbbcccdddd"; // ������, � ��� � ����������� "bbbb" � "dddd"

			// ������ ������� ��� ��������
			bool result = hasQuadruple(testString);

			// �������� ����������
			Assert::IsTrue(result, L"TThe file contains a quadruple of consecutive identical characters.");



			
		}
	};
}
