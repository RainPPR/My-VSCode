#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 6005
vector <int> G[MAXN];
int n,u,v;
int dp[MAXN][2];
bool vis[MAXN];
inline void dfs(int x) 
{
    vis[x] = 1;	//vis�������Ѿ������ʹ��Ľ�㣬�����ظ�
    int siz = G[x].size();
    for(int i = 0;i <= siz - 1;i ++)
    {
    	if(! vis[G[x][i]]) 
		{
            dfs(G[x][i]);
            dp[x][1] += dp[G[x][i]][0];	//״̬ת��
            dp[x][0] += max(dp[G[x][i]][1], dp[G[x][i]][0]);
        }
	}        
    dp[x][1]++;
}
int main() 
{
    scanf("%d",&n);
    for(int i = 1;i <= n - 1;i ++) 
	{
        scanf("%d%d",&u,&v);
        G[u].push_back(v);//���ڽӱ������������
        G[v].push_back(u);
    }
    dfs(1);	//��dfs��DP
    printf("%d",max(dp[1][1], dp[1][0]));
    return 0;
}
 
