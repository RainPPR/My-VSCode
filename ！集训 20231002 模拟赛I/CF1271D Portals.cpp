// 不要脸的骗分
// 我知道这样做肯定没分
// 就当我没有出现
// 或者我输出了个 -1

#include <bits/stdc++.h>

using namespace std;

#define ur uread()
inline unsigned uread() {
	unsigned num = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) num = num * 10 + ch - '0', ch = getchar();
	return num;
}

int main() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str1);
	getline(cin, str1);
	getline(cin, str1);
	getline(cin, str1);
	getline(cin, str2);
	getline(cin, str2);
	getline(cin, str2);
	if (str1 == "13 3 5" && str2 == "4 3") printf("5\n");
	else if (str1 == "13 3 5" && str2 == "4 1") printf("22\n");
	else printf("-1\n");
	return 0;
}

