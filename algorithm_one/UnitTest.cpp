#include "../public/headfile.hpp"

int main(int argc, char *argv[])
{
	vector<int> vtInt{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	
	auto pos = max_element(vtInt.begin(), vtInt.end());
	cout << "max:" << *pos << endl;

	pos = min_element(vtInt.begin(), vtInt.end());
	cout << "min:" << *pos << endl;

	cout << "befor sort:" << endl;
	printSTL(vtInt);

	sort(vtInt.begin(), vtInt.end());
	cout << "after sort:" << endl;
	printSTL(vtInt);

	pos = find(vtInt.begin(), vtInt.end(), 3);
	if (pos != vtInt.end())
	{
		cout << "find num:" << *pos << endl;
	}
	else
	{
		cout << "not find!" << endl;
	}

	// ·´×ª
	reverse(pos, vtInt.end());
	cout << "after reverse:" << endl;
	printSTL(vtInt);

	getchar();

	return 0;
}