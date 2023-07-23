#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct edge 
{
    int u, v, c, next;
} e[5000005];
int p[2500005], eid, S, T;
void init() 
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int c)
{
    e[eid].u = u;
    e[eid].v = v;
    e[eid].c = c;
    e[eid].next = p[u];
    p[u] = eid++;
}
bool judge[2500005];
int MAX = 0x3f3f3f3f;
int dis[2500001];
bool vis[2500001];
void spfa(int u)
{
    memset(vis,false,sizeof vis);
    vis[u] = true;
    memset(dis,inf,sizeof dis);
    dis[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty())
	{
        u = q.front();
        q.pop();
        vis[u] = false;
        for(int j=p[u];~j;j = e[j].next)
		{
            int v = e[j].v;
            int w = e[j].c;
            if(dis[v] > dis[u] + w)
			{
                dis[v] = dis[u] + w;
                if(!vis[v])
				{
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--)
	{
        init();
        memset(judge,false,sizeof(judge));
        int r,c;
        cin >> r >> c;
        int cc = c; 
        c++;//因为每行有c+1个点 
        char maze[r][c];
        for(int i = 0;i < r;i++){
            for(int j = 0;j < cc;j++)
			{
                cin >> maze[i][j];
                if(maze[i][j] == '/')
				{
                    insert(i * c + j + 1,(i+1) * c + j,0);
                    insert((i+1) * c + j,i * c + j + 1,0);//插入权值为0的边 

                    insert(i * c + j,(i+1) * c + j + 1,1);
                    insert((i+1) * c + j + 1,i * c + j,1);//插入权值为1的边 
                }
				else
				{
                    insert(i * c + j + 1,(i+1) * c + j,1);
                    insert((i+1) * c + j,i * c + j + 1,1);//插入权值为1的边 

                    insert(i * c + j,(i+1) * c + j + 1,0);
                    insert((i+1) * c + j + 1,i * c + j,0);//插入权值为0的边 
                }
            }
        }
        if((r+cc)%2)//如果终点不是同奇或同偶则永远不会到达，直接输出即可 
		{
            cout << "NO SOLUTION" << endl;
            continue;
        }
        spfa(0);//调用SPFA算法 
        cout << dis[(r+1)*(cc+1)-1] << endl;
    }
    return 0;
}
/*
1 
3 5 
\\/\\
\\///
/\\\\
*/
/*
1 
3 5 
/\/\\
\////
/\\\\
*/
