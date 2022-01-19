#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
constexpr ll inf = LONG_LONG_MAX / 2;
 
int main()
{
    ll n   = 0;
    ll l   = 0;
    ll ans = inf, tmp = 0;
    cin >> n >> l;
    vector<ll> cost(n);
    for (auto& c : cost)
        cin >> c;
    for (int i = 0; i < n - 1; i++)
    {
        if (cost[i] * 2 < cost[i + 1])
            cost[i + 1] = 2 * cost[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ll num = ll(ceil(l / pow(2, i)));
        ans = min(ans, num * cost[i] + tmp);
        tmp += ll(l / pow(2, i)) * cost[i];
        l -= ll(l / pow(2, i)) * pow(2, i);
    }
    ans = min(ans, tmp);
    cout << ans << endl;
    return 0;
}
