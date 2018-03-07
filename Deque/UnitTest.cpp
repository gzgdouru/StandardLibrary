#include "../public/headfile.hpp"

void test1()
{
	deque<int> deInt;
	for (int i = 0; i < 5; ++i)
	{
		deInt.push_front(i);
	}

	for (int i = 10; i < 15; ++i)
	{
		deInt.push_back(i);
	}

	printSTL(deInt);
}

void test2()
{
	deque<string> deStr;
	deStr.assign(3, "string");
	deStr.push_back("last string");
	deStr.push_front("first string");
	copy(deStr.begin(), deStr.end(), ostream_iterator<string>(cout, "\n"));

	deStr.pop_front();
	deStr.pop_back();

	for (int i = 1; i < deStr.size(); ++i)
	{
		deStr[i] = "another " + deStr[i];
	}
	deStr.resize(4, "resized string");
	copy(deStr.begin(), deStr.end(), ostream_iterator<string>(cout, "\n"));
}

int main(int argc, char *argv[])
{
	test2();

	getchar();
	return 0;
}