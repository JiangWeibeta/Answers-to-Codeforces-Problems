// Warning! TLE

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
vector<vector<ll>> dp(100, vector<ll>(100, 0));
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k = 0;
    cin >> k;
    string str;
    cin >> str;
    if (k > str.size())
    {
        cout << 0;
        return 0;
    }
    if (str[0] == '1')
        dp[1][0] = 1;
    else
        dp[0][0] = 1;
    ll ans = dp[k % 100][0];
    int len = str.size();
    for (int i = 1; i < len; i++)
    {
        if (str[i] == '1')
        {
            for (int j = 1; j <= k; j++)
                dp[j % 100][i % 100] = dp[(j - 1) % 100][(i - 1) % 100] + (j == 1);
        }
        else
        {
            for (int j = 0; j <= k; j++)
                dp[j % 100][i % 100] = dp[j % 100][(i - 1) % 100] + (j == 0);
        }
        ans += dp[k % 100][i % 100];
    }
    cout << ans;
    return 0;
}
