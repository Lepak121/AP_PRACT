#include "pch.h"
#include "CppUnitTest.h"
#include "../Pract_10_4/Pract_10_4.cpp" // Замініть "YourFileName.cpp" на назву вашого файлу з програмою
#include <map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestCalculateMaxPrices)
		{
			// Arrange
			map<string, vector<Car>> testData = {
				{ "FirmA", { { "ModelA", 10000 }, { "ModelB", 15000 }, { "ModelC", 12000 } } },
				{ "FirmB", { { "ModelD", 20000 }, { "ModelE", 18000 }, { "ModelF", 22000 } } },
				{ "FirmC", { { "ModelG", 25000 }, { "ModelH", 23000 }, { "ModelI", 24000 } } }
			};

			map<string, double> expectedResults = {
				{ "FirmA", 15000 },
				{ "FirmB", 22000 },
				{ "FirmC", 25000 }
			};

			// Act
			map<string, double> actualResults = calculateMaxPrices(testData);

			// Assert
			for (const auto& entry : expectedResults) {
				Assert::AreEqual(actualResults[entry.first], entry.second);
			}
		}
	};
}
