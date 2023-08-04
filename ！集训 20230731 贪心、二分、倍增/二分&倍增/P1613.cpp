#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=80;
int g[N][N],dis[N],n,m,u,v;
bool f[N][N][N],vis[N];
int main(){
	memset(g,0x3f,sizeof(g));
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u][v]=1;
		f[u][v][0]=1;
	}
	for(int k=1;k<=70;k++)
		for(int l=1;l<=n;l++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(f[i][l][k-1]&&f[l][j][k-1]) f[i][j][k]=1,g[i][j]=1;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		int v=0;
		for(int j=1;j<=n;j++) if(dis[j]<dis[v]&&!vis[j]) v=j;
		vis[v]=1;
		for(int j=1;j<=n;j++)
			if(dis[v]+g[v][j]<dis[j]) dis[j]=dis[v]+g[v][j];
	}
	printf("%d\n",dis[n]);
	return 0;
}
