#include "../public/headfile.hpp"

void testOne()
{
	vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto pos1 = find(coll.begin(), coll.end(), 5);
	cout << *pos1 << endl;

	vector<int>::reverse_iterator pos2(pos1);
	cout << *pos2 << endl;
}

void testTwo()
{
	vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto pos1 = find(coll.begin(), coll.end(), 2);
	auto pos2 = find(coll.begin(), coll.end(), 7);
	for_each(pos1, pos2, [] (int x){
		cout << x << " ";
	});
	cout << endl;

	vector<int>::reverse_iterator rpos1(pos1);
	vector<int>::reverse_iterator rpos2(pos2);
	for_each(rpos2, rpos1, [](int x) {
		cout << x << " ";
	});
	cout << endl;
}

void testThree()
{
	list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto pos = find(coll.begin(), coll.end(), 5);
	cout << *pos << endl;

	list<int>::reverse_iterator rpos(pos);
	cout << *rpos << endl;

	list<int>::iterator rrpos = rpos.base();
	cout << *rrpos << endl;
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	testTwo();

	//testThree();

	getchar();

	return 0;
}