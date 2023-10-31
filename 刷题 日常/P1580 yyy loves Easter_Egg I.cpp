#include <bits/stdc++.h>

using namespace std;

#define meow(x) cerr << #x" = [" << (x) << "]" << endl

inline string gl() {
    string s;
    return (getline(cin, s), s);
}

const string no = "-1";

string getid(string s) {
    char id[1010];
    sscanf(s.c_str(), "%[^:]", id);
    s = id;
    return (s.pop_back(), s);
}

int getcnt(string s) {
    int cnt = 0;
    for (char c : s) cnt += c == '@';
    return cnt;
}

string getat(string s) {
    int cnt = getcnt(s);
    if (cnt != 1) return no;
    char id[1010];
    sscanf(s.c_str(), "%*[^@]%*s %*s %s", id);
    return "yyy loves " + string(id);
}

void Successful(string s) {
    cout << "Successful @" << s << " attempt" << endl;
}

void Broken(string s, int line, string id) {
    cout << "Unsuccessful @" << s << " attempt" << endl;
    cout << line << endl;
    cout << id << endl;
}

void Queue(string s, int line) {
    cout << "Unsuccessful @" << s << " attempt" << endl;
    cout << line << endl;
    cout << "Good Queue Shape" << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s, atw = no; int cnt = 0;
    while ((s = gl(), ++cnt, s.size() > 1)) {
        string id = getid(s), at = getat(s);
        if (atw == no) atw = at;
        if (id == atw) Successful(atw), exit(0);
        if (at == no || at != atw) Broken(atw, cnt, id), exit(0);
    } Queue(atw, cnt - 1);
    return 0;
}
