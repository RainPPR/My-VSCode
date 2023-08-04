#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10,M=3e7+10,L=2e7+1,Maxn=1e7+1;
int sum[M],ls[M],rs[M],cnt=1,n;
void modify(int u,int l,int r,int x,int v){
	if(l==r){
		sum[u]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		if(!ls[u]) ls[u]=++cnt;
		modify(ls[u],l,mid,x,v);
	}else{
		if(!rs[u]) rs[u]=++cnt;
		modify(rs[u],mid+1,r,x,v);
	}
	sum[u]=sum[ls[u]]+sum[rs[u]];
}
int qsum(int u,int l,int r,int x,int y){
	if(l>=x&&r<=y) return sum[u];
	int mid=(l+r)>>1,res=0;
	if(x<=mid) res=qsum(ls[u],l,mid,x,y);
	if(y>mid) res+=qsum(rs[u],mid+1,r,x,y);
	return res;
}
int qrk(int k){
	return qsum(1,1,L,1,k-1)+1;
}
int qkth(int u,int l,int r,int k){
	if(l==r) return l-Maxn;
	int mid=(l+r)>>1;
	if(sum[ls[u]]>=k) return qkth(ls[u],l,mid,k);
	return qkth(rs[u],mid+1,r,k-sum[ls[u]]);
}
int qpre(int k){
	//查询小于 k 的最大的数 
	int rk=qrk(k);
	if(rk==1) return -1;
	return qkth(1,1,L,rk-1);
}
int qnex(int k){
	//查询大于 k 的最小的数 
	int rk=qrk(k+1);
	if(rk==n+1) return -1;
	return qkth(1,1,L,rk);
}
int main(){
	scanf("%d",&n);
	int opt,x;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&opt,&x);
		if(opt==1) modify(1,1,L,x+Maxn,1);
		else if(opt==2) modify(1,1,L,x+Maxn,-1);
		else if(opt==3) printf("%d\n",qrk(x+Maxn));
		else if(opt==4) printf("%d\n",qkth(1,1,L,x));
		else if(opt==5) printf("%d\n",qpre(x+Maxn));
		else printf("%d\n",qnex(x+Maxn));
	}
	return 0;
}
