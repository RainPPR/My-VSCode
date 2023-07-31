#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n,cnt = 0,maxn[N],f[N];
struct node{
	int s,a,id;
	friend bool operator < (const node x,const node y){
		return x.a > y.a;
	}
}A[N];
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i += 1)
		scanf("%d",&A[i].s);
	for(int i = 1;i <= n;i += 1){
		scanf("%d",&A[i].a);
		if(A[i].s != A[i-1].s){
			A[i].id = ++cnt;
			f[cnt] = A[i].s;
		}
		else A[i].id = cnt;
		maxn[cnt] = max(A[i].a + A[i].s * 2,maxn[cnt]);
	}
	for(int i = cnt - 1;i >= 1;i -= 1)
		maxn[i] = max(maxn[i],maxn[i+1]);
	sort(A + 1,A + 1 + n);
	int sum = 0,ans,ms = 0;
	for(int i = 1;i <= n;i += 1){
		ans = sum + A[i].a + max(f[ms],A[i].s) * 2;
		ans = max(ans,sum + maxn[ms+1]);
		printf("%d\n",ans);
		sum += A[i].a;
		ms = max(ms,A[i].id);
	}
	return 0;
}
