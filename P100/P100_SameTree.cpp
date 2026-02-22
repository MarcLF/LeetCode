#include "P100_SameTree.h"

namespace problem100
{
	bool checkNode(TreeNode* p, TreeNode* q)
	{
		if (p == nullptr && q == nullptr)
		{
			return true;
		}
		if (p == nullptr || q == nullptr || p->val != q->val)
		{
			return false;
		}

		return checkNode(p->left, q->left) && checkNode(p->right, q->right);
	}

	bool SameTree::isSameTree(TreeNode* p, TreeNode* q)
	{
		return checkNode(p, q);
	}
}