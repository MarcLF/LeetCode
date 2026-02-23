#include "PC3_BalancedNodes.h"
#include <algorithm>
#include <numeric>
#include <vector>

namespace probcustom3
{
	static int calculateSubtreeSize(Node* node, int& count)
	{
		if (node == nullptr)
		{
			return 0;
		}

		int leftSize = calculateSubtreeSize(node->left, count);
		int rightSize = calculateSubtreeSize(node->right, count);

		if (node->left != nullptr && node->right != nullptr)
		{
			if (leftSize == rightSize)
			{
				count++;
			}
		}
		else
		{
			count++;
		}

		// Return total size of this node's subtree to its parent
		return 1 + leftSize + rightSize;
	}

	int BalancedNodes::solution(Node* tree)
	{
		int balancedCount = 0;
		calculateSubtreeSize(tree, balancedCount);
		return balancedCount;
	}
}