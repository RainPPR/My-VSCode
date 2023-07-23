#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int first[N],nxt[N*2],to[N*2],wht[N*2];
int tot,INF=0x3f3f3f3f;
int down1[N],down2[N],up[N],p[N];
void add(int x,int y,int z)
{
	to[++tot]=y;
	wht[tot]=z;
	nxt[tot]=first[x];
	first[x]=tot;
}
//查找子树，用子节点更新父节点
int dfs_down(int x,int father)
{
	down1[x]=down2[x]=-INF;
	for(int i=first[x];i;i=nxt[i])
	{
		int y=to[i],z=wht[i];
		if(y==father)
		{
			continue;
		}
		int d=dfs_down(y,x)+z;
		if(d>down1[x])
		{
			down2[x]=down1[x];
			down1[x]=d;
			p[x]=y;
		}
		else if(d>down2[x])
		{
			down2[x]=d;
		}
	}
	if(down1[x]==-INF && down2[x]==-INF)
	{
		down1[x]=down2[x]=0;
	}
	return down1[x];
} 
//查找父节点
void dfs_up(int x,int father)
{
	for(int i=first[x];i;i=nxt[i])
	{
		int y=to[i],z=wht[i];
		if(y==father)
		{
			continue;
		}		
        if(p[x]==y) 
			up[y]=max(up[x],down2[x])+z;
        else 
			up[y]=max(up[x],down1[x])+z;
        dfs_up(y,x);
    }
}
int main()
{
	int n,x,y,z;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs_down(1,0);
	dfs_up(1,0);
	int res=INF;
	for(int i=1;i<=n;i++)
	{
		res=min(res,max(down1[i],up[i]));
	}
	printf("%d",res);
	return 0;
}
/*
5 
2 1 1 
3 2 1 
4 3 1 
5 1 1
*/
