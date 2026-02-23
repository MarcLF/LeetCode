#include "gtest/gtest.h"
#include "PC2_BiggestSquare.h"

namespace probcustom2
{
	TEST(SquareStickTest, Example1_MixedSticks)
	{
		// Stick B gives 3 pieces of 7, Stick A gives 1 piece of 7 (after shortening)
		EXPECT_EQ(BiggestSquare::solution(10, 21), 7);
	}

	TEST(SquareStickTest, Example2_SplitDistribution)
	{
		// Both sticks contribute 2 pieces of 5
		EXPECT_EQ(BiggestSquare::solution(13, 11), 5);
	}

	TEST(SquareStickTest, Example3_NotPossible)
	{
		// Total length is 3, cannot make 4 pieces of length 1
		EXPECT_EQ(BiggestSquare::solution(2, 1), 0);
	}

	TEST(SquareStickTest, Example4_SingleStickFocus)
	{
		// Stick B is cut into 4 pieces of 2; Stick A is too short to contribute
		EXPECT_EQ(BiggestSquare::solution(1, 8), 2);
	}

	TEST(SquareStickTest, LargeValues)
	{
		// Maximum possible values: 10^9 and 10^9
		// (10^9 + 10^9) / 4 = 500,000,000
		EXPECT_EQ(BiggestSquare::solution(1000000000, 1000000000), 500000000);
	}

	TEST(SquareStickTest, OneVeryLongOneVeryShort)
	{
		// Stick A is 1, Stick B is 1,000,000,000. 
		// All 4 pieces must come from B.
		EXPECT_EQ(BiggestSquare::solution(1, 1000000000), 250000000);
	}

	TEST(SquareStickTest, SmallestValidSquare)
	{
		// Minimum length to get four sticks of 1
		EXPECT_EQ(BiggestSquare::solution(2, 2), 1);
		EXPECT_EQ(BiggestSquare::solution(1, 3), 1);
	}
}