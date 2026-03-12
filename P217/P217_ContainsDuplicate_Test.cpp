#include "gtest/gtest.h"
#include "P217_ContainsDuplicate.h"

namespace problem217
{
	TEST(ContainsDuplicate, BasicTest)
	{
		ContainsDuplicate solution;
		std::vector<int> nums = { 1, 2, 3, 1 };
		EXPECT_TRUE(solution.containsDuplicate(nums));
	}

	TEST(ContainsDuplicate, NoDuplicates)
	{
		ContainsDuplicate solution;
		std::vector<int> nums = { 1, 2, 3, 4 };
		EXPECT_FALSE(solution.containsDuplicate(nums));
	}

	TEST(ContainsDuplicate, SingleElement)
	{
		ContainsDuplicate solution;
		std::vector<int> nums = { 1 };
		EXPECT_FALSE(solution.containsDuplicate(nums));
	}

	TEST(ContainsDuplicate, EmptyArray)
	{
		ContainsDuplicate solution;
		std::vector<int> nums = {};
		EXPECT_FALSE(solution.containsDuplicate(nums));
	}

	TEST(ContainsDuplicate, AllDuplicates)
	{
		ContainsDuplicate solution;
		std::vector<int> nums = { 5, 5, 5, 5 };
		EXPECT_TRUE(solution.containsDuplicate(nums));
	}

	TEST(ContainsDuplicate, DuplicatesAtEnd)
	{
		ContainsDuplicate solution;
		std::vector<int> nums = { 1, 2, 3, 4, 5, 1 };
		EXPECT_TRUE(solution.containsDuplicate(nums));
	}
}