#include<stdio.h>
#include<stdlib.h>
#define FORa(i,s,e) for(int i=s;i<=e;i++)
#define FORs(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
const int N=1000,INF=2147483647;
int n,num_edge,ans,head[N+1],d[N+1]; 
struct Edge{
    int next,to,dis;
}edge[2*N];
inline void Add_edge(int from,int to,int dis)
{
    edge[++num_edge]=(Edge){head[from],to,dis},head[from]=num_edge;
}
inline int max(int fa,int fb){return fa>fb?fa:fb;}

inline int Dfs(int u,int fa,int dis)
{
    int max1=0,max2=0;//子树的链中的最大值与次大值 
    for(int i=head[u];i;i=edge[i].next)
    {
        if(edge[i].to!=fa) 
        {
            Dfs(edge[i].to,u,dis+edge[i].to);
            if(d[edge[i].to]+edge[i].dis>max1)
                max2=max1,max1=d[edge[i].to]+edge[i].dis;
            else if(d[edge[i].to]+edge[i].dis>max2)
                max2=d[edge[i].to]+edge[i].dis; 
        }
    }
    d[u]=max1;
    //考虑到将u作为根节点,更新子树的链中的最大值与次大值 
    if(dis>max1)
        max2=max1,max1=dis;
    else if(dis>max2)
        max2=dis;
    ans=max(max1+max2,ans);
}
int main()
{
    int from,to,dis;
    scanf("%d",&n);
    FORa(i,2,n)
    {
        scanf("%d%d%d",&from,&to,&dis);
        Add_edge(from,to,dis),Add_edge(to,from,dis);
    }
    Dfs(1,0,0);
    printf("%d",ans);
    return 0;
}
/*
7
1 2 4
1 3 2
2 5 1
2 6 4
3 4 9
5 7 10
*/
