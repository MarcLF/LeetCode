#include "P153_SortedArray.h"

#include <numeric>

namespace problem153
{
	int SortedArray::findMin(std::vector<int>& nums)
	{
		auto left_element = nums.begin();
		auto right_element = nums.end() - 1;

		while (left_element != right_element)
		{
			auto mid_element = left_element + (right_element - left_element) / 2;

			if (*mid_element > *right_element)
			{
				left_element = mid_element + 1;
			}
			else
			{
				right_element = mid_element;
			}

		}

		return *left_element;
	}
}
