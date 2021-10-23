#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    vector<ll> dp(str.size());
    fill(dp.begin(), dp.end(), 0);
    if ((str[0] - '0') % 4 == 0)
        dp[0] = 1;
    for (int i = 1; i < str.size(); i++)
    {
        ll tmp = dp[i - 1];
        ll n1  = str[i] - '0';
        ll n2  = (str[i - 1] - '0') * 10 + n1;
        if (n1 % 4 == 0)
            tmp++;
        if (n2 % 4 == 0)
            tmp += i;
        dp[i] = tmp;
    }
    cout << dp[str.size() - 1];
    system("pause");
    return 0;
}
