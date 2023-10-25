#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> ans;
    for (int i9 = 0; i9 <= 1; ++i9) for (int i8 = 0; i8 <= 1; ++i8) for (int i7 = 0; i7 <= 1; ++i7) for (int i6 = 0; i6 <= 1; ++i6) for (int i5 = 0; i5 <= 1; ++i5) for (int i4 = 0; i4 <= 1; ++i4) for (int i3 = 0; i3 <= 1; ++i3) for (int i2 = 0; i2 <= 1; ++i2) for (int i1 = 0; i1 <= 1; ++i1) for (int i0 = 0; i0 <= 1; ++i0) {
        string now = string(i9 ? "9" : "") + (i8 ? "8" : "") + (i7 ? "7" : "") + (i6 ? "6" : "") + (i5 ? "5" : "") + (i4 ? "4" : "") + (i3 ? "3" : "") + (i2 ? "2" : "") + (i1 ? "1" : "") + (i0 ? "0" : "");
        if (now != "") ans.push_back(stoll(now));
    } sort(ans.begin(), ans.end());
    ofstream fout("AT_abc321_c 321-like Searcher -2.cpp");
    fout << "#include <bits/stdc++.h>" << endl;
    fout << "using namespace std;" << endl;
    fout << "long long ans[1050] = {";
    for (long long i : ans) fout << i << ", ";
    fout << "-1};" << endl;
    fout << "signed main() {" << endl;
    fout << "    int k; scanf(\"%d\", &k);" << endl;
    fout << "    printf(\"%lld\\n\", ans[k]);" << endl;
    fout << "    return 0;" << endl;
    fout << "}" << endl;
    fout.close();
    return 0;
}
