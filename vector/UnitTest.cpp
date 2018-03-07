#include "../public/headfile.hpp"

void test1()
{
	vector<int> vtInt{ 1, 2, 3, 4, 5, 6, 3, 7, 8, 3, 9, 10, 2 };
	printSTL(vtInt, "vector init:");

	// 删除vector里所有值为3的元素
	auto end_iterator = remove(vtInt.begin(), vtInt.end(), 11);
	vtInt.erase(end_iterator, vtInt.end());
	printSTL(vtInt, "after erase all 3:");

	// 删除vector里第一个值为2的元素
	auto pos = find(vtInt.begin(), vtInt.end(), 11);
	if (pos != vtInt.end())
	{
		vtInt.erase(pos);
	}

	printSTL(vtInt, "after erase first 2:");
}

void test2()
{
	vector<string> vtStr;
	vtStr.reserve(5);
	vtStr.push_back("hello,");
	vtStr.push_back("how");
	vtStr.push_back("are");
	vtStr.push_back("you");
	vtStr.push_back("?");
	copy(vtStr.begin(), vtStr.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	
	cout << "max_size(): " << vtStr.max_size() << endl;
	cout << "size(): " << vtStr.size() << endl;
	cout << "capacity(): " << vtStr.capacity() << endl;

	swap(vtStr[1], vtStr[3]);
	vtStr.insert(find(vtStr.begin(), vtStr.end(), "?"), "always");
	vtStr.back() = "!";
	copy(vtStr.begin(), vtStr.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	cout << "max_size(): " << vtStr.max_size() << endl;
	cout << "size(): " << vtStr.size() << endl;
	cout << "capacity(): " << vtStr.capacity() << endl;
}

void test3()
{
	vector<string> vtStr;
	vtStr.reserve(5);
	vtStr[0] = "hello,";
	vtStr[1] = "how";
	vtStr[2] = "are";
	vtStr[3] = "you";
	vtStr[4] = "?";
	copy(vtStr.begin(), vtStr.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	cout << "max_size(): " << vtStr.max_size() << endl;
	cout << "size(): " << vtStr.size() << endl;
	cout << "capacity(): " << vtStr.capacity() << endl;
}

void test4()
{
	vector<int> vtInt;
	for (int i = 0; i < 10; ++i)
	{
		vtInt[i] = i;
	}
	vtInt.resize(20);
	printSTL(vtInt);
}

int main(int argc, char *argv[])
{
	test4();

	getchar();
	return 0;
}