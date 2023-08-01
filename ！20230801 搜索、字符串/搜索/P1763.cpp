#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a,b;
int dep;
ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}
int B[10000],ans[10000];
bool check(){
	return ans[dep]==-1||B[dep]<ans[dep];
}
int getmin(ll aa,ll bb){
	return (bb+aa-1)/aa;
}
bool dfs(int now,int lst,ll aa,ll bb){
	if(now==dep){
		if(aa!=1||bb<=lst) return false;
		B[now]=bb;
		if(check())
			for(int i=1;i<=dep;i++)
				ans[i]=B[i];
		return true;
	}
	bool ok=false;
	lst=max(lst,getmin(aa,bb));
	if(lst>=1e7) return false;
	for(int i=lst;;i++){
		//Èç¹û (dep-now+1)/i<aa/bb£¬¼´(dep-now+1)*bb<aa*i 
		if((dep-now+1)*bb<=i*aa) break;
		ll nb=bb*i;
		ll na=aa*i-bb;
		ll g=gcd(na,nb);
		na/=g,nb/=g;
		B[now]=i;
		if(dfs(now+1,i+1,na,nb)) ok=true;
	}
	return ok;
}
int main(){
	scanf("%lld%lld",&a,&b);
	ll g=gcd(a,b);
	a=a/g,b=b/g;
	if(a==1){
		printf("%lld\n",b);
		return 0;
	}
	for(int i=0;i<10000;i++)
		ans[i]=-1;
	for(dep=2;;dep++)
		if(dfs(1,1,a,b))
			break;
	for(int i=1;i<=dep;i++)
		printf("%d ",ans[i]);
	return 0;
}
