#include "P153_SortedArray.h"
#include <gtest/gtest.h>

namespace problem153
{
	TEST(SortedArray, BasicTest1)
	{
		SortedArray solution;
		std::vector<int> nums = { 5,1,2,3,4 };
		int expected = 1;

		EXPECT_EQ(solution.findMin(nums), expected);
	}

	TEST(SortedArray, BasicTest2)
	{
		SortedArray solution;
		std::vector<int> nums = { 11,13,15,17 };
		int expected = 11;

		EXPECT_EQ(solution.findMin(nums), expected);
	}
}
