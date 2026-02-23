#include "gtest/gtest.h"
#include "P230_SmallestElement.h"

namespace problem230
{
	TEST(KthSmallestTest, BasicBST)
	{
		/* 3
			 / \
			1   4
			 \
			  2
		   Sorted order: [1, 2, 3, 4]
		*/
		TreeNode* n2 = new TreeNode(2);
		TreeNode* n1 = new TreeNode(1, nullptr, n2);
		TreeNode* n4 = new TreeNode(4);
		TreeNode* root = new TreeNode(3, n1, n4);

		EXPECT_EQ(SmallestElement::kthSmallest(root, 1), 1);
		EXPECT_EQ(SmallestElement::kthSmallest(root, 2), 2);
		EXPECT_EQ(SmallestElement::kthSmallest(root, 3), 3);
	}

	TEST(KthSmallestTest, LeftSkewedTree)
	{
		/*
			  5
			 /
			3
		   /
		  1
		   Sorted order: [1, 3, 5]
		*/
		TreeNode* n1 = new TreeNode(1);
		TreeNode* n3 = new TreeNode(3, n1, nullptr);
		TreeNode* root = new TreeNode(5, n3, nullptr);

		EXPECT_EQ(SmallestElement::kthSmallest(root, 1), 1);
		EXPECT_EQ(SmallestElement::kthSmallest(root, 3), 5);
	}

	TEST(KthSmallestTest, RightSkewedTree)
	{
		/*
		  1
		   \
			2
			 \
			  3
		   Sorted order: [1, 2, 3]
		*/
		TreeNode* n3 = new TreeNode(3);
		TreeNode* n2 = new TreeNode(2, nullptr, n3);
		TreeNode* root = new TreeNode(1, nullptr, n2);

		EXPECT_EQ(SmallestElement::kthSmallest(root, 2), 2);
	}

	TEST(KthSmallestTest, SingleNode)
	{
		TreeNode* root = new TreeNode(10);
		EXPECT_EQ(SmallestElement::kthSmallest(root, 1), 10);
	}
}