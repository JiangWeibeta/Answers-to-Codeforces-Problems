#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

constexpr ll mod = 998244353;

inline ll qpow(ll a, ll b)
{

    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n = 0;
    cin >> n;
    vector<ll> dp(n + 2);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < n + 2; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    ll y_ = qpow(qpow(2, n), mod - 2) % mod;
    cout << (dp[n] % mod) * (y_ % mod) % mod;
    system("pause");
    return 0;
}
