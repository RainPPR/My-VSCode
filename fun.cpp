#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

inline string readline()
{
    string str;
    char ch = getchar();
    while (ch == '\n' || ch == '\r')
        ch = getchar();
    while (ch != '\n' && ch != '\r')
        str += ch, ch = getchar();
    return str;
}

template <typename _Tp>
vector<_Tp> multiply(const vector<_Tp> &num1, const vector<_Tp> &num2)
{
    int m = num1.size();
    int n = num2.size();
    vector<int> res(m + n, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            _Tp mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            _Tp sum = mul + res[p2];

            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }

    int i = 0;
    while (i < res.size() && res[i] == 0)
        i++;

    vector<_Tp> result;
    for (; i < res.size(); i++)
        result.push_back(res[i]);
    return result;
}

template <typename _Tp>
string encrypt(const string &str, const int &k, const int &p)
{
    int n = str.length();
    vector<vector<_Tp>> nums(n);

    for (int i = 0; i < n; ++i)
    {
        _Tp t = str[i] + _Tp(11);
        while (t)
            nums[i].push_back(t * k % p), t /= p;
    }

    vector<_Tp> product = multiply<_Tp>(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
        product = multiply<_Tp>(product, nums[i]);

    string result;
    for (int i = product.size() - 1; i >= 0; i--)
        result += to_string(product[i]);
    return result;
}

int main()
{
    string str = readline();
    int k = read(), p = read();

    cout << encrypt<short>(str, k, p) << endl;
    cout << encrypt<int>(str, k, p) << endl;
    cout << encrypt<long long>(str, k, p) << endl;
    return 0;
}
