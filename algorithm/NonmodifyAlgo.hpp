//非变动性算法
#pragma once
#ifndef _NON_MODIFY_ALGO_HPP
#define _NON_MODIFY_ALGO_HPP

#include "../public/headfile.hpp"

namespace nsNonmodifyAlgo
{
	bool isEven(int iElem)
	{
		return iElem % 2 == 0;
	}

	bool absLess(int x, int y)
	{
		return abs(x) < abs(y);
	}

	bool checkEven(int element, bool even)
	{
		bool bRes = even ? (element % 2 == 0) : (element % 2 == 1);
		return bRes;
	}

	bool doubled(int x, int y)
	{
		return x * 2 == y;
	}

	bool bothEvenOrdOdd(int x, int y)
	{
		return x % 2 == y % 2;
	}

	void printCollection(const list<int> &lstInt)
	{
		printSTL(lstInt);
	}

	bool lessForCollection(const list<int> &lstInt1, const list<int> &lstInt2)
	{
		return lexicographical_compare(lstInt1.begin(), lstInt1.end(), lstInt2.begin(), lstInt2.end());
	}
}

class CNonmodifyAlgoTest
{
public:
	void test1()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt);

		int iNum = count(vtInt.begin(), vtInt.end(), 4);
		cout << "number of elements equal to 4: " << iNum << endl;

		iNum = count_if(vtInt.begin(), vtInt.end(), nsNonmodifyAlgo::isEven);
		cout << "number of elements with even value:" << iNum << endl;

		iNum = count_if(vtInt.begin(), vtInt.end(), [](int x) { return x > 4; });
		//iNum = count_if(vtInt.begin(), vtInt.end(), bind2nd(greater<int>(), 4));
		cout << "number of elemnents greater than 4: " << iNum << endl;
	}

	void test2()
	{
		deque<int> deInt;
		insert_elements(deInt, 2, 8);
		insert_elements(deInt, -3, 5);
		printSTL(deInt);

		cout << "min: " << *min_element(deInt.begin(), deInt.end()) << endl;
		cout << "max: " << *max_element(deInt.begin(), deInt.end()) << endl;

		cout << "min of absolute values: " << *min_element(deInt.begin(), deInt.end(), nsNonmodifyAlgo::absLess) << endl;
		cout << "max of absolute values: " << *max_element(deInt.begin(), deInt.end(), nsNonmodifyAlgo::absLess) << endl;
	}

	void test3()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 9);
		insert_elements(lstInt, 1, 9);
		printSTL(lstInt);

		auto pos1 = find(lstInt.begin(), lstInt.end(), 4);
		auto pos2 = lstInt.end();
		if (pos1 != lstInt.end())
		{
			pos2 = find(++pos1, lstInt.end(), 4);
		}

		if (pos1 != lstInt.end() && pos2 != lstInt.end())
		{
			copy(--pos1, ++pos2, ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	void test4()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt);

		auto pos = find_if(vtInt.begin(), vtInt.end(), bind2nd(greater<int>(), 3));
		cout << "the " << distance(vtInt.begin(), pos) + 1 << ". element is the first greater than 3." << endl;
	}

	void test5()
	{
		deque<int> deInt;
		insert_elements(deInt, 1, 9);
		printSTL(deInt);

		auto pos = search_n(deInt.begin(), deInt.end(), 4, 3);
		if (pos != deInt.end())
		{
			cout << "four consecuitve elements wtih value 3 start with " << distance(deInt.begin(), pos) + 1 << ".element" << endl;
		}
		else
		{
			cout << "no four consecuitve elements with value 3 found" << endl;
		}

		pos = search_n(deInt.begin(), deInt.end(), 4, 3, greater<int>());
		if (pos != deInt.end())
		{
			cout << "four consecuitve elements wtih value >3 start with " << distance(deInt.begin(), pos) + 1 << ".element" << endl;
		}
		else
		{
			cout << "no four consecuitve elements with value 3 found" << endl;
		}
	}

	void test6()
	{
		deque<int> deInt;
		list<int> lstInt;
		insert_elements(deInt, 1, 7);
		insert_elements(deInt, 1, 7);
		insert_elements(lstInt, 3, 6);
		printSTL(deInt, "deque: ");
		printSTL(lstInt, "list: ");

		auto pos = search(deInt.begin(), deInt.end(), lstInt.begin(), lstInt.end());
		while (pos != deInt.end())
		{
			cout << "subcoll found start with element " << distance(deInt.begin(), pos) + 1 << endl;
			++pos;
			pos = search(pos, deInt.end(), lstInt.begin(), lstInt.end());
		}
	}

	void test7()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt);

		bool checkEvenArgs[3] = { true, false, true };
		auto pos = search(vtInt.begin(), vtInt.end(), checkEvenArgs, checkEvenArgs + 3, nsNonmodifyAlgo::checkEven);
		while (pos != vtInt.end())
		{
			cout << "sub range found start with element " << distance(vtInt.begin(), pos) + 1 << endl;
			pos = search(++pos, vtInt.end(), checkEvenArgs, checkEvenArgs + 3, nsNonmodifyAlgo::checkEven);
		}
	}

	void test8()
	{
		deque<int> deInt;
		insert_elements(deInt, 1, 7);
		insert_elements(deInt, 1, 7);
		printSTL(deInt, "deque: ");

		list<int> lstInt;
		insert_elements(lstInt, 3, 6);
		printSTL(lstInt, "list: ");

		auto pos = find_end(deInt.begin(), deInt.end(), lstInt.begin(), lstInt.end());
		auto end = deInt.end();
		while (pos != end)
		{
			cout << "subcoll found start with element " << distance(deInt.begin(), pos) + 1 << endl;
			end = pos;
			pos = find_end(deInt.begin(), end, lstInt.begin(), lstInt.end());
		}
	}

	void test9()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 11);
		printSTL(vtInt, "vector: ");

		list<int> lstInt = {3, 5};
		//insert_elements(lstInt, 3, 5);
		printSTL(lstInt, "list: ");

		auto pos = find_first_of(vtInt.begin(), vtInt.end(), lstInt.begin(), lstInt.end());
		cout << "first element of searchcoll in coll is element " << distance(vtInt.begin(), pos) + 1 << endl;

		vector<int>::reverse_iterator rpos = find_first_of(vtInt.rbegin(), vtInt.rend(), lstInt.begin(), lstInt.end());
		cout << "last element of searchcoll in coll is element " << distance(vtInt.begin(), rpos.base()) << endl;
	}

	//查找两个连续且相等的元素
	void test10()
	{
		vector<int> vtInt = { 1, 3, 2, 4, 5, 5, 0 };
		printSTL(vtInt);

		auto pos = adjacent_find(vtInt.begin(), vtInt.end());
		if (pos != vtInt.end())
		{
			cout << "first two elements with equal value have position " << distance(vtInt.begin(), pos) + 1 << endl;
		}

		pos = adjacent_find(vtInt.begin(), vtInt.end(), nsNonmodifyAlgo::doubled);
		if (pos != vtInt.end())
		{
			cout << "first two elements with second value twice the first have pos." << distance(vtInt.begin(), pos) + 1 << endl;
		}
	}
	
	//检验区间相等性
	void test11()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 7);
		printSTL(vtInt, "vector: ");

		list<int> lstInt;
		insert_elements(lstInt, 3, 9);
		printSTL(lstInt, "list: ");

		if (equal(vtInt.begin(), vtInt.end(), lstInt.begin()))
		{
			cout << "vtInt == lstInt" << endl;
		}
		else
		{
			cout << "vtInt != lstInt" << endl;
		}

		//if (equal(vtInt.begin(), vtInt.end(), lstInt.begin(), lstInt.end(), nsNonmodifyAlgo::bothEvenOrdOdd))
		if (equal(vtInt.begin(), vtInt.end(), lstInt.begin(), nsNonmodifyAlgo::bothEvenOrdOdd))
		{
			cout << "even and odd elements correspond" << endl;
		}
		else
		{
			cout << "even and odd elements do not correspond" << endl;
		}
	}

	// 查找第一处不同点
	void test12()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 6);
		printSTL(vtInt, "vector: ");

		list<int> lstInt;
		for (int i = 1; i <= 16; i *= 2)
		{
			lstInt.push_back(i);
		}
		lstInt.push_back(3);
		printSTL(lstInt, "list: ");

		auto value = mismatch(vtInt.begin(), vtInt.end(), lstInt.begin());
		if (value.first == vtInt.end())
		{
			cout << "not mismatch...." << endl;
		}
		else
		{
			cout << "first mismatch: " << *value.first << " and " << *value.second << endl;
		}

		value = mismatch(vtInt.begin(), vtInt.end(), lstInt.begin(), less_equal<int>());
		if (value.first == vtInt.end())
		{
			cout << "always less-or-equal: " << endl; 
		}
		else
		{
			cout << distance(vtInt.begin(), value.first) + 1 << endl;
			cout << "not less-or-equal: " << *value.first << " and " << *value.second << endl;
		}
	}

	// 检验"小于"
	void test13()
	{
		list<int> l1, l2, l3, l4;
		insert_elements(l1, 1, 5);
		l4 = l3 = l2 = l1;
		l1.push_back(7);
		l3.push_back(2);
		l3.push_back(0);
		l4.push_back(2);

		vector<list<int> > vtLst = { l1, l2, l3, l4, l3, l1, l4 ,l2 };
		for_each(vtLst.begin(), vtLst.end(), nsNonmodifyAlgo::printCollection);
		cout << endl;

		sort(vtLst.begin(), vtLst.end(), nsNonmodifyAlgo::lessForCollection);
		for_each(vtLst.begin(), vtLst.end(), nsNonmodifyAlgo::printCollection);
	}
};

#endif //_NON_MODIFY_ALGO_HPP
