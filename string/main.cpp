#include "../public/headfile.hpp"

void reverse_print(const string &szStr, const string &szdelims)
{
	int begIdx = szStr.find_first_not_of(szdelims);
	while (begIdx != string::npos)
	{
		int endIdx = szStr.find_first_of(szdelims, begIdx);
		if (endIdx == string::npos)
		{
			endIdx = szStr.size();
		}

		for (int i = endIdx - 1; i >= begIdx ; --i)
		{
			cout << szStr[i];
		}
		cout << " ";

		begIdx = szStr.find_first_not_of(szdelims, endIdx);
	}
	cout << endl;
}

void test1()
{
	string szStr = "abcde";

	char &r = szStr[2];
	char *p = &szStr[3];

	r = 'X';
	*p = 'Y';
	cout << szStr << endl;

	szStr = "fghijk";
	cout << szStr << endl;

	cout << r << endl;
	cout << *p << endl;
	r = 'H';
	*p = 'Y';
	cout << szStr << endl;
}

//compare
void test2()
{
	string szStr = "abcd";

	cout << szStr.compare("abcd") << endl;
	cout << szStr.compare("dcba") << endl;
	cout << szStr.compare("ab") << endl;

	cout << szStr.compare(szStr) << endl;
	cout << szStr.compare(0, 2, szStr, 2, 2) << endl; // ab cd
	cout << szStr.compare(1, 2, "bcx", 2) << endl;	// bc	bc
}

// assign
void test3()
{
	string szStr = "othello";

	string szTmp = szStr;
	cout << szTmp << endl;

	szTmp = "two\nlines";
	cout << szTmp << endl;

	szTmp.assign(szStr);
	cout << szTmp << endl;

	szTmp.assign(szStr, 1, 3);
	cout << szTmp << endl;

	szTmp.assign(szStr, 2, string::npos);
	cout << szTmp << endl;

	szTmp.assign("two\nlines");
	cout << szTmp << endl;

	szTmp.assign("nico", 5);
	cout << szTmp << endl;

	szTmp.assign(5, 'x');
	cout << szTmp << endl;
}

bool nocase_compare(const char& c1, const char &c2)
{
	return tolower(c1) == tolower(c2);
}

void test4()
{
	string szStr = "this is a string";
	string szSubStr = "STRING";

	if (szStr.size() == szSubStr.size() && 
		equal(szStr.begin(), szStr.end(), szSubStr.begin(), nocase_compare))
	{
		cout << "the string are equal" << endl;
	}
	else
	{
		cout << "the string are not equal" << endl;
	}

	auto pos = search(szStr.begin(), szStr.end(), szSubStr.begin(), szSubStr.end(), nocase_compare);
	if (pos == szStr.end())
	{
		cout << "[" << szSubStr << "] is not a substring of [" << szStr  << "]" << endl;
	}
	else
	{
		cout << "[" << szSubStr << "] is  a substring of " << "[" << szStr << "] at index " << pos - szStr.begin() << endl;
	}
}

	
int main(int argc, char *argv[])
{
	//reverse_print("hello,hi dashabi;nihaihs.shg", " \t,.;");
	test4();

	getchar();
	return 0;
}