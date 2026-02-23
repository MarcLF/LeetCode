#include "PC1_SkyArray.h"
#include <algorithm>
#include <numeric>
#include <vector>

namespace probcustom1
{
	std::vector<int> Skyscrapers::solution(std::vector<int>& max_heights)
	{
		size_t max_h_size = max_heights.size();
		std::vector<int> output_heights(max_h_size);

		std::vector<int> indices(max_h_size);
		std::iota(indices.begin(), indices.end(), 0);

		// Process the tallest potential buildings first.
		std::sort(indices.begin(), indices.end(), [max_heights](int i, int j)
			{
				return max_heights[i] > max_heights[j];
			});

		// upper_limit for the next building we process.
		int upper_limit = std::numeric_limits<int>::max();

		for (int idx : indices)
		{
			int current_height = std::min(max_heights[idx], upper_limit);

			output_heights[idx] = current_height;

			// next building must be at least 1 unit shorter to remain unique.
			upper_limit = current_height - 1;
		}

		return output_heights;
	}
}