#include "P125_ValidPalindrome.h"
#include <cctype>

namespace problem125
{
	bool ValidPalindrome::isPalindrome(std::string str)
	{
		if (str.empty())
		{
			return true;
		}

		std::string filtered;
		for (unsigned char c : str)
		{
			if (std::isalnum(c))
			{
				filtered += std::tolower(c);
			}
		}

		if (filtered.empty())
		{
			return true;
		}

		auto left = filtered.begin();
		auto right = filtered.end() - 1;

		while (left < right)
		{
			if (*left != *right)
			{
				return false;
			}
			++left;
			--right;
		}

		return true;
	}

	bool ValidPalindrome::isPalindromeInPlace(std::string str)
	{
		if (str.empty())
		{
			return true;
		}

		int left = 0;
		int right = static_cast<int>(str.length()) - 1;

		while (left < right)
		{
			// Move left pointer forward until an alphanumeric character is found
			while (left < right && std::isalnum(static_cast<unsigned char>(str[left]) == false))
			{
				left++;
			}

			// Move right pointer backward until an alphanumeric character is found
			while (left < right && std::isalnum(static_cast<unsigned char>(str[right]) == false))
			{
				right--;
			}

			if (std::tolower(static_cast<unsigned char>(str[left])) !=
				std::tolower(static_cast<unsigned char>(str[right])))
			{
				return false;
			}

			left++;
			right--;
		}

		return true;
	}
}