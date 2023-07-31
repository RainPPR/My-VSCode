#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+20;
int a[N],f[N],g[N];
int n=1,lf,lg;
int minn(int x,int len){
	int l=1,r=len+1,ans=-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(f[mid]<x){
			ans=mid;
			r=mid;
		}else l=mid+1;
	}
	return ans;
}
int maxn(int x,int len){
	int l=1,r=len+1,ans=-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(g[mid]>=x){
			ans=mid;
			r=mid;
		}else l=mid+1;
	}
	return ans;
}
int main(){
	while(scanf("%d",&a[n])==1) n++;
	n--;
	f[lf=1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]<=f[lf]) f[++lf]=a[i];
		else{
			int j=minn(a[i],lf);
			if(j!=-1) f[j]=a[i];
		}
	}
	g[lg=1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>g[lg]) g[++lg]=a[i];
		else{
			int j=maxn(a[i],lg);
			if(j!=-1) g[j]=a[i];
		}
	}
	printf("%d\n%d\n",lf,lg);
	return 0;
}
