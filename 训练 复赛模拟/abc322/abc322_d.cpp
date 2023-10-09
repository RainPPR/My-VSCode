#include <bits/stdc++.h>

using namespace std;

struct matrix {
    bitset<16> bs;
    void write() {
        for (int i = 0; i < bs.size(); ++i) putchar('0' + bs[i]);
        putchar('\n');
    }
} a[3][4][16];

struct strmat {
    string base[4];
    int h, w;
    void write() {
        for (int i = 0; i < h; ++i) printf("%s", base[i].c_str());
        putchar('\n');
    }
};

struct point {
    int x, y;
};

strmat turn(strmat e) {
    strmat r; r.h = e.w, r.w = e.h;
    for (int i = e.h - 1; ~i; --i) {
        string th = e.base[i]; for (int j = 0; j < th.size(); ++j) r.base[j].push_back(th[j]);
    } return r;
}

matrix tomat(strmat e) {
    int cc = 0; matrix r;
    for (int i = 0; i < e.h; ++i) for (int j = 0; j < e.w; ++j) r.bs[cc++] = e.base[i][j] == '#';
    return r;
}

void mix(int p, int f, strmat base) {
    int cc = 0;
    for (int i = 0; i + base.h - 1 < 4; ++i) for (int j = 0; j + base.w - 1 < 4; ++j) {
        strmat kt; kt.h = kt.w = 4;
        kt.base[0] = kt.base[1] = kt.base[2] = kt.base[3] = "....";
        for (int r = 0; r < base.h; ++r) for (int c = 0; c < base.w; ++c)
            kt.base[i + r][j + c] = base.base[r][c];
        a[p][f][cc++] = tomat(kt);
    }
}

void getmatrix(int p) {
    string line[4];
    cin >> line[0] >> line[1] >> line[2] >> line[3];

    point lu = {0, 0}, rd = {3, 3};
    while (line[lu.x] == "....") ++lu.x;
    while (line[0][lu.y] == '.' && line[1][lu.y] == '.' && line[2][lu.y] == '.' && line[3][lu.y] == '.') ++lu.y;
    while (line[rd.x] == "....") --rd.x;
    while (line[0][rd.y] == '.' && line[1][rd.y] == '.' && line[2][rd.y] == '.' && line[3][rd.y] == '.') --rd.y;

    strmat base[4]; base[0].h = rd.x - lu.x + 1, base[0].w = rd.y - lu.y + 1;
    for (int i = lu.x; i <= rd.x; ++i)
        for (int j = lu.y; j <= rd.y; ++j)
            base[0].base[i - lu.x] += line[i][j];

    base[1] = turn(base[0]);
    base[2] = turn(base[1]);
    base[3] = turn(base[2]);

    for (int t = 0; t < 4; ++t) mix(p, t, base[t]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getmatrix(0);
    getmatrix(1);
    getmatrix(2);

    for (int j0 = 0; j0 < 4; ++ j0) for (int k0 = 0; k0 < 16; ++k0) {
        if (a[0][j0][k0].bs.count() == 0) continue;
        for (int j1 = 0; j1 < 4; ++ j1) for (int k1 = 0; k1 < 16; ++k1) {
            if (a[1][j1][k1].bs.count() == 0) continue;
            for (int j2 = 0; j2 < 4; ++ j2) for (int k2 = 0; k2 < 16; ++k2) {
                if (a[2][j2][k2].bs.count() == 0) continue;
                // a[0][j0][k0].bs | a[1][j1][k1].bs | a[2][j2][k2].bs
                bitset<16> t1 = a[0][j0][k0].bs & a[1][j1][k1].bs;
                bitset<16> t2 = a[1][j1][k1].bs & a[2][j2][k2].bs;
                bitset<16> t3 = a[0][j0][k0].bs & a[2][j2][k2].bs;
                bitset<16> t = a[0][j0][k0].bs | a[1][j1][k1].bs | a[2][j2][k2].bs;
                if (t1.count() + t2.count() + t3.count() == 0 && t.count() == 16) printf("Yes\n"), exit(0);
            }
        }
    }

    printf("No\n");
    return 0;
}
