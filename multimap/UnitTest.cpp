#include "../public/headfile.hpp"

int main(int argc, char *argv[])
{
	multimap<string, string> mlpStr;
	mlpStr.insert(make_pair("ouru", "4000"));
	mlpStr.insert(make_pair("wancaiji", "4500"));
	mlpStr.insert(make_pair("laopan", "12000"));
	mlpStr.insert(make_pair("wancaiji", "6500"));
	mlpStr.insert(make_pair("ouru", "5000"));
	mlpStr.insert(make_pair("wancaiji", "8500"));
	mlpStr.insert(make_pair("ouru", "9000"));
	mlpStr.insert(make_pair("laopan", "13000"));

	cout << "ouru:" << endl;
	for (auto it = mlpStr.lower_bound("ouru"); it != mlpStr.upper_bound("ouru"); ++it)
	{
		cout << it->second << endl;
	}
	cout << endl;

	cout << "wancaiji:" << endl;
	for (auto it = mlpStr.lower_bound("wancaiji"); it != mlpStr.upper_bound("wancaiji"); ++it)
	{
		cout << it->second << endl;
	}
	cout << endl;

	cout << "laopan:" << endl;
	for (auto it = mlpStr.lower_bound("laopan"); it != mlpStr.upper_bound("laopan"); ++it)
	{
		cout << it->second << endl;
	}
	cout << endl;

	getchar();

	return 0;
}