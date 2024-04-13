#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_9_2B/Pract_9_2B.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCompareStudentsDifferentAverageGrade)
        {

            Student studentA;
            studentA.averageGrade = 90;
            studentA.specialty = "Computer Science";
            studentA.lastName = "Smith";

            Student studentB;
            studentB.averageGrade = 80;
            studentB.specialty = "Informatics";
            studentB.lastName = "Johnson";

            Assert::IsTrue(compareStudents(studentA, studentB));
            Assert::IsFalse(compareStudents(studentB, studentA));
        }
    };
}
