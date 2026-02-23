#include "P230_SmallestElement.h"
#include <optional>

namespace problem230
{
	void inOrderTraversal(TreeNode* node, int k, int& counter, std::optional<int>& result)
	{
		if (node == nullptr || result.has_value())
		{
			return;
		}

		inOrderTraversal(node->left, k, counter, result);

		if (result.has_value()) { return; }

		counter++;
		if (counter == k)
		{
			result = node->val;
			return;
		}


		inOrderTraversal(node->right, k, counter, result);
	}
	int SmallestElement::kthSmallest(TreeNode* root, int k)
	{
		int counter = 0;
		std::optional<int> result;

		inOrderTraversal(root, k, counter, result);

		return result.value();
	}
}