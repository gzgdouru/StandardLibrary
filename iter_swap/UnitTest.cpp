#include "../public/headfile.hpp"

int main(int argc, char *argv[])
{
	vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	iter_swap(coll.begin(), ++coll.begin());
	printSTL(coll);

	iter_swap(coll.begin(), --coll.end());
	printSTL(coll);

	getchar();
	return 0;
}