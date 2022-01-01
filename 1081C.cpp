#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
constexpr ll mod = 998'244'353;
 
int main()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[1][0] = m;
    dp[1][1] = 0;
    for (int i = 2; i < n + 1; i++)
    {   dp[i][0] = m;
        for (int j = 1; j < k + 1; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * (m - 1) + dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][k];
    return 0;
}
