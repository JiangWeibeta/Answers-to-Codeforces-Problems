#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    int n = 0;
    cin >> n;
    vector<ll> a(n + 1, 0);
    vector<ll> b(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
        cin >> a[i];
    for (int i = 1; i < n + 1; i++)
        cin >> b[i];
    vector<ll> front(n + 2, 0);
    vector<ll> back(n + 2, 0);
    ll        sum = 0;
    ll         ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (a[i] * b[i]);
        front[i] = sum;
    }
    sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += (a[i] * b[i]);
        back[i] = sum;
    }
    ans = back[1];
    for (int i = 1; i < n; i++)
    {
        sum = a[i] * b[i + 1] + a[i + 1] * b[i];
        for (int k = 0; i - k >= 1 && i + k + 1 <= n; k++)
        {
            if (k)
                sum += (a[i - k] * b[i + k + 1] + a[i + k + 1] * b[i - k]);
            ans = max(ans, sum + front[i - k - 1] + back[i + k + 2]);
        }
    }
    for (int i = 2; i < n; i++)
    {
        sum = a[i] * b[i];
        for (int k = 1; i - k >= 1 && i + k <= n; k++)
        {
            sum += (a[i - k] * b[i + k] + a[i + k] * b[i - k]);
            ans = max(ans, sum + front[i - k - 1] + back[i + k + 1]);
        }
    }
    cout << ans;
    return 0;
}
