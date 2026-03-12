#include "P217_ContainsDuplicate.h"

#include <unordered_set>

namespace problem217
{
	bool ContainsDuplicate::containsDuplicate(std::vector<int>& nums)
	{
		std::unordered_set<int> vec_nums;
		for (auto it : nums)
		{
			if (vec_nums.contains(it) == true)
			{
				return true;
			}
			vec_nums.emplace(it);
		}
		return false;
	}
}
