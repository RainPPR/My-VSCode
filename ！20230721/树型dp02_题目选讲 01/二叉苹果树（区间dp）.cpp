#include<iostream>
#include<cstring>
using namespace std;
const int N = 210;
int h[N], e[N], ne[N], w[N], idx;
int f[N][N];
int n, m;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int father)
{
    for(int i = h[u]; i != -1; i = ne[i]){  //枚举每一个分组
        if(e[i] == father)continue;
        dfs(e[i], u);
        for(int j = m; j >= 0; j--)  //枚举分支的个数
            for(int k = 0; k < j; k++)  //枚举决策
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[e[i]][k] + w[i]);
    }
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);
    cout << f[1][m] << endl;
    return 0;
}

