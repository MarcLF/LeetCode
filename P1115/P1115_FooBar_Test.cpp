#include "gtest/gtest.h"
#include "P1115_FooBar.h"

#include <mutex>
#include <string>
#include <thread>

namespace problem1115
{
	namespace
	{
		std::string RepeatFooBar(int n)
		{
			std::string expected;
			expected.reserve(static_cast<std::size_t>(n) * 6);

			for (int i = 0; i < n; ++i)
			{
				expected += "foobar";
			}

			return expected;
		}

		std::string RunFooBar(int n, bool start_bar_first = false)
		{
			FooBar foobar(n);

			std::string output;
			std::mutex output_mutex;

			auto printFoo = [&]()
				{
					std::scoped_lock lock(output_mutex);
					output += "foo";
				};

			auto printBar = [&]()
				{
					std::scoped_lock lock(output_mutex);
					output += "bar";
				};

			if (start_bar_first)
			{
				std::thread thread_bar([&]()
									   {
										   foobar.bar(printBar);
									   });
				std::thread thread_foo([&]()
									   {
										   foobar.foo(printFoo);
									   });

				thread_bar.join();
				thread_foo.join();
			}
			else
			{
				std::thread thread_foo([&]()
									   {
										   foobar.foo(printFoo);
									   });
				std::thread thread_bar([&]()
									   {
										   foobar.bar(printBar);
									   });

				thread_foo.join();
				thread_bar.join();
			}

			return output;
		}
	}

	TEST(FooBar, BasicTest)
	{
		EXPECT_EQ(RunFooBar(1), "foobar");
	}

	TEST(FooBar, TwoIterations)
	{
		EXPECT_EQ(RunFooBar(2), "foobarfoobar");
	}

	TEST(FooBar, MultipleIterations)
	{
		constexpr int n = 5;
		EXPECT_EQ(RunFooBar(n), RepeatFooBar(n));
	}

	TEST(FooBar, CorrectOutputLength)
	{
		constexpr int n = 10;
		EXPECT_EQ(RunFooBar(n).size(), static_cast<std::size_t>(n) * 6);
	}

	TEST(FooBar, BarThreadCanStartFirst)
	{
		constexpr int n = 3;
		EXPECT_EQ(RunFooBar(n, true), RepeatFooBar(n));
	}

}