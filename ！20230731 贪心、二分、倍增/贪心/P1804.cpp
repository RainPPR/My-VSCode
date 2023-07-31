#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e6 + 6;
int n;
struct line{
	int l,r;
	friend bool operator < (const line a,const line b){
		return a.r < b.r;
	}
}A[N];
//这里介绍一个结构体的重定义运算符 
//使用 friend bool operator 加上要重定义的运算符 
//就能够定义结构体类型变量的运算 
//比如上述代码，此时 A[i] < A[j] 的含义就代表 A[i].r < A[j].r 
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i += 1)
		scanf("%d%d",&A[i].l,&A[i].r);
	sort(A + 1,A + 1 + n);
	int mr = 0,ans = 0;
	//mr 记录目前最大的右端点值为多少 
	for(int i = 1;i <= n;i += 1)
		if(A[i].l >= mr){
			mr = A[i].r;
			ans += 1;
		}
	printf("%d\n",ans);
	return 0;
}
