#include "../public/headfile.hpp"

// 输入流迭代器
void testOne()
{
	vector<string> vtStr;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(vtStr));
	cout << "source string:";
	printSTL(vtStr);

	sort(vtStr.begin(), vtStr.end());
	cout << "after sort string:";
	printSTL(vtStr);

	cout << "after unique string:";
	unique_copy(vtStr.begin(), vtStr.end(), ostream_iterator<string>(cout, "\n"));
}

// 输出流迭代器
void testTwo()
{
	vector<int> vtInt = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	copy(vtInt.begin(), vtInt.end(), ostream_iterator<int>(cout, " "));
}

int main(int argc, char *argv[])
{
	testTwo();

	getchar();

	return 0;
}