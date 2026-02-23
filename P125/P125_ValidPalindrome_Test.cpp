#include "gtest/gtest.h"
#include "P125_ValidPalindrome.h"

namespace problem125
{
	TEST(ValidPalindromeTest, Example1)
	{
		EXPECT_TRUE(problem125::ValidPalindrome::isPalindrome("A man, a plan, a canal: Panama"));
	}

	TEST(ValidPalindromeTest, Example2)
	{
		EXPECT_FALSE(problem125::ValidPalindrome::isPalindrome("race a car"));
	}

	TEST(ValidPalindromeTest, EmptyAndSingle)
	{
		EXPECT_TRUE(problem125::ValidPalindrome::isPalindrome(""));
		EXPECT_TRUE(problem125::ValidPalindrome::isPalindrome("a"));
	}

	TEST(ValidPalindromeTest, Example1InPlace)
	{
		EXPECT_TRUE(problem125::ValidPalindrome::isPalindromeInPlace("A man, a plan, a canal: Panama"));
	}

	TEST(ValidPalindromeTest, Example2InPlace)
	{
		EXPECT_FALSE(problem125::ValidPalindrome::isPalindromeInPlace("race a car"));
	}

	TEST(ValidPalindromeTest, EmptyAndSingleInPlace)
	{
		EXPECT_TRUE(problem125::ValidPalindrome::isPalindromeInPlace(""));
		EXPECT_TRUE(problem125::ValidPalindrome::isPalindromeInPlace("a"));
	}
}
