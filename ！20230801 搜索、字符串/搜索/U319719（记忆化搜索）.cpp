#include<iostream>
#include<cstdio>
using namespace std;
const int N=21,M=1<<20;
int n,m,ans;
bool vis[N][N],used[N][M];
int f[N][M],g[M];
int dfs(int now,int s){
	if(g[s]>m) return 0; 
	if(now>n){
		if(g[s]==m) return 1;
		return 0;
	}
	if(used[now][s]) return f[now][s];
	used[now][s]=true;
	int res=dfs(now+1,s);
	for(int i=1;i<=n;i++)
		if(vis[now][i]&&(s&(1<<(i-1)))==0)
			res+=dfs(now+1,(s|(1<<(i-1))));
	return f[now][s]=res;
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
		ans=0;
		for(int i=0;i<=n;i++)
			for(int s=0;s<(1<<n);s++)
				f[i][s]=used[i][s]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				char ch;
				cin>>ch;
				vis[i][j]=(ch=='L'?0:1);
			}
		printf("%d\n",dfs(1,0));
		scanf("%d%d",&n,&m);
	}
	return 0; 
}
