//“∆≥˝–‘À„∑®
#pragma once
#ifndef _REMOVE_ALGO_HPP
#define _REMOVE_ALGO_HPP

#include "../public/headfile.hpp"

class CRmoveAlgoTest
{
public:
	// remove and remove_if
	void test1()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 2, 6);
		insert_elements(vtInt, 4, 9);
		insert_elements(vtInt, 1, 7);
		printSTL(vtInt, "vector: ");

		auto pos = remove(vtInt.begin(), vtInt.end(), 5);
		printSTL(vtInt, "size not change: ");
		vtInt.erase(pos, vtInt.end());
		printSTL(vtInt, "size changed: ");

		pos = remove_if(vtInt.begin(), vtInt.end(), bind2nd(less<int>(), 0));
		vtInt.erase(pos, vtInt.end());
		printSTL(vtInt, "<4 remove: ");
	}

	// remove_copy and remove_copy_if
	void test2()
	{
		list<int> lstInt;
		insert_elements(lstInt, 1, 6);
		insert_elements(lstInt, 1, 9);
		printSTL(lstInt);

		remove_copy(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "), 3);
		cout << endl;

		remove_copy_if(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "), bind2nd(greater<int>(), 4));
		cout << endl;

		multiset<int> coll2;
		remove_copy_if(lstInt.begin(), lstInt.end(), inserter(coll2, coll2.end()), bind2nd(less<int>(), 4));
		printSTL(coll2);
	}

	// unique
	void test3()
	{
		list<int> lstTmp = { 1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4 };
		list<int> lstInt(lstTmp.begin(), lstTmp.end());
		printSTL(lstInt);

		auto pos = unique(lstInt.begin(), lstInt.end());
		copy(lstInt.begin(), pos, ostream_iterator<int>(cout, " "));
		cout << endl;

		lstInt.resize(lstTmp.size());
		lstInt.assign(lstTmp.begin(), lstTmp.end());
		pos = unique(lstInt.begin(), lstInt.end(), greater<int>());
		lstInt.erase(pos, lstInt.end());
		printSTL(lstInt);
	}

	//unique_copy
	void test4()
	{
		list<int> lstSource = { 1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4 };
		list<int> lstInt(lstSource.begin(), lstSource.end());
		printSTL(lstInt);

		unique_copy(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		unique_copy(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "), 
			[](int x, int y) { return x + 1 == y || x - 1 == y; });
		cout << endl;
	}
};

#endif // _REMOVE_ALGO_HPP