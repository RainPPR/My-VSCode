#include <iostream>
#include <cstring>
using namespace std;
const int N=100010, M=2*N;
int first[N],to[M],nxt[M],wht[M],idx;
int n,ans;
void add(int u, int v, int w)
{
	to[idx]=v;
	wht[idx]=w;
	nxt[idx]=first[u];
	first[u]=idx++;
}
//计算经过u点的路径长度最大值
int dfs(int u, int fa)
{
    //dist表示从u往下走的最大长度
    int dist = 0;
    //到u点的最长距离和次长距离
    int d1 = 0, d2 = 0;
    for(int i=first[u]; i!=-1; i=nxt[i])
    {
        int v=to[i];
        if(v==fa)//防止回上一层搜索
		{
			continue; 
		}
        //求子结点的向下走的最大长度
        int d=dfs(v,u)+wht[i]; 
        dist=max(dist,d);
        //更新最长距离和次长距离
        if(d>=d1) 
		{
			d2=d1;
			d1=d;
		}
        else if(d>d2)
		{
			d2=d;
		}
    }
    //打擂台求经过u点的最长路径距离
    ans=max(ans,d1+d2);
    cout<<u<<":d1="<<d1<<",d2="<<d2<<",dis="<<dist<<",ans="<<ans<<endl;
    return dist;
}
int main()
{
    cin>>n;
    memset(first, -1, sizeof first);
    int u,v,w;
    for(int i=0; i< n-1; i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
		add(v,u,w);
    }
    cout<<first[1]<<endl;
    dfs(1,-1);//dfs(6, -1);分析下效果
    cout << ans << endl;
    return 0;
}

