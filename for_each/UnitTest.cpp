#include "../public/headfile.hpp"

void printInt(int iElem)
{
	cout << iElem << " ";
}

int main(int argc, char *argv[])
{
	vector<int> vtInt{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//for_each(vtInt.begin(), vtInt.end(), printInt);
	int iNum = 5;
	for_each(vtInt.begin(), vtInt.end(), [](int i) {
		cout << i << " "; }
	);
	cout << endl;

	getchar();

	return 0;
}