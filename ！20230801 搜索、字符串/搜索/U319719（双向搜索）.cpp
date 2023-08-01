#include<iostream>
#include<cstdio>
using namespace std;
const int N=21,M=1<<20;
int n,m,ans,dv;
bool vis[N][N];
int f[N][M],g[M];
void dfs1(int now,int s){
	if(g[s]>m) return;
	if(now>dv){
		f[g[s]][s]++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(vis[now][i]&&(s&(1<<(i-1)))==0)
			dfs1(now+1,(s|(1<<(i-1))));
	dfs1(now+1,s);
}
void dfs2(int now,int s){
	if(g[s]>m) return;
	if(now==dv){
		int s0=(s^((1<<n)-1));
		ans+=f[m-g[s]][s0];
		return; 
	}
	for(int i=1;i<=n;i++)
		if(vis[now][i]&&(s&(1<<(i-1)))==0)
			dfs2(now-1,(s|(1<<(i-1))));
	dfs2(now-1,s);
}
int main(){
	freopen("U319719.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int s=0;s<M;s++){
		int tmp=s;
		while(tmp){
			g[s]+=tmp%2;
			tmp/=2;
		}
	}
	while(n){
		dv=n/2;
		ans=0;
		for(int i=0;i<=n;i++)
			for(int s=0;s<(1<<n);s++)
				f[i][s]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				char ch;
				cin>>ch;
				vis[i][j]=(ch=='L'?0:1);
			}
		dfs1(1,0);
		for(int s=(1<<n)-1;s;s--){
			for(int s0=((s-1)&s);s0;s0=((s0-1)&s))
				f[g[s0]][s]+=f[g[s0]][s0];
			f[0][s]+=f[0][0];
		}
		dfs2(n,0);
		printf("%d\n",ans);
		scanf("%d%d",&n,&m);
	}
	return 0; 
}
