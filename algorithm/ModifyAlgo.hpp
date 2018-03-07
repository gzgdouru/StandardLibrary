// 变动性算法
#pragma once
#ifndef _MODIFY_ALGO_HPP
#define _MODIFY_ALGO_HPP

#include "../public/headfile.hpp"

class CModifyAlgoTest
{
public:
	// copy
	void test1()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		
		list<int> lstInt;
		copy(vtInt.begin(), vtInt.end(), back_inserter(lstInt));
		copy(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		//copy(vtInt.rbegin(), vtInt.rend(), lstInt.begin());
		reverse_copy(vtInt.begin(), vtInt.end(), lstInt.begin());
		copy(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	//copy and copy_backward
	void test2()
	{
		vector<char> vtSource(10, '.');
		for (int c = 'a'; c <= 'f'; ++c)
		{
			vtSource.push_back(c);
		}
		vtSource.insert(vtSource.end(), 10, '.');
		printSTL(vtSource, "source: ");

		vector<char> c1(vtSource.begin(), vtSource.end());
		copy(vtSource.begin() + 10, vtSource.begin() + 16, c1.begin() + 7);
		printSTL(c1, "c1: ");

		vector<char>c2(vtSource.begin(), vtSource.end());
		copy_backward(vtSource.begin() + 10, vtSource.begin() + 16, c2.begin() + 19);
		printSTL(c2, "c2: ");
	}

	//transfrom
	void test3()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt, "vector: ");

		list<int> lstInt;

		//transform(vtInt.begin(), vtInt.end(), vtInt.begin(), negate<int>());
		transform(vtInt.begin(), vtInt.end(), vtInt.begin(), [](int x) { return x *= -1; });
		printSTL(vtInt, "vector negate: ");

		transform(vtInt.begin(), vtInt.end(), back_inserter(lstInt), bind2nd(multiplies<int>(), 10));
		printSTL(lstInt, "list: ");

		transform(lstInt.rbegin(), lstInt.rend(), ostream_iterator<int>(cout, " "), negate<int>());
		cout << endl;
	}

	//transfrom
	void test4()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt, "vector: ");

		transform(vtInt.begin(), vtInt.end(), vtInt.begin(), vtInt.begin(), multiplies<int>());
		printSTL(vtInt, "vector multiplies: ");

		list<int> lstInt;
		transform(vtInt.begin(), vtInt.end(), vtInt.rbegin(), back_inserter(lstInt), plus<int>());
		printSTL(lstInt, "list: ");

		cout << "diff: ";
		transform(vtInt.begin(), vtInt.end(), lstInt.begin(), ostream_iterator<int>(cout, " "), minus<int>());
		cout << endl;
	}

	// swap_ranges
	void test5()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);

		deque<int> deInt;
		insert_elements(deInt, 11, 23);

		printSTL(vtInt, "vector: ");
		printSTL(deInt, "deque: ");

		auto pos = swap_ranges(vtInt.begin(), vtInt.end(), deInt.begin());
		printSTL(vtInt, "vector: ");
		printSTL(deInt, "deque: ");
		if (pos != deInt.end())
		{
			cout << "first element not modified: " << *pos << endl;
		}

		swap_ranges(deInt.begin(), deInt.begin() + 3, deInt.rbegin());
		printSTL(deInt, "deque: ");
	}

	// fill and fill_n
	void test6()
	{
		fill_n(ostream_iterator<float>(cout, " "), 10, 7.7);
		cout << endl;

		list<string> lstStr;
		fill_n(back_inserter(lstStr), 9, "hello");
		printSTL(lstStr, "list: ");

		fill(lstStr.begin(), lstStr.end(), "again");
		printSTL(lstStr, "list: ");

		fill_n(lstStr.begin(), lstStr.size() - 2, "hi");
		printSTL(lstStr, "list: ");

		auto start = lstStr.begin();
		auto end = lstStr.end();
		fill(++start, --end, "hmmm");
		printSTL(lstStr, "list: ");
	}

	// generate and generate_n
	void test7()
	{
		list<int> lstInt;
		generate_n(back_inserter(lstInt), 5, rand);
		printSTL(lstInt);

		generate(lstInt.begin(), lstInt.end(), rand);
		printSTL(lstInt);
	}

	//repacle and repace_if
	void test8()
	{
		list<int> lstInt;
		insert_elements(lstInt, 2, 7);
		insert_elements(lstInt, 4, 9);
		printSTL(lstInt);

		replace(lstInt.begin(), lstInt.end(), 4, 42);
		printSTL(lstInt);

		replace_if(lstInt.begin(), lstInt.end(), bind2nd(less<int>(), 5), 0);
		printSTL(lstInt);
	}

	//replace_copy and replace_copy_if
	void test9()
	{
		list<int> lstInt;
		insert_elements(lstInt, 2, 6);
		insert_elements(lstInt, 4, 9);
		printSTL(lstInt);

		replace_copy(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "), 5, 55);
		cout << endl;

		replace_copy_if(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "), bind2nd(less<int>(), 5), 42);
		cout << endl;

		replace_copy_if(lstInt.begin(), lstInt.end(), ostream_iterator<int>(cout, " "), bind2nd(modulus<int>(), 2), 0);
		cout << endl;
	}
};

#endif // _MODIFY_ALGO_HPP
