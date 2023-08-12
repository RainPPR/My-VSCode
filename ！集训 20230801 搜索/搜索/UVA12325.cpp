#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll t,n,s1,v1,s2,v2,cnt;
void solve(){
	scanf("%lld%lld%lld%lld%lld",&n,&s1,&v1,&s2,&v2);
	ll ans=0;
	if(s1>=n/s1){
		for(int i=0;s1*i<=n;i++)
			ans=max(ans,i*v1+(n-s1*i)/s2*v2);
	}else if(s2>=n/s2){
		for(int i=0;s2*i<=n;i++)
			ans=max(ans,i*v2+(n-s2*i)/s1*v1);
	}else{
		//取 s2 个 1 和取 s1 个 2 占的体积是相同的 
		//那么考虑比较 s1*v2 和 s2*v1 的相对大小关系 
		//如果 s1*v2 大，那么 1 至多取 s2-1 个 
		if(s1*v2>s2*v1){
			for(int i=0;i<s2;i++)
				ans=max(ans,v1*i+(n-s1*i)/s2*v2);
		}else{
			for(int i=0;i<s1;i++)
				ans=max(ans,v2*i+(n-s2*i)/s1*v1);
		}
	}
	cnt++;
	printf("Case #%lld: %lld\n",cnt,ans);
}
int main(){
	scanf("%lld",&t);
	cnt=0;
	while(t--) solve();
	return 0;
}
