#include <algorithm>
#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
ll dp[1011][1011];
 
void init()
{
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < 1011; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i] = 1;
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] %= mod;
        }
    }
}
 
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    init();
    ll  ans = 0;
    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += ((dp[i + m - 1][m] - pre + mod) % mod) * (dp[m + n - i][m] % mod) % mod;
        ans %= mod;
        pre = dp[i + m - 1][m];
    }
    cout << ans;
    return 0;
}
