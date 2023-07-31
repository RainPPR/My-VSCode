#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e4+5;
int T,n;
struct node{
	ll A,B;
	int D;
	friend bool operator < (const node x,const node y){
		if(x.D != y.D) return x.D < y.D;
		if(x.D <= 0) return x.A < y.A;
		return x.B > y.B;
	}
}mini[N];
void solve(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i += 1){
		scanf("%lld%lld",&mini[i].A,&mini[i].B);
		if(mini[i].A == mini[i].B) mini[i].D = 0;
		else if(mini[i].A < mini[i].B) mini[i].D = -1;
		else mini[i].D = 1;
	}
	sort(mini + 1,mini + 1 + n);
	ll C = mini[1].A + mini[1].B,S = mini[1].A;
	for(int i = 2;i <= n;i += 1){
		S += mini[i].A;
		C = max(C,S) + mini[i].B;
	}
	printf("%lld\n",C);
}
int main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
