#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int                    sum   = 0;
    int                    k_sum = 0;
    vector<pair<int, int>> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i].first;
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i].second;
        if (vc[i].second == 1)
            sum += vc[i].first;
    }
    vector<int> dp(n);
    fill(dp.begin(), dp.end(), 0);
    for (int i = 0; i < k; i++)
    {
        if (vc[i].second == 0)
            dp[k - 1] += vc[i].first;
    }
    k_sum = dp[k - 1];
    for (int i = k; i < n; i++)
    {
        dp[i] += dp[i - 1];
        if (vc[i].second == 0)
            dp[i] += vc[i].first;
        if (vc[i - k].second == 0)
            dp[i] -= vc[i - k].first;
        if (dp[i] > k_sum)
            k_sum = dp[i];
    }
    cout << k_sum + sum << endl;
    system("pause");
    return 0;
}
