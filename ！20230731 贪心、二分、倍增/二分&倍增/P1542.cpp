#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+10;
typedef long long ll;
typedef long double ld;
int n;
ll ans;
ld x[N],y[N],s[N];
bool check(ld mid){
	ld t=0;
	for(int i=1;i<=n;i++){
		t+=s[i]/mid;
		if(t>y[i]) return false;
		if(t<x[i]) t=x[i];
	}
	return true;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>s[i];
	ll l=1,r=1e18;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid/100000.0)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%.2lf\n",ans/100000.0);
	return 0;
}
