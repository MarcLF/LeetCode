#pragma once

#include <condition_variable>
#include <functional>
#include <semaphore>

namespace problem1115
{
	class FooBar
	{
	private:
		int n;
		std::binary_semaphore foo_sem{ 1 };
		std::binary_semaphore bar_sem{ 0 };

	public:
		FooBar(int n);
		void foo(std::function<void()> printFoo);
		void bar(std::function<void()> printBar);
	};
}
