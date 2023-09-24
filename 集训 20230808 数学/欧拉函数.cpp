#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int euler_phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++) { if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }}
    return n > 1 ? ans / n * (n - 1) : ans;
}

int primes[N], cnt;
bool is[N];
int phi[N];

int get_phi(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!is[i]) primes[++cnt] = i, phi[i] = i - 1;
        for (int j = 0; primes[j] <= n / i; ++j) {
            is[primes[j] * i] = 1;
            if (i % primes[j]) phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            else {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
        }
    }
}

int main()
{
    return 0;
}