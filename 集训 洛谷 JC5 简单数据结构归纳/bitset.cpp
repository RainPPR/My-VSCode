#include <bitset>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// 1 位占用一个 bit
	bitset<10000000> b;

	// b.set(pos, value): 把第 pos 位修改为 value
	b.set(1, 1);
	
	// b.test(pos): 返回第 pos 位的值
	cout << b.test(0) << endl;
	cout << b.test(1) << endl;
	return 0;
}
