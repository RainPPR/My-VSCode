#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int T,n,A;
map<int,int>mp;
void solve(){
	scanf("%d",&n);
	int ans = n,s = 0;
	mp.clear();
	mp[0] = 1;
	for(int i = 1;i <= n;i += 1){
		scanf("%d",&A);
		s ^= A;
		if(mp.find(s) != mp.end()){
			ans--;
			mp.clear();
			s = 0;
		}
		mp[s] = 1;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
