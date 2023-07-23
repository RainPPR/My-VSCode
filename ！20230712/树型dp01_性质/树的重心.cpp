#include <iostream>
#include <vector>
using namespace std;
const int N=105;
vector<int> G[N];
int n;
int dp[N];
int tot[N];
void dfs(int u,int fa)
{
	tot[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v!=fa)//注意fa的作用
		{
			dfs(v,u);
			tot[u]+=tot[v];
			dp[u]=max(dp[u],tot[v]); //dp[u]这里保存最大子树的联通量
		}
	}
	dp[u]=max(dp[u],n-tot[u]);//判断下子树的最大联通量与"父子树"的联通量大小
}
int main()
{
	int u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);//双向存储 
		G[v].push_back(u);
	}
	int root=1;
	dfs(root,-1);
	int minn=100;
	vector <int> v2;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]<minn)
		{
			minn=dp[i];
			v2.clear();
			v2.push_back(i);
		}
		else if(dp[i]==minn)
		{
			v2.push_back(i);
		}
	}
	cout<<minn<<endl;
	for(int i=0;i<v2.size();i++)
	{
		cout<<v2[i]<<" ";
	}
	return 0;
}
