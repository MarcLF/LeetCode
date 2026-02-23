#include "gtest/gtest.h"
#include "PC3_BalancedNodes.h"

namespace probcustom3
{
	TEST(BalancedNodesTest, ProvidedExample)
	{
		/* Tree Structure from Task 3 Image:
				 6 (Root)
				/ \
			   3   2
			  / \   \
			 1   1   1
		*/
		Node* l1 = new Node(1);
		Node* l2 = new Node(1);
		Node* l3 = new Node(1);

		Node* n3 = new Node(3, l1, l2);      // Balanced (1 == 1)
		Node* n2 = new Node(2, nullptr, l3); // Balanced (only 1 child)
		Node* root = new Node(6, n3, n2);    // Unbalanced (3 != 2)

		int result = BalancedNodes::solution(root);

		// Expected balanced nodes: l1, l2, l3, n3, n2 = 5
		EXPECT_EQ(result, 5);

		delete l1; delete l2; delete l3; delete n3; delete n2; delete root;
	}

	TEST(BalancedNodesTest, PerfectBinaryTree)
	{
		//      2
		//     / \
        //    1   1
		Node* l1 = new Node(1);
		Node* l2 = new Node(1);
		Node* root = new Node(2, l1, l2);

		int result = BalancedNodes::solution(root);

		// All nodes are balanced (l1, l2 are leaves, root has 1 == 1)
		EXPECT_EQ(result, 3);

		delete l1; delete l2; delete root;
	}

	TEST(BalancedNodesTest, NullTree)
	{
		// An empty tree should return 0 balanced nodes
		EXPECT_EQ(BalancedNodes::solution(nullptr), 0);
	}
}