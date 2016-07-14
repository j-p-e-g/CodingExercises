#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CodingExercises/Exercise4.cpp"
#include "../CodingExercises/Exercise18.cpp"
#include "../CodingExercises/Exercise25.cpp"
#include "../CodingExercises/Exercise28.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCodingExercises
{		
	TEST_CLASS(ExercisesTest)
	{
	public:
		
		TEST_METHOD(Exercise04_CalculateSum_Test)
		{
			{
				Exercise4 *ex = new Exercise4();
				const std::vector<int> numbers = {};
				const int expectedSum = 0;
				const int sum = ex->calculateSum(numbers);
				Assert::AreEqual(expectedSum, ex->calculateSum(numbers), L"Wrong result for sum of numbers");
			}
			{
				Exercise4 *ex = new Exercise4();
				const std::vector<int> numbers = { 1, 2, 3, 2, 5, 4 };
				const int expectedSum = 17;
				Assert::AreEqual(expectedSum, ex->calculateSum(numbers), L"Wrong result for sum of numbers");
			}
			{
				Exercise4 *ex = new Exercise4();
				const std::vector<int> numbers = {3, -2, 8, -10, 1};
				const int expectedSum = 0;
				Assert::AreEqual(expectedSum, ex->calculateSum(numbers), L"Wrong result for sum of numbers");
			}
		}

		TEST_METHOD(Exercise18_CompareTriangles_Test)
		{
			const int NUM = 3;
			Exercise18* ex = new Exercise18();
			const std::string triangleString = ex->createTriangleString(NUM);
			const std::string expectedString = "***\n**\n*\n";

			Assert::AreEqual(expectedString, triangleString, L"The triangle doesn't match the expected string");
		}

		TEST_METHOD(Exercise25_CalculateExponential_Test)
		{
			Exercise25* ex = new Exercise25();
			const float result = ex->calculateExponential(2.5, 3);
			const float expectedResult = 15.625;
			const float roundingError = 0.0001;
			Assert::AreEqual(expectedResult, result, roundingError, L"Exponential was calculated wrongly");
		}

		TEST_METHOD(Exercise25_CalculateExponentialGrowth_Test)
		{
			Exercise25* ex = new Exercise25();
			const int result = ex->calculateExponentialGrowth(15000, 0.01, 3);
			const int expectedResult = 15454;
			Assert::AreEqual(expectedResult, result, L"Exponential growth was calculated wrongly");
		}

		TEST_METHOD(Exercise25_CalculateTimeWhenAExceedsBDueToExponentialGrowth_Test)
		{
			Exercise25* ex = new Exercise25();
			long unused;
			const int result = ex->calculateTimeWhenAExceedsB(900, 0.05, 1000, 0.01, unused, unused);
			const int expectedResult = 3;
			Assert::AreEqual(expectedResult, result, L"Calculated time different than expected");
		}

		TEST_METHOD(Exercise28_GetNumberOfCharOccurencesInString_Test)
		{
			{
				Exercise28* ex = new Exercise28();
				const int num = ex->countNumberOfOccurencesInString("banana", 'a');
				const int expectedResult = 3;
				Assert::AreEqual(expectedResult, num, L"Wrong number of occurences returned");
			}
			{
				Exercise28* ex = new Exercise28();
				const int num = ex->countNumberOfOccurencesInString("kayak", 'k');
				const int expectedResult = 2;
				Assert::AreEqual(expectedResult, num, L"Wrong number of occurences returned");
			}
			{
				Exercise28* ex = new Exercise28();
				const int num = ex->countNumberOfOccurencesInString("running", 'n');
				const int expectedResult = 3;
				Assert::AreEqual(expectedResult, num, L"Wrong number of occurences returned");
			}
		}
	};
}