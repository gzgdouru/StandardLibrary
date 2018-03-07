//已序区间算法
#pragma once
#ifndef _SORTED_RANGE_ALGO_HPP
#define _SORTED_RANGE_ALGO_HPP

#include "../public/headfile.hpp"

class CSortRangeAlgoTest
{
public:
	//binary_search
	void test1()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 9);
		insert_elements(lstInt, 3, 7);
		lstInt.sort();
		printSTL(lstInt);

		bool bRes = binary_search(lstInt.begin(), lstInt.end(), 5);
		string szRes = bRes ? "5 is present" : "5 is not present";
		cout << szRes << endl;

		bRes = binary_search(lstInt.begin(), lstInt.end(), 42);
		szRes = bRes ? "42 is present" : "42 is not present";
		cout << szRes << endl;
	}

	// includes	
	void test2()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 9);
		printSTL(lstInt, "list:");

		vector<int> vtInt = { 3, 4, 7};
		printSTL(vtInt, "vector:");

		bool bRes = includes(lstInt.begin(), lstInt.end(), vtInt.begin(), vtInt.end());
		string szRes = bRes ? "all elements of search are also in coll" : "not all elements of search are also in coll";
		cout << szRes << endl;
	}

	// lower_bound and upper_bound
	void test3()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 9);
		insert_elements(lstInt, 1, 9);
		lstInt.sort();
		printSTL(lstInt);

		auto pos1 = lower_bound(lstInt.begin(), lstInt.end(), 5);
		auto pos2 = upper_bound(lstInt.begin(), lstInt.end(), 5);

		cout << "5 could get position " << distance(lstInt.begin(), pos1) + 1 << " up to "
			<< distance(lstInt.begin(), pos2) + 1 << " without breaking the sorting" << endl;

		pos1 = lower_bound(lstInt.begin(), lstInt.end(), 3);
		pos2 = upper_bound(lstInt.begin(), lstInt.end(), 7);
		
		lstInt.insert(pos1, 3);
		lstInt.insert(pos2, 7);
		printSTL(lstInt);
	}

	// equal_range
	void test4()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 9);
		insert_elements(lstInt, 1, 9);
		lstInt.sort();
		printSTL(lstInt);

		auto range = equal_range(lstInt.begin(), lstInt.end(), 5);
		cout << "5 could get position " << distance(lstInt.begin(), range.first) + 1 << " up to "
			<< distance(lstInt.begin(), range.second) + 1 << " without breaking the sorting" << endl;
	}

	// merge
	void test5()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 6);
		printSTL(lstInt, "list:");

		set<int> stInt;
		insert_elements(stInt, 3, 11);
		printSTL(stInt, "set:");

		cout << "merge:";
		merge(lstInt.begin(), lstInt.end(), stInt.begin(), stInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	void test6()
	{
		vector<int> vtInt1 = { 1, 2, 2, 4, 6, 7, 7, 9, 10, 12};
		vector<int> vtInt2 = { 2, 2, 2, 3, 6, 6, 8, 9 };

		printSTL(vtInt1, "vtInt1:");
		printSTL(vtInt2, "vtInt2:");

		// 合并
		cout << "merge():";
		merge(vtInt1.begin(), vtInt1.end(), vtInt2.begin(), vtInt2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		// 取并集
		cout << "set_union():";
		set_union(vtInt1.begin(), vtInt1.end(), vtInt2.begin(), vtInt2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		// 取交集
		cout << "set_intersection():";
		set_intersection(vtInt1.begin(), vtInt1.end(), vtInt2.begin(), vtInt2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		// 取差集
		cout << "set_difference():";
		//set_difference(vtInt1.begin(), vtInt1.end(), vtInt2.begin(), vtInt2.end(), ostream_iterator<int>(cout, " "));
		set_difference(vtInt2.begin(), vtInt2.end(), vtInt1.begin(), vtInt1.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		// 取不同时存在两组的值
		cout << "set_symmetric_difference():";
		set_symmetric_difference(vtInt1.begin(), vtInt1.end(), vtInt2.begin(), vtInt2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	//inplace_merge
	void test7()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 7);
		insert_elements(lstInt, 1, 8);
		printSTL(lstInt);

		auto pos = find(lstInt.begin(), lstInt.end(), 7);
		inplace_merge(lstInt.begin(), ++pos, lstInt.end());
		//++pos;
		//merge(lstInt.begin(), pos, pos, lstInt.end(), ostream_iterator<int>(cout, " "));
		printSTL(lstInt);
	}

	void test8()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 7);
		insert_elements(lstInt, 1, 8);
		printSTL(lstInt);

		auto pos = find(lstInt.begin(), lstInt.end(), 7);
		++pos;
		merge(lstInt.begin(), pos, pos, lstInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
};

#endif //_SORTED_RANGE_ALGO_HPP
