#include "P1115_FooBar.h"

namespace problem1115
{
	FooBar::FooBar(int n)
	{
		this->n = n;
	}

	void FooBar::foo(std::function<void()> printFoo)
	{
		for (int i = 0; i < n; i++)
		{
			foo_sem.acquire();
			// printFoo() outputs "foo". Do not change or remove this line.
			printFoo();
			bar_sem.release();
		}
	}

	void FooBar::bar(std::function<void()> printBar)
	{
		for (int i = 0; i < n; i++)
		{
			bar_sem.acquire();
			// printBar() outputs "bar". Do not change or remove this line.
			printBar();
			foo_sem.release();
		}
	}
}
