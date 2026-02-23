#pragma once
#include <vector>

namespace probcustom3
{
	struct Node
	{
		int val;
		Node* left;
		Node* right;
		Node() : val(0), left(nullptr), right(nullptr) {}
		Node(int x) : val(x), left(nullptr), right(nullptr) {}
		Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}

	};

	class BalancedNodes
	{
		public:
		static int solution(Node* tree);
	};
}