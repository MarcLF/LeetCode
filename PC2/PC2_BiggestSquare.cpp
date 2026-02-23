#include "PC2_BiggestSquare.h"
#include <algorithm>

namespace probcustom2
{
	int BiggestSquare::solution(int A, int B)
	{
		int max_side = 0;

		// Case 1: All 4 from A
		max_side = std::max(max_side, A / 4);

		// Case 2: 3 from A, 1 from B
		max_side = std::max(max_side, std::min(A / 3, B));

		// Case 3: 2 from A, 2 from B
		max_side = std::max(max_side, std::min(A / 2, B / 2));

		// Case 4: 1 from A, 3 from B
		max_side = std::max(max_side, std::min(A, B / 3));

		// Case 5: All 4 from B
		max_side = std::max(max_side, B / 4);

		return max_side;
	}
}