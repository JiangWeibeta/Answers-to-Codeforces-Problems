#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    string str;
    cin >> str;
    vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));
    for (int i = 0; i < str.size(); i++)
    {
        dp[i][i] = 1;
        if (i + 1 < str.size() && str[i] == str[i + 1])
            dp[i][i + 1] = 1;
    }
    for (int k = 2;  k < str.size(); k++)
    {
        for (int i = 0; i + k < str.size(); i++)
        {
            dp[i][i + k] = (str[i] == str[i + k] && dp[i + 1][i + k - 1] ? 1 : 0);
        }
    }
    vector<ll> back(str.size(), 0);
    vector<ll> front(str.size(), 0);
    back[str.size() - 1] = 1;
    front[0]             = 1;
    for (int i = str.size() - 2; i >= 0; i--)
    {
        for (int j = i; j < str.size(); j++)
            back[i] += dp[i][j];
        back[i] += back[i + 1];
    }
    for (int i = 1; i < str.size(); i++)
    {
        for (int j = 0; j <= i; j++)
            front[i] += dp[j][i];
    }
    ll ans = 0;
    for (int i = 0; i < str.size() - 1; i++)
    {
        ans += front[i] * back[i + 1];
    }
    cout << ans << endl;
    return 0;
}
