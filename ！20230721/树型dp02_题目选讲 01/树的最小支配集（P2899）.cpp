#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
#define N 100005
int f[N][3],n,vis[N];
vector<int> g[N];
int dp(int u)
{
 
    f[u][0]=1;
    f[u][1]=0;
    f[u][2]=0;
    vis[u]=1;
    bool flag=0;
    int inc=INF;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(vis[v]==0)
        {
            dp(v);
        	f[u][0]+=min(f[v][0],min(f[v][1],f[v][2]));
        	f[u][2]+=min(f[v][0],f[v][1]);
        	if(f[v][0]<=f[v][1])
          	{
            	flag=1;
            	f[u][1]+=f[v][0];
          	}
          	else
          	{
              	inc=min(inc,(f[v][0]-f[v][1]));
              	f[u][1]+=f[v][1];
          	}
        }
    }
    if(flag==0)//f[u][1]没有从f[v][0]推过来，强制转化为从f[v][0]推过来
        f[u][1]+=inc;
    return 0;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
      	for(int i=1;i<n;i++)
      	{
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dp(1);
		printf("%d",min(f[1][0],f[1][1]));
    }
    return 0;
}
