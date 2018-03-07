// 排序算法
#pragma once
#ifndef _SORT_ALGO_HPP
#define _SORT_ALGO_HPP

#include "../public/headfile.hpp"

class CSortAlgoTest
{
public:
	// sort
	void test1()
	{
		deque<int> deInt;
		insert_elements(deInt, 1, 9);
		insert_elements(deInt, 1, 9);
		printSTL(deInt, "on entry: ");

		sort(deInt.begin(), deInt.end());
		printSTL(deInt, "sorted: ");

		sort(deInt.begin(), deInt.end(), greater<int>());
		printSTL(deInt, "sort >: ");
	}

	// sort and stable_sort
	void test2()
	{
		vector<string> vtStr1 = { "1xxx", "2x", "3x", "4x", "5xx", "6xxxx", "7xx", "8xxx", "9xx", "10xxx", "11", "12", "13", "14xx", "15", "16", "17" };
		vector<string> vtStr2(vtStr1.begin(), vtStr1.end());
		printSTL(vtStr1, "on entry");

		sort(vtStr1.begin(), vtStr1.end(), [](const string &szStr1, const string &szStr2) { return szStr1.length() < szStr2.length(); });
		stable_sort(vtStr2.begin(), vtStr2.end(), [](const string &szStr1, const string &szStr2) {return szStr1.length() < szStr2.length(); });

		printSTL(vtStr1, "with sorted: ");
		printSTL(vtStr2, "with stable_sorted: ");
	}

	// partial_sort 局部排序
	void test3()
	{
		deque<int> deInt;
		insert_elements(deInt, 3, 7);
		insert_elements(deInt, 2, 6);
		insert_elements(deInt, 1, 5);
		printSTL(deInt);
		
		partial_sort(deInt.begin(), deInt.begin() + 5, deInt.end());
		printSTL(deInt);

		partial_sort(deInt.begin(), deInt.begin() + 5, deInt.end(), greater<int>());
		printSTL(deInt);

		partial_sort(deInt.begin(), deInt.end(), deInt.end());
		printSTL(deInt);
	}

	// partial_sort_copy
	void test4()
	{
		deque<int> deInt;
		insert_elements(deInt, 3, 7);
		insert_elements(deInt, 2, 6);
		insert_elements(deInt, 1, 5);
		printSTL(deInt);

		vector<int> vtInt6(6);
		auto pos6 = partial_sort_copy(deInt.begin(), deInt.end(), vtInt6.begin(), vtInt6.end());
		copy(vtInt6.begin(), pos6, ostream_iterator<int>(cout, " "));
		cout << endl;
		printSTL(vtInt6, "vtInt6: ");

		vector<int> vtInt30(30);
		auto pos30 = partial_sort_copy(deInt.begin(), deInt.end(), vtInt30.begin(), vtInt30.end());
		copy(vtInt30.begin(), pos30, ostream_iterator<int>(cout, " "));
		cout << endl;
		printSTL(vtInt30, "vtInt30: ");
	}

	// nth_element 根据第N个元素排序
	void test5()
	{
		deque<int> deInt;
		insert_elements(deInt, 3, 7);
		insert_elements(deInt, 2, 6);
		insert_elements(deInt, 1, 5);
		printSTL(deInt);

		nth_element(deInt.begin(), deInt.begin() + 3, deInt.end());
		cout << "the four lowest elements are: ";
		copy(deInt.begin(), deInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
		//printSTL(deInt);

		cout << "the highest elements are: ";
		copy(deInt.end() - 4, deInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		nth_element(deInt.begin(), deInt.begin() + 3, deInt.end(), greater<int>());
		cout << "the highest elements are: ";
		copy(deInt.begin(), deInt.begin() + 4, ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	// heap
	void test6()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 3, 7);
		insert_elements(vtInt, 5, 9);
		insert_elements(vtInt, 1, 4);
		printSTL(vtInt, "on entry: ");

		make_heap(vtInt.begin(), vtInt.end());
		printSTL(vtInt, "after make_heap(): ");

		pop_heap(vtInt.begin(), vtInt.end());
		vtInt.pop_back();
		printSTL(vtInt, "after pop_heap(): ");

		vtInt.push_back(17);
		push_heap(vtInt.begin(), vtInt.end());
		printSTL(vtInt, "after push_heap(): ");

		sort_heap(vtInt.begin(), vtInt.end());
		printSTL(vtInt, "afert sort_heap(): ");
	}
};

#endif // _SORT_ALGO_HPP