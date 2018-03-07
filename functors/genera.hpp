#ifndef _GENERA_HPP
#define _GENERA_HPP

#include "../public/headfile.hpp"

class CIntSequeue
{
private:
	int m_iValue;

public:
	CIntSequeue(int iValue) :
		m_iValue(iValue)
	{

	}

	int operator()()
	{
		return m_iValue++;
	}
};

class CGeneraTest
{
public:
	void test1()
	{
		list<int> lstInt;
		generate_n(back_inserter(lstInt), 9, CIntSequeue(1));
		printSTL(lstInt);

		generate(++lstInt.begin(), --lstInt.end(), CIntSequeue(42));
		printSTL(lstInt);
	}

	void test2()
	{
		list<int> lstInt;
		CIntSequeue IntSequeue(1);

		generate_n(back_inserter(lstInt), 9, IntSequeue);
		printSTL(lstInt);

		generate_n(back_inserter(lstInt), 9, IntSequeue);
		printSTL(lstInt);
	}

	void test3()
	{
		list<int> lstInt;
		CIntSequeue IntSequeue(1);

		generate_n<back_insert_iterator<list<int> >, int, CIntSequeue&>(back_inserter(lstInt), 4, IntSequeue);
		printSTL(lstInt);

		generate_n(back_inserter(lstInt), 4, CIntSequeue(42));
		printSTL(lstInt);

		generate_n(back_inserter(lstInt), 4, IntSequeue);
		printSTL(lstInt);
	}
};

#endif //_GENERA_HPP