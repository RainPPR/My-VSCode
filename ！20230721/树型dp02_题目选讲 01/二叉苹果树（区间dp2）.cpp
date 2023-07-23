#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int M=5000;
int nxt[M],pre[M],last[M],apple[M],dp[M][M],n,m,tot=0;
/*
dp[i][j]表示节点i保留j个枝条的所剩苹果最大值
apple[i]表示第i条边上的苹果数
nxt,pre,last是用来建边的数组
tot来统计边的序号
*/
void cnct(int u,int v,int w)
{
    tot++;
    nxt[tot]=v;
    pre[tot]=last[u];
    last[u]=tot;
    apple[tot]=w;
}
int dfs (int u,int father)
{
    int ans=0;//ans表示u节点的子节点数目
    for (int i=last[u];i!=0;i=pre[i])
    {
        int v=nxt[i],value=apple[i];
        if(v == father)continue;//如果下一个相邻节点就是父节点，则证明到底层了，开始递归父节点的兄弟节点
        ans+=dfs(v,u)+1;//递归到最上层的根节点1
        for(int j=min(ans,m);j>=1;--j)//因为有限制枝条的数目，取个min
        {
            for(int k=min(j,ans);k>=1;--k)
            dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k-1]+value);
/*
对于u节点下的子节点j，对j保留多少枝条最优进行dp
在这里好好说明下，因为建树是我们是按照递归建的树。
进行比较时，dp[u][j]都是前面选择除i外的子节点得到的最优解结果
所以dp的时候不可能重复或者漏掉某节点
*/
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;++i)
    {
        int x,y,value;
        scanf("%d%d%d",&x,&y,&value);
        cnct(x,y,value);
        cnct(y,x,value);
    }
    dfs(1,0);
    printf("%d\n",dp[1][m]);
    return 0;
}
