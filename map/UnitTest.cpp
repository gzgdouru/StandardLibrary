#include "../public/headfile.hpp"

template<class K, class V>
class CFindValue
{
public:
	CFindValue(const V& value) :m_value(value)
	{

	}

	~CFindValue()
	{

	}

	bool operator() (pair<const K, V> elem)
	{
		return m_value == elem.second;
	}

private:
	V m_value;
};

void testOne()
{
	map<int, int>mpInt;
	for (int i = 1; i < 16; ++i)
	{
		mpInt.insert(make_pair(i, i + 10));
	}

	auto pos = mpInt.find(13);
	if (pos != mpInt.end())
	{
		cout << "find by key: key:" << pos->first << " value:" << pos->second << endl;
	}
	else
	{
		cout << "not find by key:13" << endl;
	}

	//pos = find_if(mpInt.begin(), mpInt.end(), CFindValue<int, int>(13));
	pos = find_if(mpInt.begin(), mpInt.end(),
		[](pair<int, int> values) { return values.second == 13; });
	if (pos != mpInt.end())
	{
		cout << "find by value: key:" << pos->first << " value:" << pos->second << endl;
	}
	else
	{
		cout << "not find by value:13" << endl;
	}
}

class CRuntimeCmp
{
public:
	enum CmpMode
	{
		e_normal = 1,
		e_nocase = 2
	};

public:
	CRuntimeCmp(CmpMode Mode) :m_eCmpMode(Mode)
	{

	}

	~CRuntimeCmp()
	{

	}

	bool operator() (const string &szStr1, const string &szStr2) const
	{
		bool bResult = false;
		if (e_normal == m_eCmpMode)
		{
			bResult = (szStr1 < szStr2);
		}
		else
		{
			bResult = lexicographical_compare(szStr1.begin(), szStr1.end(), szStr2.begin(), szStr2.end(), nocase_compare);
		}


		return bResult;
	}

private:
	static bool nocase_compare(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}

private:
	CmpMode m_eCmpMode;
};

void testTwo()
{
	map<string, string, CRuntimeCmp> mpStr1(CRuntimeCmp::e_normal);
	mpStr1["ouru"] = "test1";
	mpStr1["wancaiji"] = "test2";
	mpStr1["laopan"] = "test3";
	mpStr1["OuRu"] = "test4";

	cout << "mpStr1:" << endl;
	for (auto it = mpStr1.begin(); it != mpStr1.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

	map<string, string, CRuntimeCmp> mpStr2(CRuntimeCmp::e_nocase);
	mpStr2["ouru"] = "test1";
	mpStr2["wancaiji"] = "test2";
	mpStr2["laopan"] = "test3";
	mpStr2["OuRu"] = "test4";

	cout << "mpStr2:" << endl;
	for (auto it = mpStr2.begin(); it != mpStr2.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;

}

int main(int argc, char *argv[])
{
	testOne();

	getchar();

	return 0;
}