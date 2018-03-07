#include "../public/headfile.hpp"

int main(int argc, char *argv[])
{
	list<int> ltInt;
	for (int i = 1; i <=6; ++i)
	{
		ltInt.push_front(i);
		ltInt.push_back(i);
	}
	copy(ltInt.begin(), ltInt.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	auto end_iterator = remove(ltInt.begin(), ltInt.end(), 3);
	copy(ltInt.begin(), end_iterator, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "number of remove elements:" << distance(end_iterator, ltInt.end()) << endl;

	ltInt.erase(end_iterator, ltInt.end());
	copy(ltInt.begin(), ltInt.end(), ostream_iterator<int>(cout, " "));
	cout << endl;


	getchar();

	return 0;
}