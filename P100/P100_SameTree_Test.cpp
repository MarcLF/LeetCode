#include "gtest/gtest.h"
#include "P100_SameTree.h"

namespace problem100
{
	// Test 1: Identical Trees (This will fail because p != q)
	TEST(SameTreeTest, IdenticalTrees)
	{
		TreeNode* tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
		TreeNode* tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

		EXPECT_TRUE(problem100::SameTree::isSameTree(tree1, tree2));
	}

	// Test 2: Null Trees (The ultimate base case)
	TEST(SameTreeTest, BothNull)
	{
		EXPECT_TRUE(problem100::SameTree::isSameTree(nullptr, nullptr));
	}

	// Test 3: Different Values (Same structure)
	TEST(SameTreeTest, DifferentValues)
	{
		TreeNode* tree1 = new TreeNode(1, new TreeNode(2), nullptr);
		TreeNode* tree2 = new TreeNode(1, new TreeNode(5), nullptr);

		EXPECT_FALSE(problem100::SameTree::isSameTree(tree1, tree2));
	}
}