#include "P1_TwoSum.h"
#include <unordered_map>

std::vector<int> TwoSum::twoSumBruteForce(std::vector<int>& nums, int target)
{
	bool target_not_found = true;

	int index_1 = 0;
	int index_2 = 0;

	while (target_not_found)
	{
		for (auto& it : nums)
		{
			if (index_1 == index_2)
			{
				++index_2;
				continue;
			}
			if (nums[index_1] + nums[index_2] == target)
			{
				return std::vector<int>({ index_1, index_2 });
			}
			++index_2;
		}

		if (index_1 < nums.size())
		{
			++index_1;
		}
		index_2 = 0;
	}

	return {};
}


std::vector<int> TwoSum::twoSumHashMap(std::vector<int>& nums, int target)
{
	std::unordered_map<int, int> numMap;

	for (int i = 0; i < nums.size(); i++)
	{
		int complement = target - nums[i];

		if (numMap.find(complement) != numMap.end())
		{
			return { numMap[complement], i };
		}
		numMap[nums[i]] = i;
	}
	return {};
}