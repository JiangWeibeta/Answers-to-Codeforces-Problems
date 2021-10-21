#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    ll n = 0;
    cin >> n;
    vector<ll> vc(n + 1);
    vector<ll> sum(n + 1);
    sum[0] = 0;
    vc[0] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> vc[i];
        sum[i] = vc[i] + sum[i - 1];
    }
    ll m = 0;
    cin >> m;
    sort(vc.begin(), vc.end());
    vector<ll> sorted_sum(n + 1);
    sorted_sum[0] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        sorted_sum[i] = sorted_sum[i - 1] + vc[i];
    }
    for (ll i = 0; i < m; i++)
    {
        ll type = 0, l = 0, r = 0;
        cin >> type >> l >> r;
        if (type == 1)
        {
            cout << sum[r] - sum[l - 1] << endl;
        }
        else
        {
            cout << sorted_sum[r] - sorted_sum[l - 1] << endl;
        }
    }
    system("pause");
    return 0;
}
