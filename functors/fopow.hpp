// 定制可用于函数配接器(bind1st, bind2nd.....)的仿函数
#pragma once
#ifndef _FOPOW_HPP
#define _FOPOW_HPP

#include "../public/headfile.hpp"

template<class T1, class T2>
struct fopow : public std::binary_function<T1, T2, T1>
{
	T1 operator()(T1 base, T2 exp) const
	{
		return pow(base, exp);
	}
};

class CFopowTest
{
public:
	void test1()
	{
		vector<int> vtInt = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		transform(vtInt.begin(), vtInt.end(), ostream_iterator<int>(cout, " "), bind1st(fopow<float, int>(), 3));
		cout << endl;

		std::function<int(int)> func = std::bind(fopow<float, int>(), std::placeholders::_1, 3);
		transform(vtInt.begin(), vtInt.end(), ostream_iterator<int>(cout, " "), func);
		cout << endl;

		transform(vtInt.begin(), vtInt.end(), ostream_iterator<int>(cout, " "), bind2nd(fopow<float, int>(), 3));
		cout << endl;
	}
};

#endif // _FOPOW_HPP
