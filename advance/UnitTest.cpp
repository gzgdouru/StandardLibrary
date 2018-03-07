#include "../public/headfile.hpp"
#include "../public/timer.hpp"

int main(int argc, char *argv[])
{
	list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto pos = coll.begin();

	cout << *pos << endl;

	advance(pos, 3);
	cout << *pos << endl;

	advance(pos, -1);
	cout << *pos << endl;

	vector<int> vtInt(1000000, 0);
	auto itVt = vtInt.begin();
	timer t(TimeType::e_mic);
	cout << *(itVt + 999999) << endl;
	cout << t.elapsed() << endl;

	list<int> ltInt(1000000, 0);
	pos = ltInt.begin();
	t.reset();
	advance(pos, 999999);
	cout << *pos << endl;
	cout << t.elapsed() << endl;

	getchar();
	return 0;
}