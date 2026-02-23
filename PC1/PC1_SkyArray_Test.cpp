#include "gtest/gtest.h"
#include "PC1_SkyArray.h"

namespace probcustom1
{
	static void VerifySolution(const std::vector<int>& A, const std::vector<int>& B, long long expectedSum)
	{
		ASSERT_EQ(A.size(), B.size()) << "Output size mismatch";

		std::set<int> uniqueHeights;
		long long actualSum = 0;

		for (size_t i = 0; i < A.size(); ++i)
		{
			// Requirement 1: Positive and within bounds
			EXPECT_GT(B[i], 0) << "Height at index " << i << " is not positive";
			EXPECT_LE(B[i], A[i]) << "Height at index " << i << " exceeds maximum A[i]";

			// Requirement 2: Uniqueness
			bool inserted = uniqueHeights.insert(B[i]).second;
			EXPECT_TRUE(inserted) << "Duplicate height found: " << B[i];

			actualSum += B[i];
		}

		// Requirement 3: Maximum Sum
		EXPECT_EQ(actualSum, expectedSum) << "The sum of heights is not maximized";
	}

	TEST(SkyArrayTest, Example1_SimpleIncreasing)
	{
		std::vector<int> A = { 1, 2, 3 };
		auto result = Skyscrapers::solution(A);
		// Sum: 1 + 2 + 3 = 6
		VerifySolution(A, result, 6);
	}

	TEST(SkyArrayTest, Example2_Duplicates)
	{
		std::vector<int> A = { 9, 4, 3, 7, 7 };
		auto result = Skyscrapers::solution(A);
		// Max sum: 9 + 4 + 3 + 7 + 6 = 29
		VerifySolution(A, result, 29);
	}

	TEST(SkyArrayTest, Example3_TightConstraints)
	{
		std::vector<int> A = { 2, 5, 4, 5, 5 };
		auto result = Skyscrapers::solution(A);
		// Max sum: 5 + 4 + 3 + 2 + 1 = 15
		VerifySolution(A, result, 15);
	}

	TEST(SkyArrayTest, LargeIdenticalLimits)
	{
		// Testing N = 5 buildings all capped at 5
		// They must become 5, 4, 3, 2, 1
		std::vector<int> A = { 5, 5, 5, 5, 5 };
		auto result = Skyscrapers::solution(A);
		VerifySolution(A, result, 15);
	}

	TEST(SkyArrayTest, MaximumConstraints)
	{
		// N is 50,000, A[i] is 1,000,000,000
		int N = 50000;
		std::vector<int> A(N, 1000000000);
		auto result = Skyscrapers::solution(A);

		// The sum of an arithmetic progression: n/2 * (first + last)
		// 1,000,000,000 + 999,999,999 + ... + (1,000,000,000 - 49,999)
		long long first = 1000000000;
		long long last = 1000000000 - 49999;
		long long expectedSum = (long long)N * (first + last) / 2;

		VerifySolution(A, result, expectedSum);
	}
}