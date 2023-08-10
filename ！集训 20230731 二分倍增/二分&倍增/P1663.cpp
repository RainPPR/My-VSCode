#include<iostream>
#include<cstdio>
using namespace std;
const int N=5010;
typedef double db;
int n;
db xi[N],yi[N],ans;
bool check(db mid){
	db maxn=-1e9,minn=1e9;
	for(int i=1;i<n;i++){
		db k=(yi[i+1]-yi[i])/(xi[i+1]-xi[i]);
		db b=yi[i]-k*xi[i];
		db cur=(mid-b)/k;
		if(k<0) maxn=max(maxn,cur);
		else minn=min(minn,cur);
	}
	return maxn>=minn;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&xi[i],&yi[i]);
	int l=1,r=1e8;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid/100.0)){
			ans=mid/100.0;
			l=mid+1;
		}else r=mid-1;
	}
	printf("%.2lf\n",ans);
	return 0;
}
