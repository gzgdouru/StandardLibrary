#include "../public/headfile.hpp"

int f(int a, int b)
{
	return a * a + b;
}

int main(int argc, char *argv[])
{
	set<int> stInt{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> vtInt;
	printSTL(stInt, "set:");
	int iNum = 10;


	//transform(stInt.begin(), stInt.end(), back_inserter(vtInt), [iNum](int i) {
	//	return i * i + iNum;
	//});

	function<int(int)> func = bind(f, placeholders::_1, iNum);
	transform(stInt.begin(), stInt.end(), back_inserter(vtInt), func);

	printSTL(vtInt, "vector:");


	getchar();
	
	return 0;
}