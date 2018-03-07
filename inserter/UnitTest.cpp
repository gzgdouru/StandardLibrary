#include "../public/headfile.hpp"

int main(int argc, char *argv[])
{
	list<int> lstInt{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// 插入到容器后面
	vector<int> vtInt;
	copy(lstInt.begin(), lstInt.end(), back_inserter(vtInt));
	cout << "vector:";
	printSTL(vtInt);

	// 插入到容器前面
	deque<int> dqInt;
	copy(lstInt.begin(), lstInt.end(), front_inserter(dqInt));
	cout << "deque:";
	printSTL(dqInt);

	// 插入到容器适当的位置
	set<int> stInt;
	copy(lstInt.begin(), lstInt.end(), inserter(stInt, stInt.begin()));
	cout << "set:";
	printSTL(stInt);

	list<int> ltInt2;
	copy(lstInt.begin(), lstInt.end(), inserter(ltInt2, ltInt2.begin()));
	copy(lstInt.begin(), lstInt.end(), inserter(ltInt2, ltInt2.begin()));
	cout << "list2:";
	printSTL(ltInt2);

	getchar();

	return 0;
}