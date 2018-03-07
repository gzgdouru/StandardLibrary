#ifndef _FOREACH_THREE_HPP
#define _FOREACH_THREE_HPP

#include "../public/headfile.hpp"

class CMeanValue
{
private:
	long m_lNum;
	long m_lSum;
public:
	CMeanValue() :
		m_lNum(0), m_lSum(0)
	{

	}

	void operator()(int iElem)
	{
		++m_lNum;
		m_lSum += iElem;
	}

	double value()
	{
		return static_cast<double>(m_lSum);
	}
};

class CForeachThreeTest
{
public: 
	void test1()
	{
		vector<int> vtInt = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		CMeanValue mv = for_each(vtInt.begin(), vtInt.end(), CMeanValue());
		cout << "mean value:" << mv.value() << endl;
	}
};

#endif // _FOREACH_THREE_HPP