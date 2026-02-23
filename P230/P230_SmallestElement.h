#pragma once
#include <vector>

namespace problem230
{
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	};

	class SmallestElement
	{
		public:
		static int kthSmallest(TreeNode* root, int k);
	};
}