#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int M=5000;
int nxt[M],pre[M],last[M],apple[M],dp[M][M],n,m,tot=0;
/*
dp[i][j]��ʾ�ڵ�i����j��֦������ʣƻ�����ֵ
apple[i]��ʾ��i�����ϵ�ƻ����
nxt,pre,last���������ߵ�����
tot��ͳ�Ʊߵ����
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
    int ans=0;//ans��ʾu�ڵ���ӽڵ���Ŀ
    for (int i=last[u];i!=0;i=pre[i])
    {
        int v=nxt[i],value=apple[i];
        if(v == father)continue;//�����һ�����ڽڵ���Ǹ��ڵ㣬��֤�����ײ��ˣ���ʼ�ݹ鸸�ڵ���ֵܽڵ�
        ans+=dfs(v,u)+1;//�ݹ鵽���ϲ�ĸ��ڵ�1
        for(int j=min(ans,m);j>=1;--j)//��Ϊ������֦������Ŀ��ȡ��min
        {
            for(int k=min(j,ans);k>=1;--k)
            dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k-1]+value);
/*
����u�ڵ��µ��ӽڵ�j����j��������֦�����Ž���dp
������ú�˵���£���Ϊ�����������ǰ��յݹ齨������
���бȽ�ʱ��dp[u][j]����ǰ��ѡ���i����ӽڵ�õ������Ž���
����dp��ʱ�򲻿����ظ�����©��ĳ�ڵ�
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
