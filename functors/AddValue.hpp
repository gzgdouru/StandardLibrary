#ifndef _ADD_VALUE_HPP

#include "../public/headfile.hpp"

class CPrintInt
{
public:
	CPrintInt() {}
	~CPrintInt() {}

	void operator() (int i)
	{
		cout << i << " ";
	}
};

class CAddValue
{
public:
	CAddValue(int iValue) :m_iVaule(iValue) {}
	~CAddValue() {}

	void operator() (int &iValue) const
	{
		iValue += m_iVaule;
	}

	void setValue(int iValue)
	{
		m_iVaule = iValue;
	}

private:
	int m_iVaule;
};

class CAddValueTest
{
public:
	void test1()
	{
		vector<int> vtInt{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		for_each(vtInt.begin(), vtInt.end(), CPrintInt());
		cout << endl;
	}

	void test2()
	{
		list<int> ltInt{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		printSTL(ltInt, "init:");

		CAddValue AddValue(10);

		for_each(ltInt.begin(), ltInt.end(), AddValue);
		printSTL(ltInt, "after add 10:");

		AddValue.setValue(15);
		for_each(ltInt.begin(), ltInt.end(), AddValue);
		printSTL(ltInt, "after add 15:");

		for_each(ltInt.begin(), ltInt.end(), CAddValue(*ltInt.begin()));
		printSTL(ltInt, "after add first element:");
	}

	void test3()
	{
		set<int, greater<int> > stInt{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		printSTL(stInt, "init set:");

		deque<int> dqInt;
		transform(stInt.begin(), stInt.end(), back_inserter(dqInt), bind2nd(multiplies<int>(), 10));
		printSTL(dqInt, "transfrom:");

		replace_if(dqInt.begin(), dqInt.end(), bind2nd(equal_to<int>(), 70), 42);
		printSTL(dqInt, "replace:");

		//dqInt.erase(remove_if(dqInt.begin(), dqInt.end(), bind2nd(less<int>(), 50)), dqInt.end());
		std::function<bool(int&)> f = std::bind([](int& x, int& y) { return x < y; }, placeholders::_1, 50);
		dqInt.erase(remove_if(dqInt.begin(), dqInt.end(), f), dqInt.end());
		printSTL(dqInt, "remove:");
	}
};

#define _ADD_VALUE_HPP
#endif // _ADD_VALUE_HPP
