#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CodingExercises/PermutationChallenge.cpp"
#include "../CodingExercises/LinkedListReversalChallenge.cpp"
#include "../CodingExercises/NumberToEnglishConversionChallenge.cpp"
#include "../CodingExercises/WildcardStringSearchingChallenge.cpp"
#include "../CodingExercises/SubArraySumChallenge.cpp"
#include "../CodingExercises/FactorialTrailingZeroesChallenge.cpp"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCodingExercises
{
	class HelperClass
	{
	public:
		static HelperClass& getInstance()
		{
			static HelperClass* m_instance(new HelperClass());
			return *m_instance;
		}

		void compareIntVectors(const std::vector<int> &i_vecA, const std::vector<int> &i_vecB) const
		{
			Assert::AreEqual(i_vecA.size(), i_vecB.size(), L"Wrong size of vector");
			for (size_t k = 0; k < i_vecA.size(); k++)
			{
				Assert::AreEqual(i_vecA[k], i_vecB[k], L"Wrong vector element");
			}
		}

		void compareStringVectors(const std::vector<std::string> &i_vecA, const std::vector<std::string> &i_vecB) const
		{
			Assert::AreEqual(i_vecA.size(), i_vecB.size(), L"Wrong size of vector");
			for (size_t k = 0; k < i_vecA.size(); k++)
			{
				Assert::AreEqual(i_vecA[k], i_vecB[k], L"Wrong vector element");
			}
		}
	};

	TEST_CLASS(ChallengesTest)
	{
	public:
		TEST_METHOD(PermutationChallenge_GetAllPermutations_Test)
		{
			{
				PermutationChallenge *challenge = new PermutationChallenge();
				std::vector<std::string> permutations = challenge->getAllPermutations("cat");

				// make sure both are sorted alphabetically
				std::sort(permutations.begin(), permutations.end());
				const std::vector<std::string> expectedPermutations = { "act", "atc", "cat", "cta", "tac", "tca" };

				Assert::AreEqual(expectedPermutations.size(), permutations.size(), L"Wrong number of found permutations");
				for (size_t k = 0; k < expectedPermutations.size(); k++)
				{
					Assert::AreEqual(expectedPermutations[k], permutations[k], L"Different permutation entries");
				}
			}
		}

		TEST_METHOD(PermutationChallenge_GetAllPermutationsWithoutIndices_Test)
		{
			{
				PermutationChallenge *challenge = new PermutationChallenge();
				std::vector<std::string> permutations = challenge->getAllPermutationsWithoutIndices("cat");

				// make sure both are sorted alphabetically
				std::sort(permutations.begin(), permutations.end());
				const std::vector<std::string> expectedPermutations = { "act", "atc", "cat", "cta", "tac", "tca" };

				Assert::AreEqual(expectedPermutations.size(), permutations.size(), L"Wrong number of found permutations");
				for (size_t k = 0; k < expectedPermutations.size(); k++)
				{
					Assert::AreEqual(expectedPermutations[k], permutations[k], L"Different permutation entries");
				}
			}
		}

		TEST_METHOD(PermutationChallenge_GetSinglePermutation_Test)
		{
			PermutationChallenge* challenge = new PermutationChallenge();
			const std::vector<int> indices = { 1,2,0,1,0 };
			const std::string permutation = challenge->getSinglePermutation("dummy", indices);
			const std::string expectedPermutation = "umdym";
			Assert::AreEqual(expectedPermutation, permutation, L"Returned permutation differs");
		}

		TEST_METHOD(PermutationChallenge_GetAllIndexPermutations_Test)
		{
			{
				PermutationChallenge *challenge = new PermutationChallenge();
				std::vector<std::vector<int>> permutations = challenge->getAllIndexPermutations(3);

				// make sure both are sorted alphabetically
				std::sort(permutations.begin(), permutations.end());
				std::vector<std::vector<int>> expectedPermutations;
				expectedPermutations.push_back({ 0,0,0 });
				expectedPermutations.push_back({ 0,1,0 });
				expectedPermutations.push_back({ 1,0,0 });
				expectedPermutations.push_back({ 1,1,0 });
				expectedPermutations.push_back({ 2,0,0 });
				expectedPermutations.push_back({ 2,1,0 });

				Assert::AreEqual(expectedPermutations.size(), permutations.size(), L"Wrong number of found permutations");

				for (size_t k = 0; k < expectedPermutations.size(); k++)
				{
					const std::vector<int> expectedIndices = expectedPermutations[k];
					std::vector<int> indices = permutations[k];

					Assert::AreEqual(expectedIndices.size(), indices.size(), L"Different number of indices");
					
					for (size_t j = 0; j < indices.size(); j++)
					{
						Assert::AreEqual(expectedIndices[j], indices[j], L"Different permutation entries");
					}
				}
			}
		}

		TEST_METHOD(StressTest_PermutationChallenge)
		{
			PermutationChallenge* challenge = new PermutationChallenge();
			challenge->getAllPermutations("LongTest");
		}

		TEST_METHOD(StressTest_PermutationChallengeWithoutIndices)
		{
			PermutationChallenge* challenge = new PermutationChallenge();
			challenge->getAllPermutations("LongTest");
		}

		// these three methods are hard to test on their own
		TEST_METHOD(LinkedListReversalChallenge_addNodeGetSizeGetValues)
		{
			SingleLinkedList* list = new SingleLinkedList();
			const std::vector<int> expectedValues = { 3, 2, 5, 1 };
			for (std::vector<int>::const_iterator it = expectedValues.begin(), end = expectedValues.end(); it != end; it++)
			{
				list->addNode(new ListNode(*it));
			}

			const int size = list->getSize();
			const std::vector<int> values = list->getValues();

			Assert::AreEqual((int) expectedValues.size(), size, L"Created list has wrong size");
			Assert::AreEqual(expectedValues.size(), values.size(), L"Created list has wrong size");
			for (size_t k = 0; k < expectedValues.size(); k++)
			{
				Assert::AreEqual(expectedValues[k], values[k], L"Linked list contains wrong elements");
			}
		}

		TEST_METHOD(LinkedListReversalChallenge_getPredecessor_Test)
		{
			SingleLinkedList* list = new SingleLinkedList();
			ListNode* nodeA = new ListNode(1);
			ListNode* nodeB = new ListNode(2);
			ListNode* nodeC = new ListNode(3);
			list->addNode(nodeA);
			list->addNode(nodeB);

			Assert::IsTrue(nodeA == list->getPredecessor(*nodeB), L"Predecessor doesn't match");
			Assert::IsTrue(NULL == list->getPredecessor(*nodeA), L"Predecessor doesn't match");
		}

		TEST_METHOD(LinkedListReversalChallenge_getReversedValues_Test)
		{
			SingleLinkedList* list = new SingleLinkedList();
			const std::vector<int> expectedValues = { 3, 2, 5, 1 };
			for (int k = (int)expectedValues.size() - 1; k >= 0; k--)
			{
				list->addNode(new ListNode(expectedValues[k]));
			}

			const std::vector<int> values = list->getReversedValues();

			Assert::AreEqual(expectedValues.size(), values.size(), L"Inverted values vector has wrong size");
			for (size_t k = 0; k < expectedValues.size(); k++)
			{
				Assert::AreEqual(expectedValues[k], values[k], L"Inverted values vector contains wrong elements");
			}
		}

		TEST_METHOD(LinkedListReversalChallenge_getReversedValuesRecursion_Test)
		{
			SingleLinkedList* list = new SingleLinkedList();
			const std::vector<int> expectedValues = { 3, 2, 5, 1 };
			for (int k = (int)expectedValues.size() - 1; k >= 0; k--)
			{
				list->addNode(new ListNode(expectedValues[k]));
			}

			std::vector<int> values;
			list->getReversedValuesRecursion(values, list->getFirst());

			Assert::AreEqual(expectedValues.size(), values.size(), L"Inverted values vector has wrong size");
			for (size_t k = 0; k < expectedValues.size(); k++)
			{
				Assert::AreEqual(expectedValues[k], values[k], L"Inverted values vector contains wrong elements");
			}
		}

		TEST_METHOD(LinkedListReversalChallenge_inplaceReversal_Test)
		{
			SingleLinkedList* list = new SingleLinkedList();
			const std::vector<int> initialValues = { 3, 2, 5, 1 };
			for (int k = 0; k < (int)initialValues.size(); k++)
			{
				list->addNode(new ListNode(initialValues[k]));
			}
			const std::vector<int> reversedValues = list->getReversedValues();

			list->reverseListInPlace();
			const std::vector<int> values = list->getValues();

			Assert::AreEqual(reversedValues.size(), values.size(), L"Inverted list has wrong size");
			for (size_t k = 0; k < reversedValues.size(); k++)
			{
				Assert::AreEqual(reversedValues[k], values[k], L"Inverted list contains wrong elements");
			}
		}

		TEST_METHOD(NumberToEnglishConversionChallenge_describeNumber_Test)
		{
			NumberToEnglishConversionChallenge* challenge = new NumberToEnglishConversionChallenge();
			Assert::AreEqual("zero", challenge->describeNumber(0).c_str(), L"Number description doesn't match");
			Assert::AreEqual("twelve", challenge->describeNumber(12).c_str(), L"Number description doesn't match");
			Assert::AreEqual("eighteen thousand", challenge->describeNumber(18000).c_str(), L"Number description doesn't match");
			Assert::AreEqual("minus two million", challenge->describeNumber(-2000000).c_str(), L"Number description doesn't match");
			Assert::AreEqual("minus one hundred fifty-nine", challenge->describeNumber(-159).c_str(), L"Number description doesn't match");
			Assert::AreEqual("sixty-two thousand one hundred and eight", challenge->describeNumber(62108).c_str(), L"Number description doesn't match");
			Assert::AreEqual("seven million two hundred eighteen thousand three hundred ninety-nine", challenge->describeNumber(7218399).c_str(), L"Number description doesn't match");
		}

		TEST_METHOD(NumberToEnglishConversionChallenge_getDoubleDigitDescription_Test)
		{
			NumberToEnglishConversionChallenge* challenge = new NumberToEnglishConversionChallenge();
			Assert::AreEqual("twelve", challenge->getDoubleDigitDescription(12).c_str(), L"Number description doesn't match");
			Assert::AreEqual("fifty-nine", challenge->getDoubleDigitDescription(59).c_str(), L"Number description doesn't match");
			Assert::AreEqual("eighty", challenge->getDoubleDigitDescription(80).c_str(), L"Number description doesn't match");
		}

		TEST_METHOD(NumberToEnglishConversionChallenge_getTripleDigitDescription_Test)
		{
			NumberToEnglishConversionChallenge* challenge = new NumberToEnglishConversionChallenge();
			Assert::AreEqual("one hundred and two", challenge->getTripleDigitDescription(102).c_str(), L"Number description doesn't match");
			Assert::AreEqual("two hundred fifty-nine", challenge->getTripleDigitDescription(259).c_str(), L"Number description doesn't match");
			Assert::AreEqual("eight hundred seventy", challenge->getTripleDigitDescription(870).c_str(), L"Number description doesn't match");
		}

		TEST_METHOD(NumberToEnglishConversionChallenge_handleNegativeNumbers_Test)
		{
			NumberToEnglishConversionChallenge* challenge = new NumberToEnglishConversionChallenge();
			Assert::AreEqual("minus one hundred and two", challenge->handleNegativeNumber(-102).c_str(), L"Number description doesn't match");
			Assert::AreEqual("two hundred fifty-nine", challenge->handleNegativeNumber(259).c_str(), L"Number description doesn't match");
			Assert::AreEqual("minus seventy", challenge->handleNegativeNumber(-70).c_str(), L"Number description doesn't match");
		}

		TEST_METHOD(WildcardStringSearchingChallenge_findSubstringNoWildcards_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			Assert::IsTrue(challenge->isPatternInString("banana", "ana"), L"Existing pattern wasn't found");
			Assert::IsFalse(challenge->isPatternInString("banana", "baa"), L"Found non-existing pattern");
			Assert::IsTrue(challenge->isPatternInString("ananas", "anas"), L"Existing pattern wasn't found");
		}

		TEST_METHOD(WildcardStringSearchingChallenge_findSubstringWithWildcards_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			Assert::IsTrue(challenge->isPatternInString("banana", "*"), L"Plain wildcard wasn't found");
			Assert::IsTrue(challenge->isPatternInString("banana", "*ba"), L"Wildcard pattern at string start wasn't found");
			Assert::IsTrue(challenge->isPatternInString("banana", "b*a"), L"Existing wildcard pattern wasn't found");
			Assert::IsTrue(challenge->isPatternInString("banana", "nana*"), L"Wildcard pattern at string end wasn't found");
			Assert::IsTrue(challenge->isPatternInString("banana", "a*a*a"), L"Multi-wildcard pattern wasn't found");
			Assert::IsFalse(challenge->isPatternInString("banana", "a*ba*a"), L"Found non-existing wildcard pattern");
		}

		TEST_METHOD(WildcardStringSearchingChallenge_splitPattern_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			{
				const std::vector<std::string> expectedSplits = { "ba" };
				const std::vector<std::string> splits = challenge->splitPattern("ba");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { };
				const std::vector<std::string> splits = challenge->splitPattern("*");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "b" };
				const std::vector<std::string> splits = challenge->splitPattern("*b");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "b" };
				const std::vector<std::string> splits = challenge->splitPattern("b*");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "b" };
				const std::vector<std::string> splits = challenge->splitPattern("*b");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "b", "a" };
				const std::vector<std::string> splits = challenge->splitPattern("b*a");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = {"b", "a"};
				const std::vector<std::string> splits = challenge->splitPattern("b***a");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
		}

		TEST_METHOD(WildcardStringSearchingChallenge_splitPatternEscapedWildcards_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			{
				const std::vector<std::string> expectedSplits = { "b*a" };
				const std::vector<std::string> splits = challenge->splitPattern("b\\*a");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "*ba" };
				const std::vector<std::string> splits = challenge->splitPattern("\\*ba");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "ba*" };
				const std::vector<std::string> splits = challenge->splitPattern("ba\\*");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "*ba*" };
				const std::vector<std::string> splits = challenge->splitPattern("\\*ba\\*");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "b", "a*" };
				const std::vector<std::string> splits = challenge->splitPattern("b*a\\*");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "*", "*" };
				const std::vector<std::string> splits = challenge->splitPattern("*\\**\\**");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
			{
				const std::vector<std::string> expectedSplits = { "a*b", "c*d", "e" };
				const std::vector<std::string> splits = challenge->splitPattern("a\\*b*c\\*d*e");
				HelperClass::getInstance().compareStringVectors(expectedSplits, splits);
			}
		}

		TEST_METHOD(WildcardStringSearchingChallenge_findSubstringWithEscapedWildcards_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			Assert::IsFalse(challenge->isPatternInString("banana", "\\*"), L"Escaped wildcard mistakenly recognized");
			Assert::IsTrue(challenge->isPatternInString("ab*cd", "b*d"), L"Wildcard pattern wasn't found");
			Assert::IsFalse(challenge->isPatternInString("ab*cd", "b\\*d"), L"Wildcard pattern mistakenly found");
		}

		TEST_METHOD(WildcardStringSearchingChallenge_findSubstringWithBackspaces_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			Assert::IsFalse(challenge->isPatternInString("ba\\nana", "na\\n"), L"Backspace mistakenly recognized");
			Assert::IsTrue(challenge->isPatternInString("ba\\nana", "a\\n"), L"Backspace not recognized");
			Assert::IsTrue(challenge->isPatternInString("ab*c\\d", "b*\\d"), L"Wildcard pattern wasn't found");
			Assert::IsFalse(challenge->isPatternInString("a*\\cd", "a\\*\\d"), L"Wildcard pattern mistakenly found");
		}

		TEST_METHOD(WildcardStringSearchingChallenge_containsSubstringNoWildcards_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			Assert::IsTrue(challenge->containsSubstring("banana", "ana"), L"Existing pattern wasn't found");
			Assert::IsFalse(challenge->containsSubstring("banana", "baa"), L"Found non-existing pattern");
			Assert::IsTrue(challenge->containsSubstring("ananas", "anas"), L"Existing pattern wasn't found");
		}

		TEST_METHOD(WildcardStringSearchingChallenge_containsSubstringWithWildcards_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			Assert::IsTrue(challenge->containsSubstring("banana", "*"), L"Pure wildcard pattern wasn't found");
			Assert::IsTrue(challenge->containsSubstring("banana", "ba*a"), L"Wildcard pattern wasn't found");
			Assert::IsTrue(challenge->containsSubstring("banana", "*ba"), L"Starting wildcard pattern wasn't found");
			Assert::IsTrue(challenge->containsSubstring("abc", "bc*"), L"Ending wildcard pattern wasn't found");
			Assert::IsFalse(challenge->containsSubstring("abc", "a*cb"), L"Found non-existing pattern");
		}

		TEST_METHOD(WildcardStringSearchingChallenge_containsSubstringWithEscapedWildcards_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			Assert::IsFalse(challenge->containsSubstring("ab", "\\*"), L"Escaped wildcard mistakenly recognized");
			Assert::IsTrue(challenge->containsSubstring("ab*cd", "b*d"), L"Wildcard pattern wasn't found");
			Assert::IsFalse(challenge->containsSubstring("ab*cd", "b\\*d"), L"Wildcard pattern mistakenly found");
		}

		TEST_METHOD(WildcardStringSearchingChallenge_containsSubstringWithBackspaces_Test)
		{
			WildcardStringSearchingChallenge* challenge = new WildcardStringSearchingChallenge();
			Assert::IsFalse(challenge->containsSubstring("ba\\nana", "na\\n"), L"Backspace mistakenly recognized");
			Assert::IsTrue(challenge->containsSubstring("ba\\nana", "a\\n"), L"Backspace not recognized");
			Assert::IsTrue(challenge->containsSubstring("ab*c\\d", "b*\\d"), L"Wildcard pattern wasn't found");
			Assert::IsFalse(challenge->containsSubstring("a*\\cd", "a\\*\\d"), L"Wildcard pattern mistakenly found");
		}

		TEST_METHOD(SubArraySumChallenge_getMaxSubArraySum_Test)
		{
			SubArraySumChallenge* challenge = new SubArraySumChallenge();
			Assert::AreEqual(4, challenge->getMaxSubArraySum({ 1, 2, -5, 4, -3, 2 }), L"Wrong sub-array sum returned");
			Assert::AreEqual(8, challenge->getMaxSubArraySum({ 4, -2, 3, -1, 4 }), L"Wrong sub-array sum returned");
			Assert::AreEqual(4, challenge->getMaxSubArraySum({ 2, -4, 3, 1, -2 }), L"Wrong sub-array sum returned");
			Assert::AreEqual(3, challenge->getMaxSubArraySum({ -3, 1, 1, 1, -2, 2 }), L"Wrong sub-array sum returned");
			Assert::AreEqual(2, challenge->getMaxSubArraySum({ 2 }), L"Single-element sub-array should be the single value");
			Assert::AreEqual(0, challenge->getMaxSubArraySum({ -2, -1, -5, -1 }), L"For an array containing only negative numbers, the sub-array should be empty and its sum zero");
			Assert::AreEqual(0, challenge->getMaxSubArraySum({}), L"Empty array sum should be zero");
		}

		TEST_METHOD(FactorialTrailingZeroesChallenge_getNumOfTrailingZeroesForFactorial_Test)
		{
			FactorialTrailingZeroesChallenge* challenge = new FactorialTrailingZeroesChallenge();
			// 2 * 3 * 4 = 12
			Assert::AreEqual(0, challenge->getNumOfTrailingZeroesForFactorial(4), L"Wrong amount of trailing zeroes for factorial");
			// 2 * 3 * 4 * 5 = 6 * 20 = 120
			Assert::AreEqual(1, challenge->getNumOfTrailingZeroesForFactorial(5), L"Wrong amount of trailing zeroes for factorial");
			Assert::AreEqual(3, challenge->getNumOfTrailingZeroesForFactorial(16), L"Wrong amount of trailing zeroes for factorial");
		}
	};
}
