// 变序性算法
#pragma once
#ifndef _MUTATING_ALGO_HPP
#define _MUTATING_ALGO_HPP

#include "../public/headfile.hpp"

class CMutatingAlgoTest
{
public:
	// reverse and reverse_copy
	void test1()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt);

		reverse(vtInt.begin(), vtInt.end());
		printSTL(vtInt);

		reverse(++vtInt.begin(), --vtInt.end());
		printSTL(vtInt);

		reverse_copy(vtInt.begin(), vtInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	//rotate 旋转序列内的元素
	void test2()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt);

		rotate(vtInt.begin(), vtInt.begin() + 1, vtInt.end());
		printSTL(vtInt);

		rotate(vtInt.begin(), vtInt.end() - 2, vtInt.end());
		printSTL(vtInt);

		auto pos = find(vtInt.begin(), vtInt.end(), 4);
		rotate(vtInt.begin(), pos, vtInt.end() - 2);
		printSTL(vtInt);
	}

	//rotate_copy
	void test3()
	{
		set<int> stInt;
		insert_elements(stInt, 1, 9);
		printSTL(stInt);

		auto pos = stInt.begin();
		advance(pos, 1);
		rotate_copy(stInt.begin(), pos, stInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		pos = stInt.end();
		advance(pos, -2);
		rotate_copy(stInt.begin(), pos, stInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		pos = stInt.find(4);
		rotate_copy(stInt.begin(), pos, stInt.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	//next_permutation and prev_permutation
	void test4()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 3);
		printSTL(vtInt, "on entry: ");
		while (next_permutation(vtInt.begin(), vtInt.end()))
		{
			printSTL(vtInt);
		}
		printSTL(vtInt, "after: ");

		while (prev_permutation(vtInt.begin(), vtInt.end()))
		{
			printSTL(vtInt);
		}
		printSTL(vtInt, "now: ");

		while (prev_permutation(vtInt.begin(), vtInt.end()))
		{
			printSTL(vtInt);
		}
		printSTL(vtInt, "after: ");
	}

	class CMyRandom
	{
	public:
		ptrdiff_t operator()(ptrdiff_t max)
		{
			double temp;
			temp = static_cast<double>(rand()) / static_cast<ptrdiff_t>(RAND_MAX);
			return static_cast<ptrdiff_t>(temp * max);
		}
	};

	// random_shuffle and random_shuffle 打乱次序
	void test5()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		printSTL(vtInt, "vector: ");
		
		random_shuffle(vtInt.begin(), vtInt.end());
		printSTL(vtInt, "shuffled: ");

		sort(vtInt.begin(), vtInt.end());
		printSTL(vtInt, "sorted: ");

		CMyRandom rd;
		random_shuffle(vtInt.begin(), vtInt.end(), rd);
		printSTL(vtInt, "shuffed: ");
	}

	// partition and stable_partition
	void test6()
	{
		vector<int> vtInt1;
		vector<int> vtInt2;
		insert_elements(vtInt1, 1, 9);
		insert_elements(vtInt2, 1, 9);
		printSTL(vtInt1, "vtInt1: ");
		printSTL(vtInt2, "vtInt2: ");

		auto pos1 = partition(vtInt1.begin(), vtInt1.end(), bind2nd(modulus<int>(), 2));
		auto pos2 = stable_partition(vtInt2.begin(), vtInt2.end(), bind2nd(modulus<int>(), 2));

		printSTL(vtInt1, "vtInt1: ");
		cout << "first odd element: " << *pos1 << endl;

		printSTL(vtInt2, "vtInt2: ");
		cout << "first odd element: " << *pos2 << endl;
	}
};

#endif //_MUTATING_ALGO_HPP
