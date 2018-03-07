#include "../public/headfile.hpp"

bool isPrime(int iNum)
{
	iNum = abs(iNum);

	if (0 == iNum || 1 == iNum)
	{
		return true;
	}

	int iloop;
	for (iloop = iNum / 2; (iNum % iloop) != 0; --iloop)
	{
	}

	return 1 == iloop;
}

int main(int argc, char *argv[])
{
	list<int> ltInt;
	for (int i = 32; i < 100; ++i)
	{
		ltInt.push_back(i);
	}

	auto pos = find_if(ltInt.begin(), ltInt.end(), isPrime);
	if (pos != ltInt.end())
	{
		cout << *pos << " is prime" << endl;
	}
	else
	{
		cout << "not number is prime!" << endl;
	}

	getchar();

	return 0;
}