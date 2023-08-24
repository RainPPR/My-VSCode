#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

inline int read()
{
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            flag = -1;
    for (; isdigit(ch); ch = getchar())
        num = (num << 3) + (num << 1) + ch - '0';
    return num * flag;
}

struct p
{
    int x, y;
    p()
    {
        x = y = 0;
    }
    p(int _x, int _y)
    {
        x = _x, y = _y;
    }
};

struct node
{
    int val;
    p down, right;
    node()
    {
        val = -1;
    }
    node(p _d, p _r)
    {
        val = -1, down = _d, right = _r;
    }
    node(int _v, p _d, p _r)
    {
        val = _v, down = _d, right = _r;
    }
} v[N][N];

void topos(int &x, int &y)
{
    int w = y;
    node root = v[x][0];
    for (int i = 0; i < w; ++i)
        x = root.right.x, y = root.right.y, root = v[x][y];
}

void goright(int &x, int &y)
{
    p t = v[x][y].right;
    x = t.x, y = t.y;
}

void goright(int &a, int &b, int &c, int &d)
{
    goright(a, b), goright(c, d);
}

void godown(int &x, int &y)
{
    p t = v[x][y].down;
    x = t.x, y = t.y;
}

void godown(int &a, int &b, int &c, int &d)
{
    godown(a, b), godown(c, d);
}

int a[N][N];

int main()
{
    int n = read(), m = read(), q = read();

    for (int i = 1; i <= n; ++i)
        v[i][0] = node(p(i + 1, 0), p(i, 1));
    for (int i = 0; i <= m; ++i)
        v[0][i] = node(p(1, i), p(0, i + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[i][j] = node(read(), p(i + 1, j), p(i, j + 1));

    int at, bt, ct, dt, h, w;
    while (q--)
    {
        at = read(), bt = read(), ct = read(), dt = read();
        h = read(), w = read();

        int a1 = at - 1, b1 = bt - 1, c1 = ct - 1, d1 = dt - 1;
        topos(a1, b1);
        topos(c1, d1);

        int a2 = ct - 1, b2 = dt - 1, c2 = at - 1, d2 = bt - 1;
        topos(a2, b2);
        topos(c2, d2);

        for (int i = 0; i < h; ++i)
            godown(a1, b1, c1, d1), swap(v[a1][b1].right, v[c1][d1].right);
        for (int i = 0; i < w; ++i)
            goright(a2, b2, c2, d2), swap(v[a2][b2].down, v[c2][d2].down);

        for (int i = 0; i < w; ++i)
            goright(a1, b1, c1, d1), swap(v[a1][b1].down, v[c1][d1].down);
        for (int i = 0; i < h; ++i)
            godown(a2, b2, c2, d2), swap(v[a2][b2].right, v[c2][d2].right);
    }

    for (int i = 1; i <= n; ++i)
    {
        int x = i, y = 0;
        for (int j = 1; j <= m; ++j)
        {
            goright(x, y);
            printf("%d ", v[x][y].val);
        }
        putchar('\n');
    }

    return 0;
}