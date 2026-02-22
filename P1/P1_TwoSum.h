#pragma once
#include <vector>

namespace problem1
{
	class TwoSum
	{
		public:
		// The O(N^2) nested loop approach
		std::vector<int> twoSumBruteForce(std::vector<int>& nums, int target);

		// The O(N) hash map approach
		std::vector<int> twoSumHashMap(std::vector<int>& nums, int target);
	};
}