#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// �������� ��������� �����
			std::ofstream testFile("t.txt");
			Assert::IsTrue(testFile.is_open());
			testFile.close();

			// �������� �������� ����� ��� �������
			std::ifstream inputFile("t.txt");
			Assert::IsTrue(inputFile.is_open());
			inputFile.close();

			// �������� �������� ����� ��� ������ ����������
			std::ofstream resultFile("lg_arguments.txt");
			Assert::IsTrue(resultFile.is_open());
			resultFile.close();
		}
	};
}
