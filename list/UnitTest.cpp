#include "../public/headfile.hpp"

void test1()
{
	list<int> lst1, lst2;
	for (int i = 0; i < 6; ++i)
	{
		lst1.push_back(i);
		lst2.push_front(i);
	}
	printSTL(lst1, "lst1: ");
	printSTL(lst2, "lst2: ");

	auto pos = find(lst2.begin(), lst2.end(), 3);
	lst2.splice(pos, lst1);
	printSTL(lst1, "lst1: ");
	printSTL(lst2, "lst2: ");

	lst2.splice(lst2.end(), lst2, lst2.begin());
	printSTL(lst1, "lst1: ");
	printSTL(lst2, "lst2: ");

	lst2.sort();
	lst1 = lst2;
	lst2.unique();
	printSTL(lst1, "lst1: ");
	printSTL(lst2, "lst2: ");

	lst1.merge(lst2);
	printSTL(lst1, "lst1: ");
	printSTL(lst2, "lst2: ");
}

void test2()
{
	vector<int> vtInt1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vtInt2;
	vtInt2.assign(vtInt1.begin() + vtInt1.size() / 2, vtInt1.end());
	printSTL(vtInt2);
	cout << vtInt2.size() << endl;
}
void test3()
{
	ifstream dataFile("UnitTest.cpp");
	//list<string> data((istream_iterator<string>(dataFile)), istream_iterator<string>());
	istream_iterator<string> dataBegin(dataFile);
	istream_iterator<string> dataEnd;
	list<string> data(dataBegin, dataEnd);
	printSTL(data);
}

int main(int argc, char *argv[])
{
	test3();

	getchar();
	return 0;
}