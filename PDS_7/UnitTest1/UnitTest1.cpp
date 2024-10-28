#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <fstream>
#include <sstream>
#include "../PDS_7/PDS_7.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestReadGraph)
        {
            const std::string testFilename = "test_graph.txt";


            {
                std::ofstream file(testFilename);
                file << "0 1 0\n";
                file << "1 0 1\n";
                file << "0 1 0\n";
                file.close();
            }


            std::vector<std::vector<int>> expectedGraph = {
                {0, 1, 0},
                {1, 0, 1},
                {0, 1, 0}
            };


            auto graph = readGraph(testFilename);


            Assert::AreEqual(expectedGraph.size(), graph.size());
            for (size_t i = 0; i < expectedGraph.size(); ++i) {
                Assert::AreEqual(expectedGraph[i].size(), graph[i].size());
                for (size_t j = 0; j < expectedGraph[i].size(); ++j) {
                    Assert::AreEqual(expectedGraph[i][j], graph[i][j]);
                }
            }
        }

        TEST_METHOD(TestCalculateDegrees)
        {

            std::vector<std::vector<int>> graph = {
                {0, 1, 0},
                {1, 0, 1},
                {0, 1, 0}
            };

            std::stringstream buffer;
            std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

            calculateDegrees(graph);

            std::cout.rdbuf(prevcoutbuf);

            std::string output = buffer.str();
            std::string expectedOutput =
                "������ ������ ����� (������/������):\n"
                "������� 1: �������� ������ = 1, ������� ������ = 1\n"
                "������� 2: �������� ������ = 2, ������� ������ = 2\n"
                "������� 3: �������� ������ = 1, ������� ������ = 1\n"
                "���� �� � ���������.\n";

            Assert::AreEqual(expectedOutput, output);
        }

        TEST_METHOD(TestFindPendantAndIsolatedVertices)
        {

            std::vector<std::vector<int>> graph = {
                {0, 1, 0},
                {1, 0, 1},
                {0, 1, 0}
            };

            std::stringstream buffer;
            std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

            findPendantAndIsolatedVertices(graph);

            std::cout.rdbuf(prevcoutbuf);

            std::string output = buffer.str();
            std::string expectedOutput =
                "������ �������: 1 3 \n"
                "��������� �������: ����\n";

            Assert::AreEqual(expectedOutput, output);
        }
    };
}