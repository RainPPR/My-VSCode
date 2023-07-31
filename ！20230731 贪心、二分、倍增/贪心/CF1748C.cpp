#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=2e5+10;
typedef long long ll;
map<ll,int>mp;
int T,n;
ll A[N],S[N];
void solve(){
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
		S[i]=S[i-1]+A[i];
	}
	int pos=1;
	while(A[pos]!=0&&pos<=n){
		if(S[pos]==0) ans++;
		pos++;
	}
	while(pos<=n){
		int nxt=pos+1,maxn=1;
		while(A[nxt]!=0&&nxt<=n) nxt++;
		for(int i=pos;i<nxt;i++){
			mp[S[i]]++;
			maxn=max(maxn,mp[S[i]]);
		}
		mp.clear();
		pos=nxt;
		ans+=maxn;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
