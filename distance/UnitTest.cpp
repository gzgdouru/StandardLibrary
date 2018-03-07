#include "../public/headfile.hpp"

int main(int argc, char *argv[])
{
	list<int> coll;
	for (int i = -10; i <=9; ++i)
	{
		coll.push_back(i);
	}

	auto pos = find(coll.begin(), coll.end(), 5);
	if (pos != coll.end())
	{
		cout << "difference between beginning and 5: " << distance(coll.begin(), pos) << endl;
	}

	getchar();
	return 0;
}