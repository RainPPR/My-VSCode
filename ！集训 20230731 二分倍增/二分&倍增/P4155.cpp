#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=4e5+10,M=23;
const ll inf=1e9;
struct node{
	ll st,ed;
	int id;
	bool operator < (node x) const{
		return st<x.st;
	}
}so[N];
int n,m,ans[N],f[M][N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&so[i].st,&so[i].ed);
		if(so[i].st>so[i].ed) so[i].ed+=m;
		so[i].id=i;
	}
	sort(so+1,so+1+n);
	for(int i=1;i<=n;i++){
		so[i+n].st=so[i].st+m;
		so[i+n].ed=so[i].ed+m;
	}
	int pos,now=1;
	so[2*n+1].st=so[2*n+1].ed=3ll*inf;
	for(int i=1;i<=2*n+1;i++)
		while(so[now].ed<so[i].st)
			f[0][now]=i-1,now++;
	for(int j=1;j<M;j++)
		for(int i=1;i<=2*n;i++)
			f[j][i]=f[j-1][f[j-1][i]];
	for(int i=1;i<=n;i++){
		int res=2,u=i;
		for(int j=M-1;j>=0;j--){
			if(f[j][u]&&so[f[j][u]].ed<so[i].st+m)
				u=f[j][u],res+=(1<<j);
		}
		ans[so[i].id]=res;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
