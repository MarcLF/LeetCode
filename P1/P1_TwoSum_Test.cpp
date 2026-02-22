#include "gtest/gtest.h"
#include "P1_TwoSum.h"

namespace problem1
{
	// Test Case 1: Standard positive numbers
	TEST(TwoSum, StandardArray)
	{
		TwoSum sol;
		std::vector<int> nums = { 2, 7, 11, 15 };
		int target = 9;

		std::vector<int> expected = { 0, 1 };

		// Testing both approaches
		EXPECT_EQ(sol.twoSumBruteForce(nums, target), expected);
		EXPECT_EQ(sol.twoSumHashMap(nums, target), expected);
	}

	// Test Case 2: Array where the numbers are not sequential
	TEST(TwoSum, UnsortedArray)
	{
		TwoSum sol;
		std::vector<int> nums = { 3, 2, 4 };
		int target = 6;

		std::vector<int> expected = { 1, 2 };

		// Testing both approaches
		EXPECT_EQ(sol.twoSumBruteForce(nums, target), expected);
		EXPECT_EQ(sol.twoSumHashMap(nums, target), expected);
	}

	// Test Case 3: Array with identical numbers
	TEST(TwoSum, IdenticalNumbers)
	{
		TwoSum sol;
		std::vector<int> nums = { 3, 3 };
		int target = 6;

		std::vector<int> expected = { 0, 1 };

		// Testing both approaches
		EXPECT_EQ(sol.twoSumBruteForce(nums, target), expected);
		EXPECT_EQ(sol.twoSumHashMap(nums, target), expected);
	}

	// Test Case 4: Array with negative numbers
	TEST(TwoSum, NegativeNumbers)
	{
		TwoSum sol;
		std::vector<int> nums = { -1, -2, -3, -4, -5 };
		int target = -8;

		std::vector<int> expected = { 2, 4 };

		// Testing both approaches
		EXPECT_EQ(sol.twoSumBruteForce(nums, target), expected);
		EXPECT_EQ(sol.twoSumHashMap(nums, target), expected);
	}
}