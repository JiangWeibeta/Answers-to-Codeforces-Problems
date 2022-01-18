#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

constexpr ll mod = 1e9 + 7;

ll  dp[1001][1001];
int t = 0, n = 0, k = 0;

void solve(int n, int k)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][1] = 1;
    for (int i = 1; i <= k; i++)
        dp[0][i] = 1;
    for (int j = 1; j <= k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[i - 1][j] + dp[n - i][j - 1];
            dp[i][j] %= mod;
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        solve(n, k);
        cout << dp[n][k] << endl;
    }
    return 0;
}
