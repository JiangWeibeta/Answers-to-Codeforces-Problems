#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        vector<ll> c(n), a(n), b(n);
        for (auto& i : c)
            cin >> i;
        for (auto& i : a)
            cin >> i;
        for (auto& i : b)
            cin >> i;
        vector<ll> dp(n, 0);
        ll         ans = 0;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] == b[i] || i == 1)
                dp[i] = 1 + c[i] + abs(b[i] - a[i]);
            else
            {
                dp[i] = max(abs(b[i] - a[i]) + 2 + (c[i] - 1),
                            dp[i - 1] - abs(b[i] - a[i]) + 2 + (c[i] - 1));
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
