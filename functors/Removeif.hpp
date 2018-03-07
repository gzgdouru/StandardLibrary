#pragma once
#ifndef _REMOVE_IF_HPP
#define _REMOVE_IF_HPP

#include "../public/headfile.hpp"

class CNth
{
private:
	int m_iNth;
	int m_iCount;
public:
	CNth(int iNth) :
		m_iNth(iNth), m_iCount(0)
	{

	}

	bool operator()(int)
	{
		return ++m_iCount == m_iNth;
	}
};

class CRemoveifTest
{
public:
	void test1()
	{
		list<int> lstInt = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		printSTL(lstInt, "coll: ");

		auto pos = remove_if(lstInt.begin(), lstInt.end(), CNth(3));
		printSTL(lstInt, "before erase: ");
		cout << lstInt.size() << endl;
		lstInt.erase(pos, lstInt.end());
		printSTL(lstInt, "nth removed: ");
		cout << lstInt.size() << endl;
	}
};

#endif //_REMOVE_IF_HPP
