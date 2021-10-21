#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll solve(vector<ll>& diff, ll n)
{
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (diff[i] > 0)
            ans += diff[i];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 0;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n = 0, q = 0;
        cin >> n >> q;
        vector<ll> vc(n + 1);
        vector<ll> diff(n + 1);
        diff[0] = 0;
        for (ll j = 1; j <= n; j++)
            cin >> vc[j];
        vc.push_back(0);
        for (ll j = 1; j <= n; j++)
            diff[j] = vc[j] - vc[j + 1];
        ll ans = solve(diff, n);
        cout << ans << endl;
        for (ll j = 0; j < q; j++)
        {
            ll a = 0, b = 0;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            swap(vc[a], vc[b]);
            if (diff[a] > 0)
                ans -= diff[a];
            if (diff[b] > 0)
                ans -= diff[b];
            if (diff[a - 1] > 0 && a > 1)
                ans -= diff[a - 1];
            if (diff[b - 1] > 0 && b > 1 && b != a + 1)
                ans -= diff[b - 1];
            diff[a]     = vc[a] - vc[a + 1];
            diff[a - 1] = vc[a - 1] - vc[a];
            diff[b]     = vc[b] - vc[b + 1];
            diff[b - 1] = vc[b - 1] - vc[b];
            if (diff[a] > 0)
                ans += diff[a];
            if (diff[b] > 0)
                ans += diff[b];
            if (diff[a - 1] > 0 && a > 1)
                ans += diff[a - 1];
            if (diff[b - 1] > 0 && b > 1 && b - 1 != a)
                ans += diff[b - 1];
            cout << ans << endl;
        }
    }
    system("pause");
    return 0;
}
