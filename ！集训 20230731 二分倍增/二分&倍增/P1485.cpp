#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=5e5+10;
typedef long long ll;
int n,k;
ll ans,m[N];
ll A[N],B[N],C[N]; 
bool check(ll mid){
	ll x=0,cnt=0;
	x=sqrt(mid)+1;
	for(int i=n;i>=1;i--){
		ll cur,now;
		if(i+x>n){
			cur=A[i+1]-B[i+1]*2*i+C[i+1]*i*i;
			now=C[i+1]; 
		}else{
			cur=A[i+1]-A[i+x]-(B[i+1]-B[i+x])*2*i+(C[i+1]-C[i+x])*i*i;
			now=C[i+1]-C[i+x];
		}
		ll tmp=(m[i]-now*mid+cur+mid)/mid;
		if(tmp<=0) tmp=0;
		cnt+=tmp;
		A[i]=A[i+1]+tmp*i*i;
		B[i]=B[i+1]+tmp*i;
		C[i]=C[i+1]+tmp;
	}
	return cnt<=k;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&m[i]);
	check(6);
	ll l=1,r=1e11;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
