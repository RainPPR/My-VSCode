#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=2000005;
ll n,u,v,cnt,head[len],maxn,xid;
ll ans[len],f[len],size[len];
struct node
{
	int to,nxt;
}e[len];
void insert(int u,int v)
{
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
void dfs(int u,int fa)
{
	f[u]=0;
	size[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		size[u]+=size[v];
		f[u]+=f[v]+size[v];
	}
}
void dp(int u,int fa)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa)
		{
			continue;
		}
		ans[v]=ans[u]+n-2*size[v];
		dp(v,u);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		insert(u,v);
		insert(v,u);
	}
	dfs(1,0);
	ans[1]=f[1];
	dp(1,0);
	for(int i=1;i<=n;i++)
	{
		if(ans[i]>maxn)
		{
			maxn=ans[i];
			xid=i;
		}
	}
	cout<<xid<<endl;
	return 0;
}
/*
7
1 2
1 3
2 4
2 5
3 6
3 7
*/
