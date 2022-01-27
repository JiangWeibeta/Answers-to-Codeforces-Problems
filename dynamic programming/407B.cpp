#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

constexpr ll mod = 1e9 + 7;

int dp[1010][1010];

int p[1010];

// dp[i][j] = dp[i][j - 1] + dp[p[j - 1]][j - 1]

int dfs(int i, int j)
{
    if (i == j)
    {
        dp[i][j] = 1;
    }
    if (dp[i][j] == 0)
    {
        dp[i][j] = dfs(i, j - 1) + dfs(p[j - 1], j - 1) + 1;
    }
    return dp[i][j] % mod;
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    cout << dfs(1, n + 1) - 1 << endl;
    return 0;
}
