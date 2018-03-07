// for_eachÀ„∑®
#pragma once
#ifndef _FOREACH_HPP
#define _FOREACH_HPP

#include "../public/headfile.hpp"

namespace nsForeach
{
	void print(int iElem)
	{
		cout << iElem << " ";
	}
};

template<class T>
class CAddValue
{
private:
	T value;
public:
	CAddValue(const T& v) :
		value(v)
	{

	}

	void operator()(int &iElem)
	{
		iElem += value;
	}
};

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

	operator double()
	{
		return static_cast<double>(m_lSum);
	}
};

class CForeachTest
{
public:
	void test1()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		for_each(vtInt.begin(), vtInt.end(), nsForeach::print);
		cout << endl;
	}

	void test2()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		std::function<void(int& iElem)> func = std::bind([](int &x, int y) { x += y; }, std::placeholders::_1, 10);
		for_each(vtInt.begin(), vtInt.end(), func);
		//for_each(vtInt.begin(), vtInt.end(), [](int &iElem) { iElem += 10; });
		//for_each(vtInt.begin(), vtInt.end(), CAddValue<int>(10));
		for_each(vtInt.begin(), vtInt.end(), nsForeach::print);
		cout << endl;
	}

	void test3()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 10);
		CMeanValue meanValue;
		double mv = for_each(vtInt.begin(), vtInt.end(), CMeanValue());
		cout << "sum: " << mv << endl;
	}
};

#endif // _FOREACH_HPP
