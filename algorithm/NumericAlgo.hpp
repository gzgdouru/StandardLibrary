// ÊýÖµËã·¨
#pragma once
#ifndef _NUMERIC_ALGO_HPP
#define _NUMERIC_ALGO_HPP

#include "../public/headfile.hpp"

class CNumericAlgoTest
{
public:
	// accumulate
	void test1()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt);

		cout << "sum:" << accumulate(vtInt.begin(), vtInt.end(), 0) << endl;
		cout << "sum:" << accumulate(vtInt.begin(), vtInt.end(), -100) << endl;
		cout << "product:" << accumulate(vtInt.begin(), vtInt.end(), 1, multiplies<int>()) << endl;
		cout << "product:" << accumulate(vtInt.begin(), vtInt.end(), 0, multiplies<int>()) << endl;
	}

	void test2()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 6);
		printSTL(lstInt);

		// 0 + 1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6
		cout << "inner product:" << inner_product(lstInt.begin(), lstInt.end(), lstInt.begin(), 0) << endl;

		// 0 + 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1
		cout << "inner reverse product:" << inner_product(lstInt.begin(), lstInt.end(), lstInt.rbegin(), 0) << endl;

		// 1 * (1+1) * (2+2) * (3+3) * (4+4) * (5+5) * (6+6)
		cout << "product of sums:" << inner_product(lstInt.begin(), lstInt.end(), lstInt.begin(), 1, multiplies<int>(), plus<int>()) << endl;
	}

	//partial_sum
	void test3()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 10);
		printSTL(vtInt);

		partial_sum(vtInt.begin(), vtInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		partial_sum(vtInt.begin(), vtInt.end(), ostream_iterator<int>(cout, " "), multiplies<int>());
		cout << endl;
	}

	//adjacent_difference
	void test4()
	{
		deque<int> deInt;
		insert_elements(deInt, 1, 6);
		printSTL(deInt);

		adjacent_difference(deInt.begin(), deInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		adjacent_difference(deInt.begin(), deInt.end(), ostream_iterator<int>(cout, " "), plus<int>());
		cout << endl;

		adjacent_difference(deInt.begin(), deInt.end(), ostream_iterator<int>(cout, " "), multiplies<int>());
		cout << endl;
	}

	void test5()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 6);
		printSTL(vtInt);

		adjacent_difference(vtInt.begin(), vtInt.end(), vtInt.begin());
		printSTL(vtInt);

		partial_sum(vtInt.begin(), vtInt.end(), vtInt.begin());
		printSTL(vtInt);
	}
};

#endif //_NUMERIC_ALGO_HPP
