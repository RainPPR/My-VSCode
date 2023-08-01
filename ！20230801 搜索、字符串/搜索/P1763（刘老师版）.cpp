#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long ll;
const int N=1e6+10;
ll a,b;
int maxd,v[N],ans[N];
ll get_first(ll aa,ll bb){
	return (bb+aa-1)/aa;
}
ll gcd(ll aa,ll bb){
	return bb==0?aa:gcd(bb,aa%bb);
}
bool better(int d){
	return ans[d]==-1||v[d]<ans[d];
}
bool dfs(int d,ll fr,ll aa,ll bb){
	if(d==maxd){
		if(bb%aa) return false;
		v[d]=bb/aa;
		if(better(d)) memcpy(ans,v,sizeof(ll)*(d+1));
		return true;
	}
	bool ok=false;
	fr=max(fr,get_first(aa,bb));
	for(int i=fr;i<=10000000;i++){
		if(bb*(maxd+1-d)<=i*aa) break;
		v[d]=i;
		ll b2=bb*i;
		ll a2=aa*i-bb;
		ll g=gcd(a2,b2);
		if(dfs(d+1,i+1,a2/g,b2/g)) ok=true;
	}
	return ok;
}
int main(){
	scanf("%lld%lld",&a,&b);
	int ok=0;
	for(maxd=1;;maxd++){
		memset(ans,-1,sizeof(ans));
		if(dfs(0,get_first(a,b),a,b)){
			ok=1;
			break;
		}
	}
	for(int i=0;i<=maxd;i++)
		printf("%lld ",ans[i]);
	return 0;
}
