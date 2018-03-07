// 变动性算法
#pragma once
#ifndef _MODIFY_ALGO_HPP
#define _MODIFY_ALGO_HPP

#include "../public/headfile.hpp"

class CModifyAlgoTest
{
public:
	void test1()
	{
		vector<int> vtInt;
		insert_elements(vtInt, 1, 9);
		
		list<int> lstInt;
		copy(vtInt.begin(), vtInt.end(), back_inserter(lstInt));

	}
};

#endif // _MODIFY_ALGO_HPP
