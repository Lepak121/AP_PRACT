#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_9_1B/Pract_9_1B.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Pract_9_1B_UnitTest
{
    TEST_CLASS(Pract_9_1B_Test)
    {
    public:
    
     
        TEST_METHOD(TestPrintStudents)
        {
            Student students[2];

            students[0].lastName = "Doe";
            students[0].course = 3;
            students[0].specialty = COMPUTER_SCIENCE;
            students[0].physicsGrade = 80;
            students[0].mathGrade = 75;
            students[0].additionalGrade.programming = 90;

            students[1].lastName = "Smith";
            students[1].course = 2;
            students[1].specialty = INFORMATICS;
            students[1].physicsGrade = 85;
            students[1].mathGrade = 70;
            students[1].additionalGrade.numericalMethods = 85;

            std::ostringstream outputStream;
            printStudents(students, 2);
            std::string output = outputStream.str();

       
        }
    };
}
